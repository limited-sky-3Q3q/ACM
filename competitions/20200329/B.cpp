/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200329\B.cpp
 * Date: 2020-03-30 10:41:31
 * LastEditTime: 2020-03-30 20:59:29
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

int ans=0,n,cnt=1;
struct point{
    int x,y;
}p[20],v[10];

bool vis[20];

void dfs(int index){
    while(vis[index])//点用过了就跳过
        index++;

    while(index >= n){//到头，判断，return
        int maxn=0;
        for(int i=1; i<cnt-1; i++){
            for(int j=i+1; j<cnt; j++){
                if(v[i].x*v[j].y == v[i].y*v[j].x){
                    maxn++;
                }
            }
        }
        ans=max(ans, maxn);
        return;
    }
        
    vis[index]=true;
    for(int i=1; i<=n; i++){
        if(!vis[i] && index != i){//找到没用过的点
            vis[i]=true;
            v[cnt].x = p[i].x-p[index].x;
            v[cnt].y = p[i].y-p[index].y;
            cnt++;
            dfs(index+1);
            cnt--;
            vis[i]=false;
        }
    }
    vis[index]=false;
    return;
}

int main(){//暴力就完事了
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>p[i].x>>p[i].y;
    }
    memset(vis, false, sizeof vis);
    dfs(1);
    
    cout<<ans;
	return 0;
}
