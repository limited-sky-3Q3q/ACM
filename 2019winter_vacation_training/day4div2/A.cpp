/*
 * @Auther: by SR
 * @Date: 2020-01-13 15:34:50
 * @LastEditTime : 2020-01-13 15:51:40
 */
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int a[4] ={0,0,0,1};
        for(int i = 1; i < n;i++)
        {
            a[3] += a[2];
            a[2] = a[1];
            a[1] = a[0];
            a[0] = a[3];
        }
        if(!n)return 0;
        cout<<a[0]+a[1]+a[2]+a[3]<<"\n";
    }
    return 0;
}