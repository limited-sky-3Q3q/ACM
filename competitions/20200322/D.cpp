/******************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200322\D.cpp
 * Date: 2020-03-22 16:58:25
 * LastEditTime: 2020-03-22 17:42:09
 * !今日运势: 吉，无bug
******************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<map>
using namespace std;
typedef long long ll;

struct edge{
    int u,v,w;
    inline bool operator < (edge a){
        return w<a.w;
    }
}e[10000];
map<string,int>ma;
int fa[102];
int find(int a){
    return fa[a]==a?a:fa[a]=find(fa[a]);
}

int main(){
	int n,m,w;
    string a,b;
    cin>>n>>m;
    ma["English"]=0;
    int len=0;
    for(int i=0; i<=n; i++){
        fa[i]=i;
    }
    for(int i=1; i<=n; i++){
        cin>>a;
        ma[a]=i;
    }
    for(int i=0; i<m; i++){
        cin>>a>>b>>w;
        e[i]={ma[a],ma[b],w};
    }
    sort(e,e+m);
    ll ans=0;
    for(int i=0; i<m; i++){
        int fx=find(e[i].u);
        int fy=find(e[i].v);
        if(fx!=fy){
            fa[fx]=fy;
            ans+=e[i].w;
            len++;
            if(len==n){
                break;
            }
        }
    }
    if(len!=n){
        cout<<"Impossible";
        return 0;
    }
    cout<<ans;
	return 0;
}
