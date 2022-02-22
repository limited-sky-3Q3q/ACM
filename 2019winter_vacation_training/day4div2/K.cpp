/**
 * TODO Auther: by SR
 * Date: 2020-01-30 13:27:45
 * LastEditTime: 2020-02-01 16:14:31
 * ! 今日运势: 吉，无bug
 * 数位DP
 * *数学弱鸡的我觉得这道题的解法抽象极了
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
using std::cin;
using std::cout;
typedef long long ll;
#define MOD 2520//!1~9的LCM为2520
#define MAXN 30
//ans[a(当前位数)][b(除以MOD后的余数)][c(2520的因数所对应的哈希值)]
//记录着a下，余数为b，能够被映射到c的因数整除的数的数量//超级拗口~
ll ans[MAXN][MOD][50];//最后一维是MOD的48个因数

int hash[MOD + 1] = { 0 };//记录1~9的最小公倍数，即2520的因数所对应的哈希值
void init();

int bit[MAXN];//记录数的每一位
ll solve(ll);
ll dfs(int, int, int, bool);

int gcd(int, int);
int LCM(int, int);

ll l,r;
int main(){

    init();
    /*
    int counter = 0;
    for(int i = 0; i <= MOD; i++){
        if(hash[i]){
            cout << hash[i] <<":"<<i<<"  ";
            if(++counter % 10 == 0){
                cout << "\n" ;
            }
        }
        
    }*/
    
    
    memset(ans, -1, sizeof(ans));//初始化ans

	int T;
    cin >> T;
    while(T--){
        cin >> l >> r;
        cout << solve(r) - solve(l-1)<<"\n";
    }
	return 0;
}

int gcd(int a, int b){//最大公约数，辗转相除法，很常用
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

int LCM(int a, int b){//最小公倍数，直接套用公式
    return a * b / gcd(a, b);
}

void init(){//TODO 找出MOD的因数，1~2520里有48个因数
    int num = 0;
    for(int i = 1; i <= MOD; i++){//没有优化，可以优化到i <= MOD^0.5
        if(MOD % i == 0){
            hash[i] = ++num;
        }
    }
    /**
        1:1  2:2  3:3  4:4  5:5  6:6  7:7  8:8  9:9  10:10
        11:12  12:14  13:15  14:18  15:20  16:21  17:24  18:28  19:30  20:35
        21:36  22:40  23:42  24:45  25:56  26:60  27:63  28:70  29:72  30:84
        31:90  32:105  33:120  34:126  35:140  36:168  37:180  38:210  39:252  40:280
        41:315  42:360  43:420  44:504  45:630  46:840  47:1260  48:2520
    **/
    return;
}

ll solve(ll now){
    int len = 0;//记录位数
    while(now){//将当前的数now存入bit数组中,位数为len
        bit[++len] = now % 10;//?逆序存放 1~len
        now /= 10;
    }
    return dfs(len, 0, 1, true);//用到了bit数组和长度len
}
//! 核心代码
ll dfs(int len, int preSum, int preLcm, bool flag){//深度优先搜索//?最先return的是now本身是否是美丽数
    //TODO 除了刚开始的solve调用def之外，其它的调用里只有 i == bit[len] 时才有flag == true
    //TODO 所以flag的作用是标记当前调用时，是否是当前数位的数的最后一位
    //TODO 可以说，当 0 <= i <= bit[len] - 1 时， dfs的结果是相同的， 只有 i == bit[len] 时才需要特殊处理
    if(len == 0){//判断到末尾，返回当前剩下的总数能不能被当前的最小公倍数整除
        return preSum % preLcm == 0;//可以就加1，不可以就没有变化
    }//def(0, , , )  == 0或1
    if(!flag && ans[len][preSum][hash[preLcm]] != -1){
        //条件成立时说明ans[len][preSum][hash[preLcm]]已经求出
        //且所求的不是当前位的数的最大的数
        return ans[len][preSum][hash[preLcm]];
    }
    //上方条件不成立时就求出ans[len][preSum][hash[preLcm]]再return该值
    ll answer = 0;
    int end = (flag ? bit[len]:9);//求上界，//?只有计算当前位的数的最大的数时才 end = bit[len]
    for(int i = 0; i <= end; i++){// 0 <= end <= 9
    //在sum >= MOD 之前，一直是累加，说明至少会从前四位后才
        int nowSum = (preSum*10 + i) % MOD;//更新当前的总数
        int nowLcm = preLcm;//更新当前的最大公倍数，只增不减
        if(i){
            nowLcm = LCM(nowLcm, i);
        }
        //i == end说明递归到最后一次
        answer += dfs(len-1, nowSum, nowLcm, flag && i == end);//递归到len == 0为止或
    }
    
    if(!flag){//若flag == true，说明answer没有完全算出ans[len][preSum][hash[preLcm]]
        ans[len][preSum][hash[preLcm]] = answer;
    }
    return answer;//!不能return ans[len][preSum][hash[preLcm]]！！！
}