/************************************************
 * Auther        : SR
 * Date          : 2022-04-24 19:57:26
 * LastEditTime  : 2022-04-24 20:08:01
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
    vector<string>strs(n);
    for(int i=0; i<n; i++){
        cin>>strs[i];
    }
    
    int num, str_len = strs[0].length();
    vector<int>nums(str_len);
    for(int i=0; i<str_len; i++){
        num = 0;
        for(int j=0; j<n; j++){
            num = num*10 + (strs[j][i] - '0');
        }
        nums[i] = num;
    }

    sort(nums.begin(), nums.end());

    for(auto &a : nums){
        cout<<a<<' ';
    }
	return 0;
}
