/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20201003\3.cpp
 * Date: 2020-10-05 20:32:39
 * LastEditTime: 2020-10-05 20:53:54
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
int t,n;
double x[3], y[3],a,b,len;
int main(){
    cin>>t;
    cout<<setprecision(7)<<setiosflags(ios::fixed);
    while(t--){
        cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2];

        cin>>n;
        for(int i=0; i<n; i++){
            len = 1e250;
            cin>>a>>b;
            if((a-x[0])*(x[1]-x[0]) + (b-y[0])*(y[1]-y[0]) > 0){//同向
                double k = (y[1]-y[0])/(x[1]-x[0]);
                len = min(len, abs(k*a - b + y[0] - k*x[0])/pow(k*k + 1, 0.5));
            }
            else{
                len = min(len, pow((a-x[0])*(a-x[0]) + (b-y[0])*(b-y[0]), 0.5));
            }

            if((a-x[0])*(x[2]-x[0]) + (b-y[0])*(y[2]-y[0]) > 0){//同向
                double k = (y[2]-y[0])/(x[2]-x[0]);
                len = min(len, abs(k*a - b + y[0] - k*x[0])/pow(k*k + 1, 0.5));
            }
            else{
                len = min(len, pow((a-x[0])*(a-x[0]) + (b-y[0])*(b-y[0]), 0.5));
            }
            cout<<len<<'\n';
        }        
    }
	return 0;
}
