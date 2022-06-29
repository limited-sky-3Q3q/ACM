/************************************************
 * Auther        : SR
 * Date          : 2022-04-23 19:13:31
 * LastEditTime  : 2022-04-23 19:55:43
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


bool find_solution(int require_count, vector<ll>& nums, int k){

    for(int begin_pos=0; begin_pos<require_count; begin_pos++){
        int end_pos = nums.size() + begin_pos - require_count - 1;
        
        if(nums[end_pos] - nums[begin_pos] <= k){
            return true;
        }
    }

    return false;
}


int main(){
	ll n,k;
    cin>>n>>k;
    vector<ll>nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }


    sort(nums.begin(), nums.end());

    int l=0, r=n, mid;

    while(l<r){
        mid = (l+r)/2;

        if(find_solution(mid, nums, k)){// 找到可行解
            r = mid;
        }
        else{
            l = mid+1;
        }
    }

    cout<<l;

	return 0;
}
