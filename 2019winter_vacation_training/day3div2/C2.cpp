/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\C3.cpp
 * Date: 2020-02-14 16:13:31
 * LastEditTime: 2020-02-14 20:50:42
 * ! 今日运势: 吉，无bug
 * https://www.luogu.com.cn/problem/P5960
 * 差分约束模板题 分别用Bellman-Ford和SPFA做一遍
**/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 5e3+10;
const int MAXM = 5e3+10;
const int INF = 0x3f3f3f3f;

//*Bellman_Ford
/*
struct edge{
	int u,v,w;
}e[MAXM];

int ans[MAXN];
int main(){
	int u,v,w,n,m;
	//read
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%d%d%d", &e[i].v, &e[i].u, &e[i].w);
	}
	//init
	memset(ans, INF, sizeof(ans));
	ans[1]=0;
	
	for(int i=1; i<=n-1; i++){
		for(int j=0; j<m; j++){
			ans[e[j].v]=min(ans[e[j].v], ans[e[j].u]+e[j].w);
		}
	}
	for(int i=0; i<m; i++){
		if(ans[e[i].v] > ans[e[i].u]+e[i].w){
			printf("NO");
			return 0;
		}
	}
	for(int i=1; i<=n; i++){
		printf("%d ", ans[i]);
	}
	return 0;
}
————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*/
//!!!!A了A了！！！！！！！！！！！！！！突然就A了！！！！！！！！！！！！
//*SPFA
struct edge{
	int v,w;
};

vector<edge>e[MAXN];//e[u][i].v：u->v，权值为e[u][i].w
queue<int>Q;

int n,m,u,v,w,in[MAXN],dis[MAXN],vis[MAXN];
int main(){
	//read
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%d%d%d", &v, &u, &w);
		e[u].push_back({v, w});//有向权值
	}
	//init
	
	memset(in, 0, sizeof(in));
	in[0]=1;
	memset(dis, INF, sizeof(dis));//算最小值，初始化为INF
	dis[0]=0;//超级源点为0//*十分必要，绝对不能省略
	/*
	一个反例：3 3
			 1 2 -1
			 2 3 0
			 3 2 0
	有超级源点可以求出解，如果没有超级源点，把dis[1]=0的话，就会出现负环。
	*/
	memset(vis, false, sizeof(vis));
	vis[0]=true;
	for(int i=1; i<=n; i++){
		e[0].push_back({i, 0});
	}
	Q.push(0);
	//solve
	while(!Q.empty()){
		u=Q.front();
		Q.pop();
		vis[u]=false;//*用于判断负环，不可省略
		for(int i=e[u].size()-1; i>=0; i--){
			v=e[u][i].v;
			w=e[u][i].w;
			if(dis[v] > dis[u]+w){
				dis[v] = dis[u]+w;
				if(!vis[v]){
					vis[v] = true;
					in[v]++;
					Q.push(v);
					//printf("in%d\n",v);
					if(in[v]>n+1){
						printf("NO");
						return 0;
					}
					
				}
				
			}
		}
	}

	for(int i=1; i<=n; i++){
		printf("%d ", dis[i]);
	}
	return 0;
}