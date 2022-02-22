/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200531\F.cpp
 * Date: 2020-05-31 16:10:30
 * LastEditTime: 2020-05-31 16:30:19
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
struct node{
    int b,f;
    int w;
}que[100005];
bool cmp(node a, node b){
    if(a.b == b.b)
        return a.f < b.f;
    else
        return a.b < b.b;
    //return a.b < b.b? 1 : 
}

int n;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d%d%d", &que[i].b, &que[i].f, &que[i].w);
    
    sort(que, que + n, cmp);
    
    
	return 0;
}



#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
typedef long long ll;
 
struct node{
    int A,B;
    ll C;
}P[MAXN];
bool cmp(node a,node b){
    if(a.A==b.A)
        return a.B<b.B;
    return a.A<b.A;
}
 
int s[MAXN*2];
 
vector<int> li[MAXN*2];
 
bool cmp2(int a,int b){
    return a>b;
}
 
map<pair<int,int> ,ll> C;
 
ll tree[MAXN];
 
int lowbit(int t)
{
    return t&(-t);
}
 
void update(int index,ll value){
    for(int i=index;i<=MAXN;i+=lowbit(i)){
        tree[i] = max(tree[i],value);
    }
}
 
ll sum(int index){
    ll sum = 0;
    for(int i=index;i>0;i-=lowbit(i)){
        sum = max(sum,tree[i]);
    }
    return sum;
}
 
int main(){
    
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d%d%lld",&P[i].A,&P[i].B,&P[i].C);
        s[i]=P[i].A;
        s[N+i]=P[i].B;
    }
    
    sort(s,s+2*N);//AB一起排序？？？
    int cnt=unique(s,s+2*N)-s;
    
    for(int i=0;i<N;i++){
        int a=lower_bound(s,s+cnt,P[i].A)-s+1;
        int b=lower_bound(s,s+cnt,P[i].B)-s+1;
        C[make_pair(a,b)]+=P[i].C;
        li[a].push_back(b);
    }
    
    for(int a=1;a<=cnt;a++){
        sort(li[a].begin(),li[a].end(),cmp2);
        for(int i=0;i<li[a].size();i++){
            auto b=li[a][i]; 
            ll tmp=sum(b-1);
            ll ans=tmp+C[make_pair(a,b)];
            update(b,ans);
        }
    }
    
    cout<<sum(cnt)<<endl;
    
    return 0;
}