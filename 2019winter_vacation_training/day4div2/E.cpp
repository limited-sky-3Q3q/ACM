/**
 * TODO Auther: by SR
 * Date: 2020-01-21 15:00:18
 * LastEditTime: 2020-01-24 16:54:09
 * ! 今日运势: 吉，无bug
 * ?01背包问题
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

#define maxn 1003

void min_bag();

int dp[maxn] = {0};//! 不用二维数组
int value[maxn],volume[maxn] = {0};
int T,N,V;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> V;
        for(int i = 0; i <= V; i++){
            dp[i] = 0;
        }
        
        for(int i = 1; i <= N; i++){
            cin >> value[i];
        }     
        for(int i = 1; i <= N; i++){
            cin >> volume[i];
        }

        min_bag();
    }
	return 0;
}

void min_bag(){
    //for(int i = 0; i <= V; i++){cout << dp[i]<<" ";}
    //cout << "\n";
    
    for(int i = 1; i <= N; i++){
        for(int j = V; j >= volume[i]; j--){
            dp[j] = max(dp[j -volume[i]] + value[i], dp[j]);//!注意这里是反过来遍历的
        }
        /*
        for(int j = 0; j <= V; j++){
            cout << dp[j] << " ";
        }
        cout << "\n";*/
    }
    
    int large = 0;
    for(int i = 1; i <= V; i++){
        if(dp[i] > large)large = dp[i];
    }
    cout << large << "\n";
    return;
}