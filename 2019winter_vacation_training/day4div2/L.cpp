/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day4div2\L.cpp
 * Date: 2020-02-04 19:42:44
 * LastEditTime: 2020-02-24 17:33:41
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

bool meet[20][20];
ll dp[(1<<17)+10], sum[20];
int main(){
	int T,n,m,a,b,ALL,cas=1;
    ll ans;
    sum[1]=1;
    for(int i=2; i<=18; i++){
        sum[i]=sum[i-1]*i;
    }
    cin>>T;
    while(T--){
        memset(meet, false, sizeof(meet));
        memset(dp, 0, sizeof(dp));
        dp[0]=1;
        cin>>n>>m;
        ALL = (1<<n)-1;
        for(int i=1; i<=m; i++){
            cin>>a>>b;
            meet[a][b]=true;
        }
        for(int i=1; i<=n; i++){
            for(int j=ALL; j>=0; j--){
                for(int k=1; k<=n; k++){
                    if(1<<(k-1)&j){
                        continue;
                    }
                    if(meet[i][k]){
                        continue;
                    }
                    dp[1<<(k-1)|j]+=dp[j];
                }
                dp[j]=0;//TODO ？？？？
            }
        }
        ans=0;
        for(int i=0; i<=ALL; i++){
            ans+=dp[i];
        }
        printf("Case %d: %lld\n",cas++,sum[n]-ans);
    }
	return 0;
}
