/************************************************
 * Auther        : SR
 * Date          : 2022-04-20 18:55:19
 * LastEditTime  : 2022-04-20 19:22:50
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

int main(){
	int n;
    cin>>n;
    ll damages[2][40000];
    for(int i=0; i<n; i++){
        cin>>damages[0][i];
    }
    for(int i=0; i<n; i++){
        cin>>damages[1][i];
    }

    ll tot[2] = {0, 0};
    ll cost = 0;
    for(ll i=0; i<n; i++){
        tot[0] += damages[0][i];
        tot[1] += damages[1][i];
        
        while(tot[0] + cost*(i + 1) <= tot[1]){// lose
            cost++;
        }
    }
    cout<<cost;
	return 0;
}
