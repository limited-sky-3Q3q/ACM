/**
 * TODO Auther: by SR
 * Date: 2020-01-24 17:02:01
 * LastEditTime: 2020-02-14 12:00:10
 * ! 今日运势: 吉，无bug
 * *石子合并问题
 * TODO 这里用平行四边形进行了优化,优化后的时间复杂度为//!o(N^2)
 * *先用线型熟悉下定理
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
#define INF 0x3f3f3f3f 
using namespace std;

int solute();
int que[102],n,ans[102][102]={0},sum[102]={0};
int best_coordinate[102][102]={0};//!用于标记最优点的下标

int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> que[i];
    }
    
    
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + que[i];
    }
    memset(ans, INF, sizeof(ans));//求最小值，要先值为无穷大，//?要在答案边界初始化之前
    for(int i = 1; i <= n; i++){
        best_coordinate[i][i] = i;//坐标边界初始化
        ans[i][i] = 0;//答案边界初始化
    }

    cout<< solute();
    
    cout << "\n";
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cout << best_coordinate[i][j]<<" ";
        }
        cout <<"\n";
    }
    cout << "\n";
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(ans[i][j] != INF){
                cout <<"         "<< ans[i][j]<<" ";  
            }
            else{
                cout << ans[i][j]<<" ";
            }

        }
        cout <<"\n";
    }
    
    
	return 0;
}

int solute(){
    for(int i = n; i >= 1; i--){
        for(int j = i + 1; j <= n; j++){
            int temp = sum[j] - sum[i-1];
            if(!best_coordinate[i][j-1]){
                best_coordinate[i][j-1] = i;
            }
            if(!best_coordinate[i+1][j]){
                best_coordinate[i+1][j] = j-1;
            }
            for(int k = best_coordinate[i][j-1]; k <= best_coordinate[i+1][j]; k++){
                if(ans[i][k]+ans[k+1][j]+temp < ans[i][j]){
                    ans[i][j] = ans[i][k]+ans[k+1][j]+temp;
                    best_coordinate[i][j] = k;
                }
            }
        }
    }
    return ans[1][n];
}