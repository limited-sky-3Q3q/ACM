/************************************************
 * Auther        : SR
 * Date          : 2022-04-02 10:41:56
 * LastEditTime  : 2022-04-05 10:28:42
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
int T,n,m;


int main(){
	vector<int>A(3);
    A[0]=1, A[1]=2, A[2]=3;

    sort(A.begin(), A.end(), greater<int>());
    // int a = accumulate(A.begin(), A.end(), 0);
    // int a=0;
    for(auto& i:A)
        // a += i;
        cout<<i<<' ';
    // cout<<a;
    
	return 0;
}
