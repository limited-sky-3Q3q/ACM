/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\L.cpp
 * Date: 2020-02-19 18:49:22
 * LastEditTime: 2020-02-19 19:52:58
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
const int N=10004;
struct edge{
    int from, to;
    double w;
}e[1000006];
bool cmp(const edge a, const edge b){
    return a.w>b.w;
}
struct cor{
    double x,y;
}pos[N];
int fa[N];
int find(const int a){
    //!!!!!又写错了，ccccccccccccccccccc
    return fa[a]==a?a:fa[a]=find(fa[a]);
}
int main(){
	int n,m,a,b;
    double sum=0;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>pos[i].x>>pos[i].y;
    }
    for(int i=0; i<m; i++){
        cin>>a>>b;
        e[i].from=a;
        e[i].to=b;
        e[i].w = sqrt(pow((pos[a].x-pos[b].x),2) + pow((pos[a].y-pos[b].y),2));
        sum+=e[i].w;
    }
    
    sort(e, e+m,cmp);
    for(int i=1; i<=n; i++){
        fa[i]=i;
    }
    int fx,fy,cnt=1;
    for(int i=0; i<m; i++){
        fx=find(fa[e[i].from]);
        fy=find(fa[e[i].to]);
        if(fx!=fy){
            fa[fx]=fy;
            cnt++;
            sum-=e[i].w;
            if(cnt==n){
                printf("%.3f",sum);
                return 0;
            }
        }
    }
    printf("%.3f",sum);
	return 0;
}
