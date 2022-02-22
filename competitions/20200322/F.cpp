/******************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200322\F.cpp
 * Date: 2020-03-22 13:01:28
 * LastEditTime: 2020-03-22 13:57:43
 * !今日运势: 吉，无bug
******************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;
typedef long long ll;
int gcd(int a, int b){
    if(a==0)return b;
    else return gcd(b%a, a);
}
struct edge{
    int a,b,val;
}e[2000];
bool operator<(edge a, edge b){
        return a.val<b.val;
    }
priority_queue<edge>Q;
int que[1003];
int main(){
	int n;
    edge now;
    while(cin>>n){
        if(n==0)break;
        for(int i=0; i<n; i++){
            scanf("%d", &que[i]);
        }
        for(int i=0; i<=n-1; i++){//建边
            Q.push({que[i], que[(i+2)%n], gcd(que[i], que[(i+2)%n])});
        }
        
    }
    
	return 0;
}
