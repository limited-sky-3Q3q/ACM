/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200607\C.cpp
 * Date: 2020-06-07 13:14:26
 * LastEditTime: 2020-06-07 13:26:22
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

int que[1000];
bool done[1000];
int main(){
    int n, now = 0, l = 1,ans=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>que[i];
    }
    
    for(int i=1; i<=n; i++){
        if(done[i])
            continue;

        now = 0;
        for(int j=l; j<=i; j++){
            now += que[i] - que[j];
        }

        if(now >= 20){
            for(int j=l; j<i; j++){
                done[j] = true;
            }
            ans++;
            l = i;
        }
    }
    if(done[n] == false)
        ans++;
    cout<<ans;
	return 0;
}
