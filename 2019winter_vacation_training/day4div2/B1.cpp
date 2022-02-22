/*
 * @Auther: by SR
 * @Date: 2020-01-13 15:52:29
 * @LastEditTime : 2020-01-13 16:58:26
 */
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()// o(n^2)的解法
{
    int a[1002] = {0}, dp[10004] = {0};
    int n ;
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0 ; j < a[i] + 1 ; j++)
        {
            dp[a[i] + 1] = max(dp[a[i] + 1],dp[j] + 1);
        }
    }

    int L = 0;
    for(int i = 1;i <= 10000 + 1;i++)
    {
        L  = max(L,dp[i]);
    }
    cout << L;


    return 0;
}