/**
 * TODO Auther: by SR
 * Date: 2020-01-24 17:02:01
 * LastEditTime: 2020-01-27 15:26:22
 * ! 今日运势: 吉，无bug
 * *石子合并问题
 * TODO 先用思路最直接的递归算法
 * ?这里石子呈一条直线
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

int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> que[i];
    }
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + que[i];
    }
    memset(ans, INF, sizeof(ans));//求最大值，要先值为无穷大
    for(int i = 0; i <= n; i++){
        ans[i][i] = 0;//边界需要初始化为0
    }
    cout<< solute();
    
	return 0;
}

int solute(){//?时间复杂度为o(N^3)
    for(int v = 1; v <= n; v++){//计算相邻的v个区间合并的最小值，需要从小到大
        for(int i = 1; i <= n-v; i++){//从ans[1][2]开始
            int j = i + v;
            int temp = sum[j] - (i > 0 ? sum[i-1]:0);
            for(int k = i; k < j; k++){
                ans[i][j] = min(ans[i][j], ans[i][k]+ans[k+1][j]+temp);
            }
   
        }
    }

    
    return ans[1][n];
}