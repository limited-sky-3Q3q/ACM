/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day2div2\H.cpp
 * Date: 2020-02-10 15:15:35
 * LastEditTime: 2020-02-10 17:11:05
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
using namespace std;
typedef long long ll;
const int MAXN = 100000+5;

void read();void init();void solve();

ll que[MAXN];
int l[MAXN], r[MAXN];
bool used[MAXN];
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	while(cin>>n && n){
        read();
        init();
        solve();
    }
	return 0;
}

void read(){
    for(register int i=0;i<n;i++){
        cin>>que[i];
    }
    return;
}

void init(){
    memset(used,0,sizeof(used));
    l[0]=0;
    r[n-1]=n-1;
    for(register int i=1;i<n;i++){//l
        register int t=i;
        while(t>0&&que[t-1]>=que[i]){
            t=l[t-1];//注意t的赋值方式
        }
        l[i]=t;
    }
    for(register int i=n-1;i>=0;i--){//r
        register int t=i;
        while(t<n-1&&que[t+1]>=que[i]){//!注意t的范围，t开大了会TLE
            t=r[t+1];
        }
        r[i]=t;
    }
}

void solve(){
    ll ans=0;
    for(register int i=0;i<n;i++){
        ans=max(ans, que[i]*(r[i]-l[i]+1));
    }
    cout<<ans<<"\n";
}