/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200315\L.cpp
 * Date: 2020-03-15 14:10:41
 * LastEditTime: 2020-03-15 17:37:36
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=100005;

struct edge{
    int to,next;
}e[10000007];
int len=1;
int head[MAXN]={0};
void add(int u, int v){
    e[len].to=v;
    e[len].next=head[u];
    head[u]=len++;
}
int dis[MAXN]={0};
struct position{
    int x,y;
}pos[MAXN];
bool cmp(position a, position b){
    return a.x<b.x;
}

bool vis[MAXN]={0};
queue<int>Q;
void bfs(){
    int u,v;
    while(!Q.empty()){
        u=Q.front();Q.pop();
        for(int i=head[u]; i>0; i=e[i].next){
            v=e[i].to;
            if(dis[v]<dis[u]+1){
                dis[v]=dis[u]+1;
                //cout<<v<<"="<<dis[v]<<"\n";
                if(!vis[v]){
                    vis[v]=true;
                    Q.push(v);
                    vis[v]=false;
                }
                
            }
        }
    }
    
}

int main(){
	int n,l;
    cin>>n>>l;
    
    for(int i=1; i<=n; i++){
        scanf("%d%d",&pos[i].x, &pos[i].y);
    }
    pos[0].x=0;pos[0].y=0;
    pos[n+1].x=l;pos[n+1].y=0;
    sort(pos+1, pos+n+1,cmp);

    for(int i=0; i<=n; i++){//建边
        for(int j=i+1; j<=n+1; j++){
            if(pos[j].x-pos[i].x>5)break;
            if(abs(pos[i].x-pos[j].x) + abs(pos[i].y-pos[j].y)<=5 && pos[i].x<pos[j].x){
                add(i,j);
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    vis[0]=true;
	memset(dis, 0, sizeof(dis));
    Q.push(0);
    bfs();

    cout<<dis[n+1]-1;
	return 0;
}
