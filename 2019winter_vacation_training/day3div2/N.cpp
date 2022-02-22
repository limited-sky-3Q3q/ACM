/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\N.cpp
 * Date: 2020-02-19 20:27:33
 * LastEditTime: 2020-02-20 11:09:42
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<vector>
using namespace std;
typedef long long ll;
const int N=5003;
const int R=200005;
const int INF=0x3f3f3f3f;
struct edge{
    int from,to,w;
}e[R];

vector<edge>ee[N];
int dis[N][N],ans[N];
int main(){
	int n,m,u,v,w,len=0;
    cin>>n>>m;
    memset(dis, INF, sizeof(dis));
    for(int i=1; i<=n; i++){
        dis[i][i]=0;
    }
    for(int i=1; i<=m; i++){
        cin>>u>>v>>w;
        dis[u][v]=dis[v][u]=min(dis[u][v],w);
        if(u==n){
            ee[v].push_back({v,u,w});
        }
        if(v==n){
            ee[u].push_back({u,v,w});
        }
    }
    
    int ans=0;
   
    cout<<ans;
	return 0;
}
