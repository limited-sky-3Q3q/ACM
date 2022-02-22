/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200329\I.cpp
 * Date: 2020-03-29 15:20:02
 * LastEditTime: 2020-03-29 18:24:34
 * !今日运势: 吉，无bug
 * ?20行代码就能解决？？？！！！
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
const int MAXM=2e5+10;

int up[MAXN],down[MAXN],d[MAXN];
int x[MAXM],y[MAXM];

int main(){
	int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        scanf("%d%d",&x[i],&y[i]);
        up[x[i]]++;
        down[y[i]]++;
        d[x[i]]++;d[y[i]]--;
    }
    for(int i=1; i<MAXN; i++){
        up[i]+=up[i-1];
        down[i]+=down[i-1];
        d[i]+=d[i-1];
    }
    int ans1=0,ans2=0;
    for(int i=1; i<=n; i++){
        /************************************************
        什么情况需要的座位最多？乘客上来时都没有位置时最多。。
        所以最大值为各个变化前车上总人数加上变化时车上增加的人数总量中的最大值
        ************************************************/
        ans1=max(ans1, up[y[i]-1]-down[x[i]]);//最坏情况
        ans2=max(ans2, d[x[i]]);
    }
    printf("%d %d", ans1, ans2);
	return 0;
}
