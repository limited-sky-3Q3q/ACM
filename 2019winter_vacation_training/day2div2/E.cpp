/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day2div2\E.cpp
 * Date: 2020-02-09 12:09:54
 * LastEditTime: 2020-02-09 20:46:00
 * ! 今日运势: 吉，无bug
 * TODO 注意cnt要开成ll类型
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
#include<map>
#include<string.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+5;

char str[MAXN];
int main(){
/*
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
*/
    ll val[26];
    while(cin>>val[0]){
        map<ll, int>mp[26];
        for(register int i = 1; i < 26; i++){
            cin>>val[i];
        }
        cin>>str;
        int len = strlen(str);
        ll s = 0;
        ll cnt = 0;
        for(register int i = 0 ; i < len; i++){
            cnt += mp[str[i] - 'a'][s];
            s += val[str[i]-'a'];
            mp[str[i]-'a'][s]++;
        }
        cout<<cnt<<"\n";
    }
    
	return 0;
}
