/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\temp\H.cpp
 * Date: 2020-03-01 17:07:09
 * LastEditTime: 2020-03-01 17:29:22
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
int a[10000][10000]={0};
struct pos{
    int x,y;
};
int n,m;
queue<pos>Q;
void bfs(int x,int y,int now){
    pos temp;
    while(!Q.empty()){
        if(x==n && y==m){
        
        return;
        }
        temp=Q.front();
        Q.pop();
        if(a[x+1][y+1]==0){
            Q.push({x+1,y+1});
            a[x+1][y+1]=a[x][y]+1;
        }
        if(a[x-1][y+1]==0){
            Q.push({x-1,y+1});
            a[x-1][y+1]=a[x][y]+1;
        }
        if(a[x+1][y-1]==0){
            Q.push({x+1,y-1});
            a[x+1][y-1]=a[x][y]+1;
        }
        if(a[x-1][y-1]==0){
            Q.push({x-1,y-1});
            a[x-1][y-1]=a[x][y]+1;
        }
    }
}
int k;
void init(int x, int y){
    int b=x-k,c=y-k;
    for(int i=1; i<=k; i++){
        
    }
}

int main(){
    memset(a,-1,sizeof(a));
	cin>>n>>m>>k;
    char ch;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%c",&ch);
            if(ch=='.'){
                a[i][j]=0;
            }
            else if(ch=='M'){
                a[i][j]=-1;
                init(i,j);
            }
            else if(ch=='S'){
                a[i][j]=1;
            }
            else{
                a[i][j]=0;
            }
        }
    }
    
    bfs(1,1,1);
    if(a[n][m]==0){
        cout<<-1;
    }
    else{
        cout<<a[n][m];
    }
	return 0;
}
