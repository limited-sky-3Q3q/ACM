/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\test.cpp
 * Date: 2020-02-11 10:35:00
 * LastEditTime: 2020-02-17 11:38:02
 * ! 今日运势: 吉，无bug
 * https://www.luogu.com.cn/problem/P3385
 * *本题是只判断能不能从   1   达到的负环
**/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<string>
#include<memory.h>
using namespace std;
typedef long long ll;
const int N = 2003;
const int M = 3003;
const int INF = 0x3f3f3f3f;
void DFS(const int now);

struct edge{
    int v,w,next;
}e[M*2];
int head[N], pos=1;
void add(const int u, const int v, const int w){
    e[pos].v=v;
    e[pos].w=w;
    e[pos].next=head[u];
    head[u]=pos++;
}

int n,m,dis[N];
bool vis[N],flag;
int main(){
	int T,u,v,w;
    scanf("%d", &T);
    while(T--){
        //init
        pos=1;
        memset(head, 0, sizeof(head));
        //read
        scanf("%d%d", &n, &m);
        for(int i=1; i<=m; i++){
            scanf("%d%d%d", &u, &v, &w);
            if(w<0){
                add(u,v,w);
            }
            else{
                add(u,v,w);
                add(v,u,w);
            }
        }
        //init
        /*
        for(int i=1; i<=n; i++){
            add(0, i, 0);
        }
        */
        memset(dis, INF, sizeof(dis));
        dis[1]=0;
        memset(vis, false, sizeof(vis));
        vis[1]=true;
        flag=false;
        //solve
        DFS(1);
        //output
        if(flag){
            printf("YE5\n");
        }
        else{
            printf("N0\n");
        }
    }
	return 0;
}

void DFS(const int now){
    if(flag)return;

    for(int i=head[now]; i>0; i=e[i].next){
        int v=e[i].v;
        int w=e[i].w;
        if(dis[v] > dis[now]+w){
            dis[v] = dis[now]+w;
            if(!vis[v]){
                vis[v]=true;
                DFS(v);
                vis[v]=false;
            }
            else{
                flag=true;
                return;
            }
        }
    }
    return;
}