/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\K.cpp
 * Date: 2020-02-19 18:00:59
 * LastEditTime: 2020-03-15 13:35:36
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
const int N=1003;
const int M=20000;
struct edge{
    int from,to,w;
}e[M];
bool cmp(const edge a, const edge b){
    return a.w>b.w;
}
int fa[N];
int find(const int a){
    return fa[a]==a?a:fa[a]=find(fa[a]);
}

int main(){
	int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>e[i].from>>e[i].to>>e[i].w;
    }
    
    sort(e, e+m, cmp);
    for(int i=1; i<=n; i++){
        fa[i]=i;
    }

    int fx,fy,len=1,ans=0;
    for(int i=0; i<m; i++){
        fx=find(fa[e[i].from]);
        fy=find(fa[e[i].to]);
        if(fx != fy){
            fa[fx]=fy;
            len++;
            ans+=e[i].w;
            if(len==n){
                cout<<ans;
                return 0;
            }
        }
    }
    cout<<-1;
	return 0;
}
