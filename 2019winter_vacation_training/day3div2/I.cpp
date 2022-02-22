/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\I.cpp
 * Date: 2020-02-19 13:02:29
 * LastEditTime: 2020-02-19 13:46:36
 * ! 今日运势: 吉，无bug
 * 先用floryd处理距离，再用dp来求解
**/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
void floryd();
const int N=202;
const ll INF=0x1f1f1f1f1f1f1f1f;
ll a = INF+INF;
ll n,m,u,v,w,s_dis[N][N],l_dis[N][N],cost[1003][N],to[1003],R;
char ch;
int main(){
	while(scanf("%lld%lld",&n,&m)&&n+m){
        //init
        memset(l_dis, INF, sizeof(l_dis));
        memset(s_dis, INF, sizeof(s_dis));
        memset(cost, INF, sizeof(cost));
        //read
        for(int i=1; i<=m; i++){
            scanf("%lld%lld%lld", &u,&v,&w);
            getchar();
            ch=getchar();
            if(ch=='S'){
                s_dis[u][v]=s_dis[v][u]=min(s_dis[v][u], w);
            }
            else{
                l_dis[u][v]=l_dis[v][u]=min(l_dis[v][u], w);
            }
        }
        scanf("%lld", &R);
        for(int i=1; i<=R; i++){
            scanf("%lld", &to[i]);
        }
        //init
        floryd();
        for(int i=0; i<=n; i++){
            s_dis[i][i]=l_dis[i][i]=0;
        }
        cost[1][to[1]]=0;
        //solve
        for(int i=2; i<=R; i++){
            for(int j=1; j<=n; j++){
                for(int k=1; k<=n; k++){
                    if(j!=k){//走海路
                        cost[i][j]=min(cost[i][j], cost[i-1][k]+l_dis[to[i-1]][k]+s_dis[k][j]+l_dis[j][to[i]]);
                    }
                    else{//走陆路
                        cost[i][j]=min(cost[i][j], cost[i-1][k]+l_dis[to[i-1]][to[i]]);
                    }
                    
                }
            }
        }
        //output
        ll ans=INF;
        for(int i=1; i<=n; i++){
            ans=min(ans, cost[R][i]);
        }
        printf("%lld\n", ans);
    }
	return 0;
}

void floryd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                s_dis[i][j]=min(s_dis[i][j], s_dis[i][k]+s_dis[k][j]);
                l_dis[i][j]=min(l_dis[i][j], l_dis[i][k]+l_dis[k][j]);
            }
        }
    }
    return;
}