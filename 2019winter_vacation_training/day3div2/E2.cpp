/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\E.cpp
 * Date: 2020-02-15 15:08:55
 * LastEditTime: 2020-02-15 17:08:11
 * ! 今日运势: 吉，无bug
 * 用矩阵写的最短路
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
const int INF = 0x3f3f3f3f;
void SPFA(const int now);
struct edge{
    int u,v,w=1;
    inline bool operator < (edge a){
        return w < a.w;
    }
}e[10004];
int n,m,t,temp,work[302],cnt;
bool have[302][302];
bool vis[302];

queue<int>Q;
int main(){

    //read
	scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++){
        scanf("%d", &t);
        for(int j=0; j<t; j++){
            scanf("%d", &work[j]);
            for(int k=0; k<j; k++){//建边
                e[cnt].u = work[j];
                e[cnt].v = work[k];
            }
        }
    }
    //init
    /*
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<e[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    //solve
    
    int ans=INF,temp_ans=0;
    for(int i=1; i<=n; i++){
        temp_ans=0;
        for(int j=1; j<=n; j++){
            temp_ans += e[i][j];
        }
        temp_ans *= 100;
        temp_ans /= n-1;
        ans=min(ans, temp_ans);
    }
    //output
    cout<<ans;
	return 0;
}
