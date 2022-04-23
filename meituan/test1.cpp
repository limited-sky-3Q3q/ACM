/************************************************
 * Auther        : SR
 * Date          : 2022-04-02 11:10:00
 * LastEditTime  : 2022-04-02 11:50:55
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


int main(){
	ll n, A[100][100];
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>A[i][j];

    ll ans=0, max_val, min_val, t_add, t_sub;

    for(int i=0; i<n/2+1; i++)
        for(int j=0; j<n/2+1; j++){
            max_val = A[i][j];
            min_val = A[i][j];

            max_val = max(max_val, A[n-1-i][n-1-j]);
            max_val = max(max_val, A[j][n-1-i]);
            max_val = max(max_val, A[n-1-j][i]);
                        
            min_val = min(min_val, A[n-1-i][n-1-j]);
            min_val = min(min_val, A[j][n-1-i]);
            min_val = min(min_val, A[n-1-j][i]);

            ll cost=0, min_cost=INT_MAX;
            
            cost = 0;
            cost += abs(A[i][j]-A[i][j]);
            cost += abs(A[i][j]-A[n-1-i][n-1-j]);
            cost += abs(A[i][j]-A[j][n-1-i]);
            cost += abs(A[i][j]-A[n-1-j][i]);
            min_cost = min(min_cost, cost);

            cost = 0;
            cost += abs(A[n-1-i][n-1-j]-A[i][j]);
            cost += abs(A[n-1-i][n-1-j]-A[n-1-i][n-1-j]);
            cost += abs(A[n-1-i][n-1-j]-A[j][n-1-i]);
            cost += abs(A[n-1-i][n-1-j]-A[n-1-j][i]);
            min_cost = min(min_cost, cost);

            cost = 0;
            cost += abs(A[j][n-1-i]-A[i][j]);
            cost += abs(A[j][n-1-i]-A[n-1-i][n-1-j]);
            cost += abs(A[j][n-1-i]-A[j][n-1-i]);
            cost += abs(A[j][n-1-i]-A[n-1-j][i]);
            min_cost = min(min_cost, cost);

            cost = 0;
            cost += abs(A[n-1-j][i]-A[i][j]);
            cost += abs(A[n-1-j][i]-A[n-1-i][n-1-j]);
            cost += abs(A[n-1-j][i]-A[j][n-1-i]);
            cost += abs(A[n-1-j][i]-A[n-1-j][i]);
            min_cost = min(min_cost, cost);


            A[i][j] = min_cost;
            A[n-1-i][n-1-j] = min_cost;
            A[j][n-1-i] = min_cost;
            A[n-1-j][i] = min_cost;
            
            
            
            ans += min_cost;
            // cout<<ans<<' ';
        }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++)
    //         cout<<A[i][j]<<' ';

    //     cout<<'\n';
    // }
    cout<<ans;
	return 0;
}
