/************************************************
 * Auther        : SR
 * Date          : 2022-04-20 18:55:26
 * LastEditTime  : 2022-04-20 19:56:38
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
    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    ll ans = n;// 单个元素
    for(int pos_begin=0; pos_begin<n; pos_begin++){
        // [pos_begin, n-1] 的结果 
        // 必须包含nums[pos_begin]
        
        stack<int>S;
        for(int i=pos_begin+1; i<n; i++){
            // 单调栈

            while(!S.empty() && S.top() > nums[i]){
                S.pop();
            }

            if(nums[i] < nums[pos_begin]){
                // 小于起始值，不进入栈
                continue;
            }
            else{
                S.push(nums[i]);
            }

            
            ans = ans + (1ll<<(S.size() - 1));
            // cout<<ans<<'\n';
        }
    }

    cout<<ans;
	return 0;
}
