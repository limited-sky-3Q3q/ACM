/************************************************
 * Auther        : SR
 * Date          : 2022-03-31 13:51:41
 * LastEditTime  : 2022-04-02 11:05:21
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
    int n,r,b,r_need=0, b_need=0, need_count=0;
	char ball_n[100000];
	cin>>n>>b>>r;

	for(int i=0; i<n; i++)
		cin>>ball_n[i];

	for(int i=1; i<n; i++)
		if(ball_n[i-1] == ball_n[i]){
			if(ball_n[i] == 'r')
				b_need++;
			else
				r_need++;
		}
	
	if(r>=r_need && b>=b_need){
		cout<<(r_need + b_need + n);
	}
	else{
		cout<<(b>=b_need ? 0 : b_need-b)<<' '<<(r>=r_need ? 0 : r_need-r);
	}
			
	
	return 0;
}
