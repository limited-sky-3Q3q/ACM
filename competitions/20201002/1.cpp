/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20201002\1.cpp
 * Date: 2020-02-08 22:26:31
 * LastEditTime: 2020-10-05 18:34:58
 * !今日运势: 吉，无bug
************************************************/
//简单题
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

const ll MAXN = 200005;
const ll mod = 1000000000+7;
ll len,head[MAXN];
bool vis[MAXN];
ll t,n,k;

struct edge{
    ll v,next;
}e[2*MAXN];//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//刚刚开小了:(
void add(ll u, ll v){
    e[len].v=v;
    e[len].next=head[u];
    head[u]=len++;
}

ll bfs(ll node){
    
    ll temp=0;
    bool flag=true;

    for(int i=head[node]; i>0; i=e[i].next){
        if(vis[e[i].v])
            continue;
        else{
            vis[e[i].v]=1;
            
            temp += bfs(e[i].v);
            flag =false;
        }
    }

    if(flag)
        return 1;
    else{
        if(node==1){
            return temp;
        }
        else{
            return temp+1;
        }
    }
}

int main(){
    ll a,b;
    scanf("%lld", &t);
    
    for(ll i=0; i<t; i++){
        //init
        len=1;
        /*
        memset(head, 0, sizeof head);
        memset(vis, 0, sizeof vis);
        */
       
        for(int j=0; j<MAXN; j++){
            head[j]=0;
            vis[j]=0;
        }
        scanf("%lld%lld", &n, &k);


        
        
        for(ll j=0; j<n-1; j++){
            scanf("%lld%lld", &a, &b);
            
            add(a,b);
            add(b,a);
        }
        

        
        vis[1]=1;
        ll ex = bfs(1);
        ll ans=1;
        for(int j=0; j<ex; j++){
            ans = (ans*(k-1))%mod;
        }
        ans = (ans*k)%mod;
        printf("Case #%lld: %lld\n", i+1, ans);
        
    }
    
    
	return 0;
}
