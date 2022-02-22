/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\temp\J.cpp
 * Date: 2020-03-01 14:49:03
 * LastEditTime: 2020-03-01 14:51:46
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
int a[200005];
int main(){
	int n,ans,p;
    cin>>n;
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    ans=0;p=0;
    for(int i=0; i<n; i++){
        if(a[i]==a[i+1]){
            p++;
            i++;
        }
    }
    cout<<p/2;
	return 0;
}
