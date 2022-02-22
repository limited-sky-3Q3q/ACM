/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\temp2\test.cpp
 * Date: 2020-03-08 12:36:02
 * LastEditTime: 2020-03-08 14:52:01
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

char a[100005],b[100005];
int n;
void swap(char &a, char &b){
    char t;
    t=a;a=b;b=t;
    return ;
}
int main(){
    cin>>n>>a>>b;
    
    for(int i=0; i<n-1; i++){
        if(a[i]>b[i]){
            if(n-1-i>=2){
                cout<<"YES\n"<<i+2<<" "<<i+3;
                return 0;
            }
            if(a[i+1]>=b[i+1]){
                cout<<"YES\n"<<i+1<<" "<<i+2;
                return 0;
            }
            else{
                cout<<"NO";
                return 0;
            }
        }
        if(a[i]<=b[i]){
            for(int j=i+1; j<n; j++){
                if(a[j]>b[j]){
                    cout<<"YES\n"<<i+1<<" "<<j+1;
                    return 0;
                }
            }
            cout<<"NO";
            return 0;
        }
    }
    
	return 0;
}
