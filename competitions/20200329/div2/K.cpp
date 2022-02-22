/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200329\div2\K.cpp
 * Date: 2020-03-30 21:45:34
 * LastEditTime: 2020-03-30 22:17:58
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
char que[2][MAXN]={0};

char dif[2][MAXN];

int main(){
	int T,n,cnt=0;
    cin>>T;
    while(cin>>n){
        memset(que, 0, sizeof que);
        cnt=0;//init

        cin>>que[0]>>que[1];//read
        for(int i=0; i<n; i++){
            if(que[0][i] != que[1][i]){
                dif[0][cnt] = que[0][i];
                dif[1][cnt++] = que[1][i];
            }
        }
        
        if(cnt==0){
            cout<<"YES\n";
            continue;
        }
        
        
        bool flag=true;//solve
        for(int i=1; i<cnt; i++){//a转
            if(dif[0][i] != dif[1][i-1]){
                flag=false;
            }
        }
        if(dif[0][0] != dif[1][cnt-1]){
            flag=false;
        }
        if(flag){
            cout<<"YES\n";
            continue;
        }
        
        flag=true;
        for(int i=1; i<cnt; i++){//b转
            if(dif[1][i] != dif[0][i-1]){
                flag=false;
            }
        }
        if(dif[1][0] != dif[0][cnt-1]){
            flag=false;
        }
        if(flag){
            cout<<"YES\n";
            continue;
        }
        else{
            cout<<"NO\n";
            continue;
        }

    }
	return 0;
}
