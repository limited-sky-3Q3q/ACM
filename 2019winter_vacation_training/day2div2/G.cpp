/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day2div2\G.cpp
 * Date: 2020-02-10 10:41:54
 * LastEditTime: 2020-02-10 14:33:45
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<memory.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+5, MAXM = 1e4+4;

int line[MAXN][2], fa[MAXN];

int find(const int a){
    return fa[a]==a ? fa[a]:fa[a] = find(fa[a]);
}

int n,m;

int main(){
	int ans[MAXN];//刚才数组开小了，Runtime Error
    while(~scanf("%d%d", &n, &m)){
        
        for(int i = 0; i < n; i++){
            fa[i] = i;
        }

        for(int i = 0; i < m; i++){
            scanf("%d%d",&line[i][0], &line[i][1]);
        }
        
        int cnt = n;
        int a, b;
        for(int i = m-1; i >= 0; i--){
            //cout<<cnt<<"\n";
            ans[i] = cnt;
            a = find(line[i][0]);
            b = find(line[i][1]);
            if(a != b){
                cnt--;
                fa[a] = b;
            }//以后还是老老实实写函数吧。..
        }
        
        for(int i = 0; i < m; i++){
            printf("%d\n", ans[i]);
        }
    }
    
	return 0;
}