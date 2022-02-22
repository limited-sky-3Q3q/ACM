/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\test.cpp
 * Date: 2020-02-11 10:35:00
 * LastEditTime: 2020-02-14 11:42:20
 * ! 浠婃棩杩愬娍: 鍚夛紝鏃燽ug
 * https://www.luogu.com.cn/problem/P1144
 * 绠€鍗曟渶鐭�璺�
**/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int mod = 100003;
const int MAXM = 2e6+10;
const int MAXN = 1e6+10;

vector<int>to[MAXN];
ll dep[MAXN], cnt[MAXN];
bool vis[MAXN];

int main(){
	int n, m, x, y;
    //read
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d%d", &x, &y);
        to[x].push_back(y);
        to[y].push_back(x);
    }
    //init
    queue<int>Q;
    Q.push(1);
    dep[1]=0;cnt[1]=1;vis[1]=true;
    //solve
    while(!Q.empty()){
        int now=Q.front();
        Q.pop();
        for(int i=0; i<to[now].size(); i++){
            int x = to[now][i];
            if(!vis[x]){
                vis[x]=true;
                dep[x]=dep[now]+1;
                Q.push(x);
            }
            //*娉ㄦ剰涓嬮潰鐨勫啓娉�
            //鎶婃槸鍚﹁揪鍒拌繃璇ョ偣鍜屽埌杈炬�℃暟鍒嗗紑瀛樻斁锛岀缉鐭�浜嗗緢澶х殑鏃堕棿
            if(dep[x] == dep[now]+1){
                cnt[x] = (cnt[now]+cnt[x])%mod;//!
                //Q.push(x);
            }
        }
    }
    for(int i=1; i<=n; i++){
        printf("%lld\n", cnt[i]);
    }
	return 0;
}


