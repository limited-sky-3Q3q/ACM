/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\temp2\C.cpp
 * Date: 2020-03-08 13:49:09
 * LastEditTime: 2020-03-08 15:29:20
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
int t,n;
int main(){
	cin>>t;
	int cnt;
	while(t--){
		cnt=0;
		cin>>n;
		int a=sqrt(n);

		for(int i=2; i<n&&i<=a; i++){
			while(n%i==0){
				cnt += i-1;
				n/=i;
			}
		}
		cout<<cnt+n<<"\n";
	}
	return 0;
}
