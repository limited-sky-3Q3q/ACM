/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\A.cpp
 * Date: 2020-02-12 11:50:17
 * LastEditTime: 2020-02-12 13:51:32
 * ! 今日运势: 吉，无bug
 * TODO 本质上是最小生成树，但需要一些变通才能理解
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
using namespace std;
typedef long long ll;
const int MAXN = 2003;

struct edge{
    int from,to;
    ll weight;
    //TODO 好好学学
    inline bool operator < (const edge &a)const{
        return weight < a.weight;
    }
}que[MAXN*MAXN];

int x[MAXN], y[MAXN], c[MAXN], k[MAXN], fa[MAXN];
int find(const int a){
    return fa[a]==a ? a:fa[a]=find(fa[a]);
}

int main(){
/*
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
*/
	int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    m=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        que[++m]={0,i,1ll*c[i]};
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            que[++m]={i,j,1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))};
        }
    }
    sort(que+1,que+m+1);//kruscal
    for(int i=0;i<=n;i++){
        fa[i]=i;
    }
    int now=0, af, bf, ans[MAXN], v=0, e=0;
    edge link[MAXN];
    ll cost = 0;
    for(int i=1;i<=m;i++){
    //!注意 af bf只是用来判断是否在同一颗树上而已
        af=find(que[i].from);
        bf=find(que[i].to);
        if(af != bf){
            now++;
            fa[af]=bf;
            
            if(que[i].from==0){//!注意不是根节点为0
                ans[++v]=que[i].to;
            }
            else{
                link[++e]=que[i];
            }
            cost += que[i].weight;
        }
        if(now==n){
            break;
        }
    }

    cout<<cost<<"\n";
    cout<<v<<"\n";
    sort(ans+1, ans+v+1);
    for(int i=1; i<=v; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n"<<e<<"\n";
    for(int i=1; i<=e; i++){
        cout<<link[i].from<<" "<<link[i].to<<"\n";
    }
	return 0;
}

