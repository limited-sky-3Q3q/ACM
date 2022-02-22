/**
 * TODO Auther: by SR
 * Date: 2020-01-24 17:02:01
 * LastEditTime: 2020-01-28 21:34:52
 * ! 今日运势: 吉，无bug
 * *石子合并问题，环状，用了四边形不等式进行优化
 * ?时间复杂度为o(N^2)
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
#define INF 0x3f3f3f3f 
#define MAXN 1003
using namespace std;

void solute();
int que[MAXN*2], ans[MAXN*2][MAXN*2]={0}, sum[MAXN*2]={0}, n;
int best_coordinate[MAXN*2][MAXN*2]={0};//!用于标记最优点的下标


int main(){

    
    cin >> n;
    for(register int i = 1; i <= n; i++){
		cin >> que[i];
    }
    
    //初始化
    for(register int i = 1; i <= n-1; i++){
        que[i+n] = que[i];
    }
    sum[0] = 0;
    int less = INF;
    for(register int i = 1; i <= n*2-1; i++){
        sum[i] = sum[i-1] + que[i];
    }
    memset(ans, INF, sizeof(ans));
    memset(best_coordinate,0,sizeof(best_coordinate));
    for(int i = 1; i <= n*2; i++){
        ans[i][i] = 0;
        best_coordinate[i][i] = i;
    }

    //!注意虽然要枚举n个分隔点的情况，但整个ans数组只用记录一次就行!
    solute();
        
    for(register int i = 1; i <= n; i++){//选出最小值
        less = min(less, ans[i][i+n-1]);
    }
    cout<< less;
    
    /*
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
    */
	return 0;
}

void solute(){
    for(register int i = n*2-1; i >= 1; i--){//i从大到小
        for(register int j = i + 1; j <= n*2-1; j++){//j从小到大
            if(!best_coordinate[i][j-1]){
                best_coordinate[i][j-1] = i;//min(i+1, j-1)
            }
            if(!best_coordinate[i+1][j]){
                best_coordinate[i+1][j] = j-1;
            }
            
            int temp = sum[j] - sum[i-1];
            for(int k = best_coordinate[i][j-1]; k <= best_coordinate[i+1][j]; k++){
                if(ans[i][k] + ans[k+1][j] + temp < ans[i][j]){
                    ans[i][j] = ans[i][k] + ans[k+1][j] + temp;
                    best_coordinate[i][j] = k;
                }
            }
        }
            
    }
    return;
}