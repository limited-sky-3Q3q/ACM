/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200329\A.cpp
 * Date: 2020-03-30 09:58:31
 * LastEditTime: 2020-03-30 10:13:09
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

ll ans[102][2]={0};

int main(){
	int l,k;
    cin>>l>>k;
    //cout<<sizeof ans;
    ans[0][0]=1;
    for(int i=1; i<=l; i++){
        ans[i][1]+=ans[i-1][0];//[][1]黑
        if(i>=k){//
            ans[i][1]+=ans[i-k][0];
        }

        ans[i][0]+=ans[i-1][1];//[][0]白
    }

    ll a=0;
    for(int i=1; i<=l; i++){
        a+=ans[i][1];
    }

    cout<<a;
	return 0;
}
