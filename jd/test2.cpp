/************************************************
 * Auther        : SR
 * Date          : 2022-04-29 18:38:00
 * LastEditTime  : 2022-04-29 20:08:38
************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;


int main(){
	ll n, k;
    const ll mod = 998244353;
    cin>>n>>k;
    vector<vector<ll> >dp(2, vector<ll>(n+1));

    dp[0][0] = 1;
    dp[1][0] = 0;// ?
    for(int i=1; i<=k; i++){
        dp[0][i] = dp[0][i-1];// 竖
        dp[1][i] = 0;// 横
    }
    dp[1][k] = 1;

    for(int i=k+1; i<=n; i++){
        dp[0][i] = ((dp[0][i-1] % mod) + (dp[1][i-1] % mod)) % mod;
        dp[1][i] = ((dp[0][i-k] % mod) + (dp[1][i-k] % mod)) % mod;
    }

    cout<<((dp[0][n] % mod) + (dp[1][n] % mod)) % mod;

	return 0;
}
