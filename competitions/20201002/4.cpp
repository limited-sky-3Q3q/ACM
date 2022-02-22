/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20201002\4.cpp
 * Date: 2020-10-05 21:05:59
 * LastEditTime: 2020-10-05 21:50:35
 * !今日运势: 吉，无bug
************************************************/
/************************************************
考虑移除的叶子节点必定属于最大的子树
因此令Fu表示连向u的最大的子树大小，则判定条件为Fu - k <= (n-k)/2
注意Fu需要考虑向上的部分
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

int len, head[MAXN], dp[MAXN], vis[MAXN], ans;
int t,n,k,a,b;
struct edge{
    ll v,next;
}e[2*MAXN];

void add(ll u, ll v){
    e[len].v=v;
    e[len].next=head[u];
    head[u]=len++;
}

void dfs(int node){

    //bool flag = true;
    int longest=-1;
    for(int i=head[node]; i>0; i = e[i].next){
        int v = e[i].v;
        if(vis[v])
            continue;
        else{
            vis[v] = 1;
            dfs(v);
            dp[node] += dp[v];
            longest = max(dp[v], longest);
        }
    }
    
    longest = max(longest, n-dp[node]);

    if(2*(longest-k) <= n-k)//!!!
        ans++;
    return;
}

int main(){
    cin>>t;
    for(int j=1; j<=t; j++){

        //init
        //memset(e, 0, sizeof e);
        memset(dp, 0, sizeof dp);
        memset(vis, 0, sizeof vis);
        memset(head, 0, sizeof head);
        for(int i=0; i<MAXN; i++)
            dp[i] = 1;
        len=1;
        ans=0;


        cin>>n>>k;
        for(int i=0; i<n-1; i++){
            cin>>a>>b;
            add(a,b);
            add(b,a);
        }
        
        vis[1] = 1;
        dfs(1);
        
        printf("Case #%d: %d\n", j, ans);
    }
	return 0;
}
