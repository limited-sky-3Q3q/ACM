/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200501\A.cpp
 * Date: 2020-05-01 14:20:47
 * LastEditTime: 2020-05-01 17:38:13
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;


ll dp[21][600]={0};
struct p{
    int T,r,s;
}que[21];
int main(){
    int n;
    ll MAXT=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>que[i].T>>que[i].r>>que[i].s;

        MAXT=max(int(MAXT), que[i].T);//*没错，days最大值为1258*MAXT 艹艹艹艹

        for(int j=0; j<que[i].T; j++){
            if(que[i].r>que[i].s){
                if(que[i].r<j || que[i].s>j)
                    dp[i][j]=1;
                else
                    dp[i][j]=0;
            }
            else{
                if(que[i].r<j && que[i].s>j)
                    dp[i][j]=1;
                else    
                    dp[i][j]=0;
            }
        }
    }
	int s=0;
    for(ll i=0; i<MAXT*1258; i++){//？？？
        s=0;
        for(int j=0; j<n; j++){
            s += dp[j][i%que[j].T];
        }
        if(s==0){
            cout<<i;
            return 0;
        }
    }
    cout<<"impossible";
	return 0;
}
