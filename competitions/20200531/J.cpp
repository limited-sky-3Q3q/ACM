/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200531\J.cpp
 * Date: 2020-05-31 15:09:31
 * LastEditTime: 2020-05-31 15:47:58
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

char a[100005];
int k[100005];
int ans;
int main(){
    cin>>a;
    int n = strlen(a);
    for(int i=1; i<=n-1; i++){//归类
        k[gcd(i, n)]++;
    }
    
    for(int i=1; i<=n-1; i++){
        if(k[i]==0)
            continue;
        
        for(int j=0; j<i; j++){//j是起点
            if(a[j] == 'P')
                continue;

            bool flag=true;
            for(int now=(j+i)%n; now != j; now=(now+i)%n){
                if(a[now]=='P'){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans += k[i];
                break;
            }
        }
    }
    cout<<ans;
	return 0;
}
