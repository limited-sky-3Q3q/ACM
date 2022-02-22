/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\CF\643\C.cpp
 * Date: 2020-05-16 20:08:22
 * LastEditTime: 2020-05-24 12:06:09
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

ll calcProgression(ll a, ll d, ll n){
    return (2ll*a + d*(n-1))*n/2;
}
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans = 0;
    for(int z = c; z <= d; z++){
        int minX = max(a, z - c + 1);
        if(minX > b)
            continue;

        int mid = z - b + 1;
        int start = c - max(b, z - minX + 1) + 1;//最小的可以满足当前条件的X
        
        if(mid <= minX){//可完整取得y值
            ans += 1ll * (c - b + 1) * (b - minX + 1);
        }else if(mid > b){//不可能完整取得y值，等差数列
            ans += calcProgression(start, 1, b - minX + 1);
        }else{//两种情况都有
            ans += calcProgression(start, 1, mid - minX + 1);
            ans += 1ll * (c - b + 1) * (b - mid);
        }
        
    }
    cout<<ans;
    return 0;
}





//int que[4],ans;
//int main(){
    /*
    ans = 0;

    for(int i=0; i<4; i++)
        cin>>que[i];
    
   // ans = min(que[3], que[1] + que[2]) - max(que[0] + que[1] ,que[2]);
    
    int r = min(que[3], que[1] + que[2]);
    int l = min(que[2], que[0] + que[1]);

    if(que[3] >= que[0] + que[1]){
        ans = (r-l+1)*(l+r)/2;
    }
    else{
        ans = (que[3] - que[2] + 1)
    }
    
    
    cout<<ans;
    //cout<<ans;
	return 0;
    */


    //用公式做
    /*
    int A, B, C, D;
    cin>>A>>B>>C>>D;
    ll ans = 0;
    for(int z = C; z <= D; z++){//依次计算z = [C, D] 时的可能数量
        int minX = max(A, z - C + 1);//此时x的最小情况 x + C = z + 1
        if (minX > B)//不存在
            continue;
        

        //？？？？？？？？？？？？？？？？
        int mid = z - B + 1;//y 可以取 B 时 x 的最小值
        //                x 最小时 y 的大小
        int start = C - max(B, z - minX + 1) + 1;// x 的开始位置 x >= 1


        if (mid <= minX){//x,y 取任意值都满足条件
            ans += 1ll * (C - B + 1) * (B-minX +1);
        }else if(mid > B){//当 x = B 时 y 依然不能取 B ， 一个等差数列，公差为1
            ans += calcProgression(start, B - minX + 1);
        }else{//介于上方两种情况之间，分成两部分
            ans += calcProgression(start, mid - minX + 1);
            ans += 1ll*(B-mid)*(C-B+1);
        }
        cout<<ans<<"\n";
    }   
    
    return 0;
}
*/

//公式解法
/*
ll calcProgression(ll a, ll d, ll n) {
    return (2 * a + d * (n - 1)) * n / 2;
}

void run() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    ll ans = 0;
    for (int z = c; z <= d; ++z) {
        int minX = std::max(a, z - c + 1);
        if (minX > b) {
            continue;
        }

        int mid = z - b + 1;
        int start = c - std::max(b, z - minX + 1) + 1;

        if (mid <= minX) {
            ans += 1ll * (c - b + 1) * (b - minX + 1);
        } else if (mid > b) {
            // ans += 1ll * (b - minX + 1) * (b - minX + 2) / 2;
            ans += calcProgression(start, 1, b - minX + 1);
        } else {
            ans += calcProgression(start, 1, mid - minX + 1);
            ans += 1ll * (b - mid) * (c - b + 1);
            // ans += 1ll * (mid - minX + 1) * (mid - minX + 2) / 2 + 1ll * (b - mid) * (c - b + 1);
        }
    }    

    printf("%lld\n", ans);
}

int main(void) {
    run();
    return 0;
}
*/


/*
ll calcProgression(ll a, ll d, ll n) {
    return (2 * a + d * (n - 1)) * n / 2;
}

void run() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    ll ans = 0;
    for (int z = c; z <= d; ++z) {
        int minX = std::max(a, z - c + 1);
        if (minX > b) {
            continue;
        }

        int mid = z - b + 1;
        int start = c - std::max(b, z - minX + 1) + 1;

        if (mid <= minX) {
            ans += 1ll * (c - b + 1) * (b - minX + 1);
        } else if (mid > b) {
            // ans += 1ll * (b - minX + 1) * (b - minX + 2) / 2;
            ans += calcProgression(start, 1, b - minX + 1);
        } else {
            ans += calcProgression(start, 1, mid - minX + 1);
            ans += 1ll * (b - mid) * (c - b + 1);
            // ans += 1ll * (mid - minX + 1) * (mid - minX + 2) / 2 + 1ll * (b - mid) * (c - b + 1);
        }
    }    

    printf("%lld\n", ans);
}

int main() {
    run();
    return 0;
}
*/