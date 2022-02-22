/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\M.cpp
 * Date: 2020-02-19 20:05:37
 * LastEditTime: 2020-02-19 20:15:03
 * ! 今日运势: 吉，无bug
 * 最小生成树
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
const int M=10004;
const int N=2003;
struct edge{
    int from,to;
    ll w;
}e[M];
bool cmp(const edge a, const edge b){
    return a.w<b.w;
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
    sort(e,e+m,cmp);
    for(int i=1; i<=n; i++){
        fa[i]=i;
    }
    ll fx,fy,cnt=1,ans=0;
    for(int i=0; i<m; i++){
        fx=find(e[i].from);
        fy=find(e[i].to);
        if(fx!=fy){
            fa[fx]=fy;
            cnt++;
            ans= max(ans, e[i].w);
            if(cnt==n){
                cout<<ans;
                return 0;
            }
        }
    }
    cout<<ans;
	return 0;
}
