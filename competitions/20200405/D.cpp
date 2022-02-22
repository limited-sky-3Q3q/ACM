/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200405\D.cpp
 * Date: 2020-04-05 12:39:22
 * LastEditTime: 2020-04-05 13:15:13
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
	int R,C,ans=0;
    char map[600][600];
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>map[i][j];
        }
    }

    if(R==1 && C==1){
        cout<<0;
        return 0;
    }
    if(R==1 || C==1){
        ans=0;

        if(R==1){
            for(int i=1; i<C-1; i++){
                if(map[0][i]=='.')ans++;
            }
        }
        else{
            for(int i=1; i<R-1; i++){
                if(map[i][0]=='.')ans++;
            }
        }
        
        cout<<ans;
        return 0;
    }
    if(R==2 || C==2){
        ans=0;
        
        if(R==2){
            for(int i=1; i<C-1; i++){
                if(map[0][i]=='#')continue;
                if(map[1][i]=='#')continue;
                ans++;
            }
        }
        else{
            for(int i=1; i<R-1; i++){
                if(map[i][0]=='#')continue;
                if(map[i][1]=='#')continue;
                ans++;
            }
        }

        cout<<ans;
        return 0;
    }
    

    for(int i=1; i<R-1; i++){
        for(int j=1; j<C-1; j++){
            if(map[i][j]=='.')ans++;
        }
    }
    for(int i=0; i<R; i++){
        if(i==0 || i==R-1){
            for(int j=1; j<C-1; j++){
                if(map[i][j]=='#'){
                    cout<<ans;
                    return 0;
                }
            }
        }
        else{
            if(map[i][0]=='#'){
                cout<<ans;
                return 0;
            }
            if(map[i][C-1]=='#'){
                cout<<ans;
                return 0;
            }
        }
    }
    
    ans++;
    cout<<ans;
	return 0;
}
