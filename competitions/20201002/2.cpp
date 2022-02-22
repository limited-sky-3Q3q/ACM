/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20201002\2.cpp
 * Date: 2020-02-08 22:26:31
 * LastEditTime: 2020-10-05 19:20:31
 * !��������: ������bug
************************************************/
#define _CRT_SECURE_NO_WARNINGS
/*
���Ǽ���ÿ���߶������������Ĺ��ף��ȼ����ж�����·��ͨ��������
�������� u -> v �ıߣ�·������Ϊk (n ? k ) 
v�������ֱ���k��n-k���㣬�ʾ����õ�ı���Ϊk*(n-k)
*/
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
ll times[MAXN];//��¼�������м����㣬�������ĵ��޹�
ll dp[MAXN];//��¼��Ȩֵ
ll t,n;


struct edge{//�ոտ�С��:(
    ll v,next;
}e[2*MAXN];//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void add(ll u, ll v){
    e[len].v=v;
    e[len].next=head[u];
    head[u]=len++;
}

void dfs(ll node, ll father){
    
    //ll temp=0;
    //bool flag=true;

    //times[node] = 1;

    for(int i=head[node]; i>0; i=e[i].next){
        if(e[i].v == father)
            continue;
        else{
            //vis[e[i].v]=1;
            ll v = e[i].v;
            dfs(v, node);//�ȴ����ӽڵ�ı������Ĵ���
            times[node] += times[v];
            dp[node] += dp[v] + (n-times[v])*times[v];
            //flag =false;
        }
    }
    
    //if(flag)
    //    times[node]=1;
    return;
    
}
int main(){
    ll a,b;
    scanf("%lld", &t);
    
    for(ll i=0; i<t; i++){
        //init
        len=1;
        memset(head, 0, sizeof head);
        memset(vis, 0, sizeof vis);
        memset(dp, 0, sizeof dp);
        //memset(times, 0x00000001, sizeof times);
        for(int i=0; i<MAXN; i++)
            times[i]=1;

        scanf("%lld", &n);

        for(ll j=0; j<n-1; j++){
            scanf("%lld%lld", &a, &b);
            add(a,b);
            add(b,a);
        }
        
        dfs(1, -1);
        
        double ans = double(dp[1])/double(n*(n-1)/2);
        
        printf("Case #%lld: %lf\n", i+1, ans);
        
    }
    
    
	return 0;
}
