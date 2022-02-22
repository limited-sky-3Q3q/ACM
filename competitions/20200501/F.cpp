/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200501\F.cpp
 * Date: 2020-05-01 16:28:31
 * LastEditTime: 2020-05-01 17:54:32
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<iomanip>
using namespace std;
typedef long long ll;
double dp[500][500]={0};//翻转i次后有j个朝上的概率
int main(){
    int n, k;
    dp[0][0]=1;
    cin>>n>>k;
    cout<<setprecision(7)<<fixed;
    if(n >= k){
        cout<<double(k)*0.5;
    }
    else{
        /*
        ///另一种思路
        for(int i=1; i<=k; i++){
            //dp[i][0] += dp[i-1][0]/2 + dp[i-1][1]/2;
            for(int j=0; j<n; j++){
                //dp[i][j] += dp[i-1][j]/2 + dp[i-1][j+1]/2 + dp[i-1][j-1]/2;
                dp[i][j] += dp[i-1][j]/2;
                dp[i][j+1] += dp[i-1][j]/2;
            }
            //dp[i][n] += dp[i-1][n]/2 + dp[i-1][n-1]/2;
            dp[i][n] += dp[i-1][n]/2;
            dp[i][n-1] += dp[i-1][n]/2;
        }
        double ans=0;
        for(int i=1; i<=n; i++){
            ans += 1.0*i*dp[k][i];
        }
        */
        for(int i=1; i<=k; i++){
            dp[i][0] = dp[i-1][0]/2;
            for(int j=1; j<n-1; j++){
                dp[i][j] = dp[i-1][j-1]/2 + dp[i-1][j]/2;
            }
            dp[i][n-1] = dp[i-1][n-2]/2 + dp[i-1][n-1]/2 + dp[i-1][n]/2;
            dp[i][n] = dp[i-1][n-1]/2 + dp[i-1][n]/2;
        }
        double ans=0;
        for(int i=1; i<=n; i++){
            ans += 1.0*i*dp[k][i];
        }
        cout<<ans;
    }
	
	return 0;
}
