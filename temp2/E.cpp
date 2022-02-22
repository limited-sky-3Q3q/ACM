/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\temp2\E.cpp
 * Date: 2020-03-08 13:34:20
 * LastEditTime: 2020-03-08 14:20:21
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

int main(){
	double r1,r2;
    const double pi=3.14159265358979323846;
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%lf%lf",&r1,&r2);
        double a=atan(r1/(r1+r2)),b=atan((r1+r2)/r1);
        printf("%lf\n",   (r1+r2)*sin(a)*(r1+r2)*cos(a)*0.5-r1*sin(b)*r1*cos(b)*0.5-(2*b-pi/2.0)*r1*r1*0.5-a*r2*r2*0.5 );
    }
	return 0;
}
