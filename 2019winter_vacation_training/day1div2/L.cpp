/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day1div2\L.cpp
 * Date: 2020-02-05 16:26:25
 * LastEditTime: 2020-02-23 13:05:05
 * ! 今日运势: 吉，无bug
 * *这题有多组数据。。但题目没说
 * 用bfs做，不过原来每一次递归都遍历一遍ans，直接TLE了
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
#include<queue>
using namespace std;
typedef long long ll;
const int  INF = 0x3f3f3f3f, MAXN = 100000;

int ans[MAXN + 10] = {0};//TODO边界没有问题，ans[MAXN*2 + 10] 也可以A
void bfs(int);

int k, n;
int main(){
    
    while(cin>>n>>k){
        memset(ans, 0, sizeof(ans));
        bfs(n);
        cout <<ans[k]-1<<"\n";
    }
	return 0;
}

void bfs(const int n){
    queue<int>Q;
    Q.push(n);
    ans[n] = 1;
    while(!Q.empty()){
        int now = Q.front();
        if(now == k){
            break;
        }
        Q.pop();
        if(now > 0 && ans[now-1] == 0){
            ans[now-1] = ans[now] + 1;
            Q.push(now-1);
        }
        if(now <= MAXN && ans[now+1] == 0){
            ans[now+1] = ans[now] + 1;
            Q.push(now+1);
        }
        if(now*2 <= MAXN && ans[now*2] == 0){
            ans[now*2] = ans[now] + 1;
            Q.push(now*2);
        }
    }
    return;
}
