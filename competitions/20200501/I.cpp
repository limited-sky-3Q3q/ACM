/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200501\I.cpp
 * Date: 2020-05-01 12:50:58
 * LastEditTime: 2020-05-01 12:55:11
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

    int n,que[20],length;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>que[i];
	cin>>length;
    
    int ans,MIN=0x3f3f3f3f;
    for(int i=0; i<n; i++){
        (length%que[i]<MIN)?(ans=que[i], MIN=length%que[i]):1;
    }
    cout<<ans;

	//cout<<"\n";
	//system("pause");
	return 0;
}
