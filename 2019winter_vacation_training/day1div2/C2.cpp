/**
 * TODO Auther: by SR
 * Date: 2020-02-02 19:05:21
 * LastEditTime: 2020-02-02 21:54:38
 * ! 今日运势: 吉，无bug
 * *要啥二分搜索？？？答案都可以直接算出来了，我个憨憨
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
using namespace std;
typedef long long ll;
const int MAXN = 1003;

int check(const int);

int R, n;
int X[MAXN];
int main(){
	while(cin>>R>>n){
        if(R == -1 && n == -1){
            break;
        }

        for(register int i = 1; i <= n; i++){
            cin >> X[i];
        }
        sort(X+1, X+n+1);X[n+1] = -1;
       cout << check(0)<<"\n";
    }
	return 0;
}

int longest(const int now){
    for(int pos = now; pos <= n; pos++){
        
        if(X[pos] - X[now] > R){
            return pos-1;
        }
        if(X[pos] == X[pos+1]){
            continue;
        }
    }
    return n;
}

int check(const int now){
    int a = now;
    int center;
    int left_bound = 1;
    int i = 1;
    while(i <= n){
        center = longest(left_bound);
        i = left_bound = longest(center)+1;
        a--;
    }
    return -a;
}

