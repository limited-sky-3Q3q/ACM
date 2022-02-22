/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day2div2\D.cpp
 * Date: 2020-02-07 20:03:24
 * LastEditTime: 2020-02-08 22:34:37
 * ! 今日运势: 吉，无bug
 * 能看懂题意的话不难，问题是我没看懂题意。。。
 * 不是你这破编译器，数组溢出自直接说啊？？？！！！
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
#include<map>
using namespace std;
typedef long long ll;
int ans[1000006];
int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T,num,k;
	memset(ans, 0 , sizeof(ans));
	char ch;
	ll now;
	cin>>T;
	while(T--){
		k = 1, num = 0;
		cin>>ch>>now;
		while(now){//把数据转换成二进制的01再转换成十进制
			num += now%2*k;
			now /= 10;
			k *= 2;
		}
		if(ch == '+'){
			ans[num]++;
		}
		else if(ch == '-'){
			ans[num]--;
		}
		else{
			cout<<ans[num]<<"\n";
		}
	}
	return 0;
}
