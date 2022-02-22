/**
 * TODO Auther: by SR
 * Date: 2020-01-23 22:40:19
 * LastEditTime: 2020-01-24 13:52:50
 * ! 今日运势: 吉，无bug
 * ?多重背包问题
 * *求最大值
 * *这里是最朴素的求法
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
using namespace std;

struct rice{
    int p,h,c;
}a[2004];

void multiple_bag();
void split(int);

int ans[102];
int C,money,m,num;

int main(){
    cin >> C;
    while(C--){
        ans[0] = 0, num = 0;
        memset(ans,0,sizeof(ans));
        cin >> money >> m;
        for(int i = 1; i <= m; i++){
            cin>>a[i].p>>a[i].h>>a[i].c;
            split(i);
        }
        multiple_bag();
    }
	return 0;
}

void split(int now){
    for(int i = 2; i <= a[now].c; i++){
        a[m+(++num)] = a[now];
    }
}

void multiple_bag(){
    for(int i = 1; i <= m+num; i++){
        for(int j = money; j >= a[i].p; j--){
            ans[j] = max(ans[j], ans[j-a[i].p] + a[i].h);
        }
    }

    int large = 0;
    cout << ans[money] <<"\n";
    return;
}
