/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200524\B.cpp
 * Date: 2020-05-24 17:53:27
 * LastEditTime: 2020-05-24 17:53:56
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

int main(){

	return 0;
}
const int maxn = 3e5 + 5;
 
int vis[maxn], a[maxn], c1[maxn], c2[maxn];
int n, m;
 
#define lowb(x) ((x)&(-(x)))
void update(int c[], int x, int v){
 
    while(x <= m) c[x] += v, x += lowb(x);
}
 
int query(int c[], int x){
 
    int ret = 0;
    while(x) ret += c[x], x -= lowb(x);
    return ret;
}
 
int main(){
 
    freopen("task.in", "r", stdin);
    int t; scanf("%d", &t);
    while(t--){
 
        scanf("%d", &n);
        m = 2 * n + 2;
        for(int i = 1; i <= n; ++i){
 
            scanf("%d", &a[i]);
            if(a[i] <= m) ++vis[a[i]];
            if(a[i] <= m && vis[a[i]] == 1) update(c1, a[i], 1);
            if(a[i] <= m) update(c2, a[i], 1);
        }
        int ret = n + 1;
        for(int i = 1; i <= m; ++i){
 
            int lcnt = query(c2, i), luni = query(c1, i);
            int tmp = (n - lcnt) + (i - luni) + (lcnt - luni);
            ret = min(ret, tmp);
        }
        printf("%d\n", ret);
        for(int i = 1; i <= n; ++i){
 
            if(a[i] <= m) --vis[a[i]];
            if(a[i] <= m && vis[a[i]] == 0) update(c1, a[i], -1);
            if(a[i] <= m) update(c2, a[i], -1);
        }
    }
    return 0;
}