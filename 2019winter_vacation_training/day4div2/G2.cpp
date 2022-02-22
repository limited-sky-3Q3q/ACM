/**
 * TODO Auther: by SR
 * Date: 2020-01-23 22:40:19
 * LastEditTime: 2020-01-24 14:53:51
 * ! 今日运势: 吉，无bug
 * ?多重背包问题
 * *求最大值
 * TODO 用二进制拆分进行优化
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
void binary_split(int);

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
            binary_split(i);
        }
        /*
        for(int i = 0; i <= m+num; i++){
            printf("%d: %d %d\n",i,a[i].p,a[i].h);
        }*/
        
        multiple_bag();
    }
	return 0;
}

void binary_split(const int now){
    int temp = 0,total = 0;
    do{
        a[m+(++num)].p = pow(2,temp)*a[now].p;
        a[m+num].h = pow(2,temp)*a[now].h;
        total += pow(2,temp);
        temp++;
    }while(a[now].c -total >= pow(2,temp));

    if(a[now].c-total){
        a[m+(++num)].p = (a[now].c - total)*a[now].p;
        a[m+num].h = (a[now].c - total)*a[now].h;
    }
}

void multiple_bag(){
    for(int i = m+1; i <= m+num; i++){
        for(int j = money; j >= a[i].p; j--){
            ans[j] = max(ans[j], ans[j-a[i].p] + a[i].h);
        }
    }
    
    int large = 0;
    cout << ans[money] <<"\n";
    return;
}