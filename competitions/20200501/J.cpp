/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200501\J.cpp
 * Date: 2020-05-01 12:35:51
 * LastEditTime: 2020-05-01 12:42:58
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

int main(){
    int n,temp1;
    double ans=0,temp2;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp1;
        switch(temp1){
            case 0:ans+=2*16;break;
            case 1:ans+=1*16;break;
            case 2:ans+=8;break;
            case 4:ans+=4;break;
            case 8:ans+=2;break;
            case 16:ans+=1;break;
        }
    }
    cout<<setprecision(7)<<fixed;
	cout<<ans/16;
	//cout<<"\n";
	//system("pause");

	return 0;
}
