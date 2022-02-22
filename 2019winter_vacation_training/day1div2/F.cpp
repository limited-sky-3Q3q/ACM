/**
 * TODO Auther: by SR
 * Date: 2020-02-03 16:05:59
 * LastEditTime: 2020-02-03 17:10:30
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
#include<iomanip>
using namespace std;
typedef long long ll;
const int MAXN = 10004;
double solve(double, double);
bool check(double);

double que[MAXN];
int request, n;
int main(){
    cin>>n>>request;
    for(register int i = 1; i <= n; i++){
        cin >> que[i];
    }
    double upper = 0;
    for(register int i = 1; i <= n; i++){
        upper += que[i];
    }
    upper /= request;

    double ans = solve(0.00, upper);
    ans = floor(ans*100)/100.0;//TODO 不进行四舍五入
    printf("%.2lf", ans);
	return 0;
}

double solve(double l, double r){
    //cout <<l <<" "<<r<<"\n";
    if(abs(r-l) < 1e-10){
        return r;
    }

    double mid = l + (r - l)/2.0;
    if(check(mid)){
        return solve(mid, r);
    }
    else{
        return solve(l, mid);
    }
}

bool check(double now){
    int sum = 0;
    for(register int i = 1; i <= n; i++){
        sum += int(que[i]/now);
    }
    //cout <<"sum == "<<sum<<"\n";
    if(sum >= request){
        return true;
    }
    else{
        return false;
    }
}