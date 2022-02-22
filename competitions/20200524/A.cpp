/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200524\A.cpp
 * Date: 2020-05-24 12:46:11
 * LastEditTime: 2020-05-25 20:34:26
 * !今日运势: 吉，无bug
 * 看不懂啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

int sum[25][2500010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("zeros.in","r",stdin);
    int T;
    cin>>T;
    while(T--){
        
        int x,y,m,k;
        cin>>x>>y>>m>>k;
        x--;

        ll n = (1ll << (x+y));//首位一定为1
        int s = x+y;
        
        int s1 = (s>>1);//(x+y)/2
        for(int i=0; i<(1<<s1); i++){//枚举右半区间
            int cnt = __builtin_popcount(i);//cnt = i中的1的数量
            for(int j=0; j<=s1; j++){//j：1的个数
                sum[j][i] = j == cnt;//用线段树存储
                if(i)//sum[j][i] : 0 - i 中含有 j 个 1 的数的数量
                    sum[j][i] += sum[j][i-1];
            }
        }

        
        ll ans = 0;
        //暴暴暴暴暴力枚举
        for(ll i=n; i<n+(1ll<<s); i += (1<<s1)){//左半区间
            int cnt = __builtin_popcountll(i);//当前左半区间有的1的数量
            int now = x+1-cnt;//右半区间需要的1的数量
            if(now<0 || now>s1)//不可能满足条件
                continue;

            //满足条件的最小数
            int r = ((k-i)%m + m) % m;//右区间取模
            int l = ((m-1-i)%m +m) % m;//

            if(r > l)
                r -= m;
            while(r<(1<<s1)){
                int R = max(0, r);
                int L = min((1<<s1)-1, l);
                ans += sum[now][L] - (R==0?0:sum[now][R-1]);//答案的区间是周期性的
                r += m, l += m;
            }
        }
        
        cout<<ans<<endl;

    }
	return 0;
}
/*
1. #include<bits/stdc++.h>
2. using namespace std;
3. #define ll long long
4.  
5. int sum[25][2500010];
6. signed main(){
7.     ios::sync_with_stdio(0);cin.tie(0);
8.     freopen("zeros.in","r",stdin);
9.     int t;cin>>t;
10.     while(t--){
11.         int x,y,m,k;cin>>x>>y>>m>>k;x--;
12.         // 最高位一定要是1
13.         ll n=1ll<<(x+y);int s=x+y,s1=s>>1;
14.         for(int i=0;i<1<<s1;i++){
15.             int cnt=__builtin_popcount(i);
16.             for(int j=0;j<=s1;j++){
17.                 sum[j][i]=j==cnt;
18.                 if(i) sum[j][i]+=sum[j][i-1];
19.             }
20.         }
21.  
22.         ll ans=0;
23.         for(ll i=n;i<n+(1ll<<s);i+=1<<s1){
24.             int cnt=__builtin_popcountll(i);
25.             int now=x+1-cnt;
26.             if(now<0||now>s1)continue;
27.             int l=((k-i)%m+m)%m;
28.             int r=((m-1-i)%m+m)%m;
29.             if(l>r)l-=m;
30.             while(l<(1<<s1)){
31.                 int L=max(0,l),R=min((1<<s1)-1,r);
32.                 ans+=sum[now][R]-(L==0?0:sum[now][L-1]);
33.                 l+=m,r+=m;
34.             }
35.         }
36.         cout<<ans<<endl;
37.     }
38. }
*/
/*
int sum[25][2500010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("zeros.in","r",stdin);
    int t;cin>>t;
    while(t--){
        
        int x,y,m,k;cin>>x>>y>>m>>k;x--;
        ll n=1ll<<(x+y);int s=x+y,s1=s>>1;
        for(int i=0;i<1<<s1;i++){
            int cnt=__builtin_popcount(i);
            for(int j=0;j<=s1;j++){
                sum[j][i]=j==cnt;
                if(i) sum[j][i]+=sum[j][i-1];
            }
        }
 
        // for(int i=0;i<5;i++){
        //     for(int j=0;j<5;j++){
        //         cout<<sum[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
 
        ll ans=0;
        for(ll i=n;i<n+(1ll<<s);i+=1<<s1){
            int cnt=__builtin_popcountll(i);
            int now=x+1-cnt;
            // cout<<i<<" "<<now<<endl;
            if(now<0||now>s1)continue;
            int l=((k-i)%m+m)%m;
            int r=((m-1-i)%m+m)%m;
            if(l>r)l-=m;
            // cout<<i<<" org "<<l<<" "<<r<<endl;
            while(l<(1<<s1)){
                int L=max(0,l); 
                int R=min((1<<s1)-1,r);
                int tmp=sum[now][R]-(L==0?0:sum[now][L-1]);
                ans+=tmp;
                // cout<<i<<" "<<L<<" "<<R<<" "<<tmp<<endl;
                l+=m,r+=m;
            }
        }
        cout<<ans<<endl;
    }
}
*/