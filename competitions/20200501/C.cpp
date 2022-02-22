/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200501\C.cpp
 * Date: 2020-05-01 13:10:56
 * LastEditTime: 2020-05-01 13:22:14
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
    string temp;
    int que[10];
    for(int i=0; i<10; i++)
        que[i]=0;
    int n,MAX=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp;
        if(temp=="red")
            que[1]++;
        else if(temp=="yellow")
            que[2]++,MAX=max(MAX, 2);
        else if(temp=="green")
            que[3]++,MAX=max(MAX, 3);
        else if(temp=="brown")
            que[4]++,MAX=max(MAX, 4);
        else if(temp=="blue")
            que[5]++,MAX=max(MAX, 5);
        else if(temp=="pink")
            que[6]++,MAX=max(MAX, 6);
        else if(temp=="black")
            que[7]++,MAX=max(MAX, 7);
    }

    int ans=0;
    if(MAX != 0){
        ans += que[1]*(MAX+1);
    }
    else{
        cout<<1;//system("pause");
        return 0;
    }
    for(int i=2; i<=7; i++)
        ans += que[i]*i;
	
    cout<<ans;
	//cout<<"\n";
	//system("pause");
	return 0;
}
