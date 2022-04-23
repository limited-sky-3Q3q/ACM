/************************************************
 * Auther        : SR
 * Date          : 2022-04-02 10:17:18
 * LastEditTime  : 2022-04-02 11:56:58
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
	int n, nums[100001], cost=0, ans=INT_MAX, nums_add[100000], nums_add2[100000];
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>nums[i];

    int l=0, r=n-1;
    
    nums_add[0]=0;
    for(int i=1; i<n; i++){
        if(nums[i] > nums[i-1]+nums_add[i-1]){
            nums_add[i]=0;
            continue;
        }
        else{
            cost += nums[i-1] + nums_add[i-1] - nums[i] + 1;
            nums_add[i] = nums[i-1] + nums_add[i-1] - nums[i] + 1;
        }

    }
    // for(int i=0; i<n; i++)
    //     cout<<nums_add[i]<<' ';
    //     cout<<'\n';
    ans = cost;

    
    nums_add2[n-1]=0;
    for(int i=n-2; i>=0; i--){
        if(nums[i] > nums[i+1]+nums_add2[i+1]){
            nums_add2[i]=0;
            continue;
        }
        else{
            nums_add2[i] = nums[i+1] + nums_add2[i+1] - nums[i] + 1;
        }
    }
    //  for(int i=0; i<n; i++)
    //     cout<<nums_add[i]<<' ';
    //     cout<<'\n';

    for(int i=n-1; i>=0; i--){
        cost += nums_add2[i];
        cost -= nums_add[i];

        ans = min(ans, cost);
    }
    cout<<ans;
	return 0;
}
