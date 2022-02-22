/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\temp\G.cpp
 * Date: 2020-03-01 16:33:52
 * LastEditTime: 2020-03-01 16:57:21
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
int que[200005];

int main(){
	int n,k;
    ll ans=0;
    cin>>n>>k;
    for(register int i=0; i<n; i++){
        scanf("%d", &que[i]);
    }
    for(register int i=0; i<=n-k; i++){
        int l=i, r=i+k-1;
        for(register int j=0; l+j<r-j; j++){
            ans+=abs(que[l+j]-que[r-j]);
        }
    }
    cout<<ans;
	return 0;
}
