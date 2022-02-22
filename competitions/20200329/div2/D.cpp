/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200329\div2\D.cpp
 * Date: 2020-03-30 21:13:37
 * LastEditTime: 2020-03-30 21:20:01
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
	int n,x,y,t;
    cin>>t;
    while(cin>>n>>x>>y){
        if((x >= (n+1)/2) && (y >= (n-1)/2)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    
	return 0;
}
