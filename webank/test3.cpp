/************************************************
 * Auther        : SR
 * Date          : 2022-04-20 18:55:31
 * LastEditTime  : 2022-04-20 20:43:00
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
	int n, k;
    char ch;
    string str;
    cin>>n>>k>>ch>>str;


    int l=0, pos_before=-1, ans=0, ch_count=0;
    queue<int>ch_pos;
    for(int r=0; r<n; r++){
        if(str[r] == ch){
            ch_pos.push(r);
        }

        

        while(ch_pos.size() > k){
            pos_before = ch_pos.front();
            ch_pos.pop();
        }

        if(ch_pos.size() == k){
            ans += ch_pos.front() - pos_before;
        }

        // cout<<ans;
    }

    cout<<ans;
	return 0;
}
