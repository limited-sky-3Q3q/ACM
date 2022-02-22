/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day1div2\M.cpp
 * Date: 2020-02-05 17:11:37
 * LastEditTime: 2020-02-06 18:46:00
 * ! 今日运势: 吉，无bug
 * 最优子集就是只有最大值大于平均值的最大子集{1,2,...,max} ,//?就是取最大值和最前面的n个数就行了
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
const int MAXN = 5e5;
const int INF = 0x3f3f3f3f;

void solve();
double count_average(const int right);

int cnt = 0, min_pos = 1;
double num[MAXN+10] = {0}, aver[MAXN+10] = {0};

int main(){
    int T,q;
    
    cin>>T;
    for(int i = 0; i <= T; i++){
            aver[i] = 0;
    }
    while(T--){
        bool flag = true;
        scanf("%d", &q);
        if(q==2){
            solve();
            continue;
        }
        else{
            scanf("%lf", &num[++cnt]);
            if(flag==true){
                flag = false;
                aver[1] = num[1];
            }
        }
    }
	return 0;
}

void solve(){
    int r = min_pos;
    double average = count_average(r), temp;
    while(r+1 <= cnt && num[r+1] <= (temp = count_average(r+1))){
        r++;
        average = temp;
    }
    min_pos = r;

    //cout<<"r == "<<r<<"cnt == "<<cnt<<"\n";

    printf("%.10lf\n", num[cnt] - average);
    return;
}

double count_average(const int right){
    if(aver[right] != 0){
        if(right == cnt){
            return aver[right];
        }
        else{
            return (aver[right]*double(right) + num[cnt]) / double(right+1);
        }
        
    }
    for(register int i = right; i >= 1; i--){
        if(aver[i] != 0){
            double average = aver[i] * i;
            for(register int j = i+1; j <= right; j++){
                average += num[j];
            }
            aver[right] = average / double(right);

            if(right == cnt){
            return aver[right];
            }
            else{
                return (aver[right]*double(right) + num[cnt]) / double(right+1);
            }
        }
    }
    
}