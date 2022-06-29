/************************************************
 * Auther        : SR
 * Date          : 2022-04-29 18:37:48
 * LastEditTime  : 2022-04-29 19:47:55
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
    cin>>n;
    map<ll, ll>nums;
    // vector<ll>nums;

    
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        nums[num]++;
        // cin>>nums[i];
    }
    // sort(nums.begin(), nums.end());
    // for(auto &a : nums){
    //     cout<<a.first<<' '<<a.second<<'\n';
    // }
    // cout<<nums.end()->second;
    while(true){
        ll min = nums.begin()->first;
        ll max = nums.rbegin()->first;
        // for(auto &p : nums){
        //     max = p.first;
        // }
        // ll max = nums.end()->first;
        // cout<<min<<' '<<max<<'\n';

        if(min == max){
            break;
        }

        nums[min]--;
        if(nums[min] == 0){
            nums.erase(min);
        }
        nums[max]--;
        if(nums[max] == 0){
            nums.erase(max);
        }

        ll mid = (min + max) / 2ll;
        nums[mid]++;

    }

    cout<< nums.begin()->first;
    

	return 0;
}
