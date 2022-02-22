/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\H.cpp
 * Date: 2020-02-17 16:59:08
 * LastEditTime: 2020-02-18 16:53:25
 * ! 今日运势: 吉，无bug
 * *双边权单源点最短路径，注意cost的用法
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
const int N=10004;
const int M=20004;
const int INF=0x3f3f3f3f;
void SPFA();
struct edge{
    int v,w,c;
};
vector<edge>e[N];

int n,m,u,v,w,c,dis[N],cost[N];//cost代表连接的消耗
bool vis[N];
queue<int>Q;
int main(){
	while(cin>>n>>m){
        if(n==0)break;
        //init
        for(int i=0; i<N; i++){
            e[i].clear();
        }
        //read
        for(int i=1; i<=m; i++){
            cin>>u>>v>>w>>c;
            e[u].push_back({v,w,c});
            e[v].push_back({u,w,c});
        }
        

        //solve
        SPFA();
        int ans=0;
        for(int i=1; i<=n; i++){
            ans+=cost[i];
        }
        cout<<ans<<"\n";
    }
	return 0;
}

void SPFA(){
    //init
    memset(cost, INF, sizeof(cost));
    cost[1]=0;
    memset(dis, INF, sizeof(dis));
    dis[1]=0;
    memset(vis, false, sizeof(vis));
    while(!Q.empty())Q.pop();
    Q.push(1);vis[1]=true;
    //solve
    while(!Q.empty()){
        u=Q.front();
        Q.pop();vis[u]=false;
        for(int i=e[u].size()-1; i>=0; i--){
            v=e[u][i].v;
            w=e[u][i].w;
            c=e[u][i].c;
            if(dis[v]>=dis[u]+w){
                //TODO 注意cost的用法
                if(dis[v]==dis[u]+w){//距离相同，cost=最小值
                    cost[v]=min(cost[v], c);
                }
                else{//距离更短，直接更新cost
                    dis[v]=dis[u]+w;
                    cost[v]=c;
                }
                if(!vis[v]){
                    Q.push(v);
                    vis[v]=true;
                }
            }
           
        }
    }
}