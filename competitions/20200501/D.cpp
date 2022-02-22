/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200501\D.cpp
 * Date: 2020-05-01 13:30:24
 * LastEditTime: 2020-05-01 13:56:51
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

int main(){
    char que[1003];
    int ans[2][10004];
    cin>>que;
    int len = strlen(que), ansLen=0;
    int MAX=0,pos;
	for(int i=0; i<len; i++){
        MAX=0;
        for(int j=0; j<len-i; j++){
            //MAX=max(int(que[i]), MAX);
            if(que[j]>=MAX){
                MAX = que[j];
                pos = j;
            }
        }

        if(pos==len-i-1)
            continue;
        
        int temp=que[pos];
        que[pos]=que[len-i-1];
        que[len-i-1]=temp;
        
        ans[0][ansLen] = len-i;//大
        ans[1][ansLen++] = pos+1;
    }
    for(int i=ansLen-1; i>=0; i--){
        cout<<ans[0][i]<<" "<<ans[1][i]<<"\n";
    }
	//cout<<"\n";
	
    //system("pause");


	return 0;
}
