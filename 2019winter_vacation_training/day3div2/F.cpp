/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\F.cpp
 * Date: 2020-02-16 09:03:57
 * LastEditTime: 2020-02-16 12:14:28
 * ! 今日运势: 吉，无bug
**/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<string.h>
#include<queue>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 6000;
bool SPFA();
int len,head[MAXN];
struct edge{
    int v,w,next;
}e[MAXN];
void add(const int u, const int v, const int w){
    e[len].v=v;
    e[len].w=w;
    e[len].next=head[u];
    head[u]=len++;
}

int dis[502], in[502];
bool vis[502];

int n;
int main(){
	int T,u,v,w,a,b;
    scanf("%d",&T);
    while(T--){
        //init
        len=1;
        memset(head, 0, sizeof(head));
        
        //read
        scanf("%d%d%d", &n, &a, &b);
        for(int i=1; i<= a;i++){
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        for(int i=1; i<=b; i++){
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, -w);
        }
        //init
        for(int i=1; i<=n; i++){
            add(0, i, 0);
        }
        //solve
        if(SPFA()){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
	return 0;
}

bool SPFA(){
    //init
    memset(in, 0, sizeof(in));
    in[0]=1;
    memset(vis, false, sizeof(vis));
    vis[0]=true;
    memset(dis, INF, sizeof(dis));
    dis[0]=0;
    queue<int>Q;
    Q.push(0);
    int u,v,w;
    //solve
    while(!Q.empty()){
        u=Q.front();
        Q.pop();
        vis[u]=false;
        for(int i=head[u]; i>0; i=e[i].next){
            v=e[i].v;
            w=e[i].w;
            if(dis[v] > dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    vis[v]=true;
                    Q.push(v);
                    in[v]++;
                    if(in[v]>n+1){
                        return true;
                    }
                }
            }
            
        }
    }
    return false;
}