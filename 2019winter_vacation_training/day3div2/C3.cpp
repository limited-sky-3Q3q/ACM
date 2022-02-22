/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\C3.cpp
 * Date: 2020-02-14 20:55:49
 * LastEditTime: 2020-02-14 22:44:09
 * ! 今日运势: 吉，无bug
 * 进入正题！
 * https://www.luogu.com.cn/problem/P4878
**/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<stdio.h>
#include<string>
#include<memory.h>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int N = 2e4+1003;
const int INF = 0x3f3f3f3f;

struct edge{
    int v,w;
};

vector<edge>e[N];
queue<int>Q;
bool vis[1003]={0};
int n,l,d,u,v,w,A,B,D,in[1003]={0};
ll dis[1003];
int main(){
    //read
    
	scanf("%d%d%d", &n, &l, &d);
    for(int i=0; i<l; i++){
        scanf("%d%d%d", &A, &B, &D);
        e[A].push_back({B,D});
    }
    for(int i=0; i<d; i++){
        scanf("%d%d%d", &A, &B, &D);
        e[B].push_back({A, -D});
    }
    //init1
    
    for(int i=1; i<n; i++){
        e[i+1].push_back({i, 0});
        e[0].push_back({i, 0});
    }
    //memset(dis, INF, sizeof(dis));
    for(int i=0; i<sizeof(dis)/sizeof(ll);i++){
        dis[i]=INF;
    }
    dis[0]=0;
    in[0]=1;
    Q.push(0);
    //solve1
    while(!Q.empty()){
        u=Q.front();Q.pop();
        vis[u]=false;
        for(int i=e[u].size()-1; i>=0; i--){
            v=e[u][i].v;
            w=e[u][i].w;
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                if(!vis[v]){
                    vis[v]=true;
                    in[v]++;
                    Q.push(v);
                    if(in[v]>n+1){//出现负环
                        printf("-1");
                        return 0;
                    }
                    
                }
            }   
        }
    }
    //init2
    //memset(dis, INF, sizeof(dis));
    for(int i=0; i<sizeof(dis)/sizeof(ll);i++){
        dis[i]=INF;
    }
    dis[1]=0;
    //memset(vis, false, sizeof(vis));
    for(int i=0; i<sizeof(vis)/sizeof(bool);i++){
        vis[i]=false;
    }
    vis[1]=true;
    Q.push(1);
    //solve
    while(!Q.empty()){
        u=Q.front();Q.pop();
        vis[u]=false;
        for(int i=e[u].size()-1; i>=0; i--){
            v=e[u][i].v;
            w=e[u][i].w;
            //需要求最小值？？//TODO 虽然说是求1和n的最远距离（即最大值），但这些不等式是限制，不是路径
            //看来我理解还是有问题
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                if(!vis[v]){
                    vis[v]=true;
                    Q.push(v); 
                    //!若是后面的奶牛不合法就不会判断，本该是-1的答案会输出-2
                    /*
                    if(in[v]>n+1){//出现负环
                        printf("-1");
                        return 0;
                    }
                    */
                }
            }   
        }
    }
    if(dis[n] >= INF){
        printf("-2");
        return 0;
    }
    printf("%lld", dis[n]);
	return 0;
}