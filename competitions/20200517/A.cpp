/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200517\A.cpp
 * Date: 2020-05-17 12:48:25
 * LastEditTime: 2020-05-17 13:29:08
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
ll a[10],b[10];
int main(){
    ll t;
    
    cin>>t;
    for(ll n = 1; n <=t; n++){
        
        ll ans = 0;
        for(int i=0; i<6; i++)
            cin>>a[i];
        for(int i=0; i<7; i++)
            cin>>b[i];
        
        ans = a[0]*1 + a[1]*2 + a[2]*3 + a[3]*3 + a[4]*4 + a[5]*10;
        ans -= b[0]*1 + b[1]*2 + b[2]*2 + b[3]*2 + b[4]*3 + b[5]*5 + b[6]*10;
        
        printf("Battle %lld: ", n);
        
        if(ans > 0ll){
            printf("Good triumphs over Evil\n");
        }else if(ans < 0ll){
            printf("Evil eradicates all trace of Good\n");
        }else{
            printf("No victor on this battle field\n");
        }
    }
	return 0;
}
