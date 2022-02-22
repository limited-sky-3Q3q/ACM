/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200329\C.cpp
 * Date: 2020-03-29 12:54:37
 * LastEditTime: 2020-03-29 14:38:26
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
int t;

ll ans[100005]={0};
ll h[100005]={0};
//int last[100005]={0};

int main(){
	int n;//fast=INF;
    ll sum=0;//应该不是这里的问题，不对，有可能出问题
    cin>>n>>t;
    for(int i=1; i<=n; i++){
        scanf("%lld", &h[i]);
       // last[i]=h[i];
    }

    for(int i=1; i<=n; i++){
        ans[i]=1;
    }
    //ans[0]=INF;
    
    for(int i=1; i<=n; i++){//依次计算ans
        sum+=h[i];//开始体检的时间
        
        h[i] = max(h[i], h[i-1]);//快就变慢，慢的不变
        ll l=1,r=1e9+10;
        while(l<=r){//二分
            ll m = (l+r)/2;
            if(sum + h[i]*(m-1)>t){//太大
                r=m-1;
                ans[i]=m;
            }
            else{
                l=m+1;
            }
        }
    }

    for(int i=1; i<=n; i++){
        printf("%lld\n", ans[i]);
    }
	return 0;
}
