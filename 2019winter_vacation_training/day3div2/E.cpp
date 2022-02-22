/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\E.cpp
 * Date: 2020-02-15 15:08:55
 * LastEditTime: 2020-02-15 17:23:55
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
int e[302][302];
int n,m,t,temp;
bool vis[302];

vector<int>work;
queue<int>Q;
int main(){
    //init
    for(int i=0; i<=300; i++){
        for(int j=0; j<=300; j++){
            e[i][j]= (i==j? 0:INF);
        }
    }
    //read
	scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++){
        scanf("%d", &t);
        work.clear();
        for(int j=1; j<=t; j++){
            scanf("%d", &temp);
            work.push_back(temp);
            for(int k=0; k<j-1; k++){//建边
                e[temp][work[k]]=1;
                e[work[k]][temp]=1;
                
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
    for(int i=1; i<=n; i++){
        SPFA(i);
    }
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

void SPFA(const int now){
    cout<<"now == "<<now<<"\n";
    //init
    for(int i=1; i<=n; i++){
        vis[i]=false;
    }vis[now]=true;
    //TODO e[now][i]初始化为INF
    //TODO 第now行被初始化了，但对应的值还存在对应的列里，因为e是对称矩阵
    for(int i=1; i<=n; i++){
        e[now][i]=INF;
    }e[now][now]=0;

    while(!Q.empty())Q.pop();
    Q.push(now);
    int u,w;
    //solve
    while(!Q.empty()){
        u=Q.front();
        Q.pop();
        for(int v=1; v<=n; v++){
            if(e[now][v]>e[now][u] + e[v][u]){//*防止权值用第now行的，把v和u反过来
                e[now][v]=e[now][u]+e[v][u];
                Q.push(v);
                
                cout<<"push:"<<v<<"\n";
                for(int i=1; i<=n; i++){
                    for(int j=1; j<=n; j++){
                        if(e[i][j]==INF){
                            cout<<"X ";
                        }
                        else
                        cout<<e[i][j]<<" ";
                    }
                    cout<<"\n";
                }

            }
        }
    }
}