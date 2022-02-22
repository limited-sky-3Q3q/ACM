/**
 * TODO Auther: by SR
 * Date: 2020-01-10 12:40:49
 * LastEditTime: 2020-02-02 15:42:55
 * ! 今日运势: 吉，无bug
 * *跳石子， o(NlogN)， 不是一个离散的有序序列。
 * TODO 一个结果只有0和1的序列(这里是1……10……0)也可看作一个有序序列，所以可以用二分搜索
 * ? 是一个离散的有序序列的话可以用lowb和upperb
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
using namespace std;
typedef long long ll;
const int MAXN = 50004;
ll d[MAXN];

ll binary_search(ll, ll);
bool check(ll);
ll L, n, m;

int main(){

    cin>>L>>n>>m;

    d[1] = 0;//边界初始化
    d[n+2] = L;

    for(register int i = 2; i <= n+1; i++){
        cin >> d[i];
    }
    
    cout << binary_search(1ll,L);
    
	return 0;
}

bool check(ll now){//判断now可不可以存在
    ll temp;
    int t = m, left = 1;
    for(register int i = 2; i <= n+2 && t+1; i++){
        if(d[i] - d[left] >= now){
            left = i;
            continue;
        }
        else{
            t--;
            continue;
        }
    }
    if(!( t+1 )){
        return false;
    }
    else{
        return true;
    }
    
}

ll binary_search(ll down, ll up = 1000000009ll){
    if(down + 1 == up){//搜索到最后一次
        if(check(up)){
            return up;
        }
        else{
            return down;
        }
    }
    
    ll mid = down + (up - down) >> 1;//用(up + down) >> 1 的话，溢出的风险更大，当然这里的话哪一种都不会有问题
    if(check(mid)){
        return binary_search(mid, up);
    }
    else{
        return binary_search(down, mid);
    }
}

