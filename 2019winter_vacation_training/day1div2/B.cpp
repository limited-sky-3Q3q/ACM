/**
 * TODO Auther: by SR
 * Date: 2020-02-02 15:44:05
 * LastEditTime: 2020-02-02 17:14:54
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

double mininum();
double third_search(double, double, double, double);
double f(double);
ll y;
int main(){

    int T;
    cin >> T;
    while(T--){
        cin >> y;
        cout <<setiosflags(ios::fixed)<<setprecision(4)<< mininum()<<"\n";
    }
	return 0;
}

double f(double x){//F(x) = 6 * x^7 + 8*x^6 + 7*x^3 + 5*x^2 - y *x
    return  6*pow(x, 7) + 8*pow(x, 6) + 7*pow(x,3) + 5*pow(x, 2) - y*x;
}

double third_search(double l, double lmid, double rmid, double r){
    if(abs(r - l) <= 0.00000000001){
        return f(rmid);
    }

    if(f(lmid) > f(rmid)){
        l = lmid;
        lmid = l + (r - l)*1/3.0;
        rmid = l + (r - l)*2/3.0;
        return third_search(l, lmid, rmid, r);
    }
    else{
        r = rmid;
        lmid = l + (r - l)*1/3.0;
        rmid = l + (r - l)*2/3.0;
        return third_search(l, lmid, rmid, r);
    }
}

double mininum(){
    return third_search(0, (0+100)*1/3.0, (0+100)*2/3.0, 100);
}
