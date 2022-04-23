/************************************************
 * Auther        : SR
 * Date          : 2022-04-07 18:42:04
 * LastEditTime  : 2022-04-07 20:17:02
************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int maxn = 100;
const ll mod = 1e9 + 7;

int main(){
	string num_input;
    ll max_val=0;
    vector<ll>ans;

    cin>>num_input;

    for(auto& ch : num_input){

        if(ch < '9'+1){// 0-9
            max_val = max(ll(ch - '0'), max_val);
        }
        else{// A-F
            max_val = max(ll(ch - 'A' + 10), max_val);
        }

    }

    
    for(ll i=max_val+1; i<=16; i++){
        int val = 0;

        for(auto& ch : num_input){

            if(ch < '9'+1){// 0-9
                // ans = (ans*i + ll(ch - '0')) % mod;
                // ans = (ans*i % mod  + (ch - '0')) % mod;
                val = ((val%mod)*i % mod  + (ch - '0')) % mod;

            }
            else{// A-F
                // ans = (ans*i + ll(ch - 'A' + 10)) % mod;
                val = ((val%mod)*i % mod  + (ch - 'A' + 10)) % mod;

            }

        }
        // cout<<ans<<'\n';
        ans.push_back(val);
    }

    map<ll, ll>has;
    sort(ans.begin(), ans.end());

    for(auto& a : ans){
        if(has[a]++){
            continue;
        }
        cout<<a<<'\n';
    }
	return 0;
}
