/************************************************
 * Auther        : SR
 * Date          : 2022-04-23 19:13:28
 * LastEditTime  : 2022-04-23 19:24:06
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

bool cmp(int &a, int &b){
    return a%4 < b%4;
}

int main(){
	ll n,m;
    cin>>n>>m;
    vector<int>nums1(n), nums2(m);

    for(int i=0; i<n; i++){
        cin>>nums1[i];
    }
    for(int i=0; i<m; i++){
        cin>>nums2[i];
    }

    // sort(nums1.begin(), nums1.end(), cmp);
    // sort(nums2.begin(), nums2.end(), cmp);

    ll moded_count[2][4] = {0,0,0,0,0,0,0,0};
    for(int i=0; i<n; i++){
        moded_count[0][nums1[i]%4]++;
    }
    for(int i=0; i<m; i++){
        moded_count[1][nums2[i]%4]++;
    }

    ll ans = 0;
    
    ans += moded_count[0][0] * m;
    ans += moded_count[0][1] * moded_count[1][0];
    ans += moded_count[0][2] * (moded_count[1][2] + moded_count[1][0]);
    ans += moded_count[0][3] * moded_count[1][0];

    cout<<ans;

	return 0;
}
