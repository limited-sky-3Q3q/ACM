/**
 * TODO Auther: by SR
 * Date: 2020-01-21 14:43:58
 * LastEditTime: 2020-02-01 15:50:08
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
using std::cin;
using std::cout;
typedef long long ll;
const int MAXN = 30;
const int MOD = 2520;

ll ans[MAXN][MOD+10][50];
int bit[MAXN], hash[MOD+10];

ll gcd(ll, ll); ll lcm(ll, ll);
ll solve(ll);
ll dfs(int, int, int, bool);
void init();

int main(){
	ll T, l, r;
    init();
    memset(ans, -1, sizeof(ans));
    cin >> T;
    while(T--){
        cin >> l >> r;
        if(l == 0 && r == 0){
            break;
        }
        cout <<solve(r) - solve(l-1) <<"\n";
    }
	return 0;
}

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

void init(){
    int pos = 0;
    for(int i = 1; i <= MOD; i++){
        if(MOD % i == 0){
            hash[i] = ++pos;
        }
    }
    return;
}

ll solve(ll now){
    int len = 0;
    while(now){
        bit[++len] = now % 10;
        now /= 10;
    }
    return dfs(len, 0, 1, true);
}

ll dfs(int len, int preSum, int preLcm, bool flag){
    if(len == 0){
        return preSum % preLcm == 0;
    }
    if(!flag && ans[len][preSum][hash[preLcm]] != -1){
        return ans[len][preSum][hash[preLcm]];
    }

    ll answer = 0;
    int end = (flag ? bit[len]:9);
    for(int i = 0; i <= end; i++){
        int nowSum = (preSum*10 + i) % MOD;
        int nowLcm = preLcm;
        if(i){
            nowLcm = lcm(nowLcm, i);
        }
        answer += dfs(len - 1, nowSum, nowLcm, flag && i == end);
    }

    if(!flag){
        ans[len][preSum][hash[preLcm]] = answer;
    }
    return answer;
}