/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200412\G.cpp
 * Date: 2020-04-12 13:14:25
 * LastEditTime: 2020-04-13 21:40:45
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

int main(){
	ll T,K;
    cin>>T>>K;
    //cout<<T+(T+K-1)/K;
    cout<<T + 1 +(T-1)/K;
	return 0;
}