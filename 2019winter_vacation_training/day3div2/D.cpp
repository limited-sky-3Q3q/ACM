/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\D.cpp
 * Date: 2020-02-15 14:13:37
 * LastEditTime: 2020-02-15 14:58:13
 * ! 今日运势: 吉，无bug
 * 最小生成树
**/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
#include<vector>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
void bf(const int now);
struct edge{
    int u,v,w;
}e[100];

int n,u,v,w,cnt,dis[10],ans,pos,m;
int main(){
	while(scanf("%d", &n) != EOF){
        if(!n){
            return 0;
        }
        //init
        m=0;cnt=0;
        //read
        for(int i=0; i<n; i++){
            scanf("%d%d%d", &u, &v, &w);
            e[cnt++]=(edge){u, v, w};
            e[cnt++]=(edge){v, u, w};
            if(m<u)m=u;
            if(m<v)m=v;
        }
        //init
        ans=INF;pos=1;
        //solve
        for(int i=0; i<=m; i++){
            bf(i);
        }
        printf("%d %d\n", pos,ans);
    }
	return 0;
}

void bf(const int now){
    //init
    for(int i=0; i<10; i++){
        dis[i]=INF;
    }dis[now]=0;
    int temp_ans=0;
    
    //solve
    for(int i=0; i<2*n-1; i++){
        for(int j=0; j<cnt; j++){
            u=e[j].u;v=e[j].v;w=e[j].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
            }
        }
    }
    for(int i=0; i<=m; i++){
        temp_ans += dis[i];
    }
    if(ans > temp_ans){
        ans=temp_ans;
        pos=now;
    }
    return;
}