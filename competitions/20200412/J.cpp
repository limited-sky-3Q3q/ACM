/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200412\J.cpp
 * Date: 2020-04-12 15:27:10
 * LastEditTime: 2020-04-12 17:13:20
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
struct edge{
    vector<int>to;
}e[2][100005];
int dis[2][100005]={0};
bool flag=false;
bool vis[100005];
int degree[2][100005]={0};
void bfs(int now, int from){
    int d=0;
    if(e[now][from].to.size()==1){//末端节点
        dis[now][from]=d;
        degree[now][d]++;
        return;
    }
    queue<int>Q;
    Q.push(from);vis[from]=true;
    while(!Q.empty()){
        d++;
        int u=Q.front(); Q.pop();

        for(int i=(e[now][u].to.size()-1); i>=0; i--){
            int v=e[now][u].to[i];
            if(dis[now][v] != INF){
                //dis[now][u]=min(dis[now][u], dis[now][v]+1);
                dis[now][from]=min(dis[now][v]+d, dis[now][from]);
                vis[v]=true;
            }
            else if(e[now][v].to.size()==1){
                dis[now][from]=min(d, dis[now][from]);
                degree[now][dis[now][from]]++;
                return;
            }
            else if(!vis[v]){
                vis[v]=true;
                Q.push(v);
            }
        }
    }

    degree[now][dis[now][from]]++;
    //dis[now][from]=INF;
}

int main(){
	int u,v,n,m;
    cin>>n;
    for(int i=0; i<n-1; i++){
        scanf("%d%d", &u, &v);
        e[0][u].to.push_back(v);
        e[0][v].to.push_back(u);
    }
    cin>>m;
    for(int i=0; i<m-1; i++){
        scanf("%d%d", &u, &v);
        e[1][u].to.push_back(v);
        e[1][v].to.push_back(u);
    }

    memset(dis, INF, sizeof dis);

    for(int i=1; i<=n; i++){
        memset(vis, 0, sizeof vis);
        flag=false;
        bfs(0,i);
        if(dis[0][i]==-1){
            break;
        }
    }
    for(int i=1; i<=m; i++){
        memset(vis, 0, sizeof vis);
        flag=false;
        bfs(1,i);
        if(dis[1][i]==-1){
            break;
        }
    }

    long double ans=0,temp=0;
    for(ll i=0; i<n; i++){
        if(degree[0][i]==0)continue;
        temp += i*degree[0][i];
    }
    ans = temp/n;
    temp=0;
    for(ll j=0; j<m; j++){
        if(degree[1][j]==0)continue;
        temp += j*degree[1][j];
    }
    ans = ans*temp/m;
    //ans /= (long double)(n)*(long double)(m);
    cout<<fixed<<setprecision(15);
    cout<<ans;
	return 0;
}
