/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\J.cpp
 * Date: 2020-02-19 13:50:05
 * LastEditTime: 2020-02-19 15:44:32
 * ! 今日运势: 吉，无bug
 *                           * prime
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
const int N=1003;
const int INF = 0x3f3f3f3f;

ll dis[N][N];
bool vis[N];
int main(){
	int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>dis[i][j];
        }
    }
    ll ans=0;
    int len=1;
    int min=0x3f3f3f3f;
    vis[1]=true;
    int u,v;
    for(int i=1; i<= n*n; i++){
        min=0x3f3f3f3f;
        for(int j=1; j<=n; j++){
            if(vis[j]){
                for(int k=1; k<=n; k++){
                    if(k==j)continue;
                    if(min > dis[j][k]){
                        min=dis[j][k];
                        u=j;
                        v=k;
                    }
                }
            }
        }
        
        if(!vis[v]){
            vis[v]=true;
            ans += min;
            len++;
            if(len==n){
                cout<<ans;
                return 0;
            }
        }
        dis[u][v]=0x3f3f3f3f;
        /*
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(dis[i][j]==INF){
                    cout<<"X ";
                }
                else{
                    cout<<dis[i][j]<<" ";
                }
            }
            cout<<"\n";
        }
        */
    }
	return 0;
}
