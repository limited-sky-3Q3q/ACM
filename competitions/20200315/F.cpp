/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200315\F.cpp
 * Date: 2020-03-15 13:30:47
 * LastEditTime: 2020-03-15 13:54:37
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;

int fa[MAXN]={0};
int find(int a){
    return fa[a]==a?a:fa[a]=find(fa[a]);
}
int add(int a,int b){
    int fx=find(a);
    int fy=find(b);
    fa[fx]=fy;
}
int road[MAXN][2]={0};
int que[MAXN],sets[MAXN];
int main(){
	int n,m,x,y,num=0;
    scanf("%d%d",&n, &m);
    for(int i=1; i<=n; i++){
        fa[i]=i;
    }
    for(int i=1; i<=m; i++){
        scanf("%d%d",&road[i][0],&road[i][1]);
    }
    for(int i=1; i<=m; i++){
        scanf("%d",&que[i]);
    }
    for(int i=m; i>=1; i--){
        sets[i]=n-num;
        x=find(road[que[i]][0]);
        y=find(road[que[i]][1]);
        if(x!=y){
            num++;
            add(x,y);
        }
        
    }
    for(int i=1; i<=m; i++){
        printf("%d\n", sets[i]);
    }
	return 0;
}
