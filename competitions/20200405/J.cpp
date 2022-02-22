/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200405\J.cpp
 * Date: 2020-04-05 16:28:52
 * LastEditTime: 2020-04-05 17:19:29
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
struct st{
    string s;
    int form;   
}dp[15][15];//[i][j]第i个取j长度时的最小值
string que[15];
string temp[15][15];

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>que[i];
        for(int j=0; j<14; j++)dp[i][j].s.clear();
    }
    
    for(int i=0; i<n; i++){//第i个人
        for(int j=1; j<que[j].length(); j++){
            
        }
    }
	return 0;
}
