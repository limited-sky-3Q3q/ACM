/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\CF\extra\Time_limit.cpp
 * Date: 2020-09-11 17:15:07
 * LastEditTime: 2020-09-11 21:57:31
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
    int T,n,a[12];
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        
        sort(a+1, a+n);

        for(int j=a[n-1]+1;1; j++){
            if(j >= 3*a[0] && j%2==0){
                cout<<j<<'\n';
                break;
            }
        }
        
        
    }
    system("pause");
	return 0;
}
..................3.