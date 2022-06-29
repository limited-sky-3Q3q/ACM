/************************************************
 * Auther        : SR
 * Date          : 2022-04-24 19:57:39
 * LastEditTime  : 2022-04-24 20:28:42
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
	int n;
    string S;
    cin>>n>>S;
    
    vector<ll>w_count(n+1, 0), v_count(n+2, 0);

    
    for(ll i=1; i<=n; i++){// 1 - n
        if(S[i-1] == '0'){
            w_count[i] = w_count[i-1] + i;
        }
        else{
            w_count[i] = w_count[i-1];
        }
    }
    for(ll i=n; i>=0; i--){// 1 - n
        if(S[i-1] == '1'){
            v_count[i] = v_count[i+1] + i;
        }
        else{
            v_count[i] = v_count[i+1];
        }
    }
    
    ll W, V, ans = 0x3f3f3f3f3f3f3f;
    for(int pos=0; pos<=n; pos++){
        W = w_count[pos];
        V = v_count[pos+1];
        ans = min(ans, abs(W - V));
    }

    cout<<ans;

	return 0;
}
