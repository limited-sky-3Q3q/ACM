/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\temp\E.cpp
 * Date: 2020-03-01 14:13:59
 * LastEditTime: 2020-03-01 14:43:06
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;

char str[2][200005],temp[2][200005];

bool check(int l, int r){
    for(int k=0; l+k<=r; k++){
        if(str[0][l+k]==str[1][r-k]){
            continue;
        }
        return false;
    }
    return true;
}

int main(){
	cin>>str[0]>>str[1];
    if(strlen(str[0])!=strlen(str[1])){
        cout<<"NO";
    }
    int cnt=0;
    char a,b,c,d;
    for(int i=strlen(str[0])-1; i>=0; i--){
        if(str[0][i]!=str[1][i]){//r
            for(int j=0; j<i; j++){
                if(str[0][j]!=str[1][j]){//l
                    if(check(j,i)){
                        cout<<"YES";
                        return 0;
                    }
                    cout<<"NO";
                    return 0;                  
                }
            }
            
        }
    }
    cout<<"YES";
    return 0;
}
