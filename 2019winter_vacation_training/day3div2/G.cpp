/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\G.cpp
 * Date: 2020-02-17 11:46:27
 * LastEditTime: 2020-02-17 16:39:03
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int N=1003;
const int M=100005;
const int INF=0x3f3f3f3f;
void SPFA(const int now);
struct edge{
    int v,w;
};
vector<edge>e[2][M];
int dis[2][N];
bool vis[N];
int n,m,x,u,v,w;
int main(){
    //read
	cin>>n>>m>>x;
    for(int i=1; i<=m; i++){
        cin>>u>>v>>w;
        e[0][u].push_back({v, w});
        e[1][v].push_back({u, w});
    }
    //init
    memset(dis, INF, sizeof(dis));
    SPFA(0);SPFA(1);
    
    int ans = 0;

    //??????????????????这个地方写错了？？？
    for(int i=1; i<=n; i++){
        if(i==x)continue;
        ans=max(dis[0][i]+dis[1][i], ans);
        //ans=max(dis[0][i]+dis[1][i], dis[0][i+1]+dis[1][i+1]);
    }//sjb 这样写的话只是在最后两个里取最大值
    cout<<ans;
    
	return 0;
}

void SPFA(const int now){
    queue<int>Q;
    dis[now][x]=0;
    memset(vis, false, sizeof(vis));
    Q.push(x);vis[x]=true;
    
    while(!Q.empty()){
        u=Q.front();
        Q.pop();vis[u]=false;
        for(int i=0; i<e[now][u].size(); i++){
            v=e[now][u][i].v;
            w=e[now][u][i].w;
            if(dis[now][v]>dis[now][u]+w){
                dis[now][v]=dis[now][u]+w;
                if(!vis[v]){
                    vis[v]=true;
                    Q.push(v);
                }
            }
        }
    }
}