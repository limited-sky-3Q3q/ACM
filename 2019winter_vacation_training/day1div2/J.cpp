/**
 * TODO Auther: by SR
 * Date: 2020-02-04 19:42:44
 * LastEditTime: 2020-02-05 12:42:49
 * ! 今日运势: 吉，无bug
 * *dfs正着求就TLE。。反过来求就A了。。。
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
using namespace std;
typedef long long ll;

bool flag = false;
int board[10][10] = {0};

void read();
void solve();
void output();
void dfs(int);
bool check(int, int);

int main(){
	int T;
    cin>>T;
    while(T--){
        flag = false;
        read();
        dfs(81);
        output();
    }
	return 0;
}
void output(){
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            cout <<board[i][j];
        }
        cout << "\n";
    }
}

void read(){
    char temp[10];
    for(register int i = 1; i <= 9; i++){
        cin>>temp;
        for(register int j = 1; j <= 9; j++){
            board[i][j] = temp[j-1] - '0';
        }
    }
}

void dfs(int n){
    if(n < 1){
        flag = true;
        return;
    }
    
    int x = (n-1)/9 + 1, y = (n-1)%9 + 1;
    if(board[x][y] != 0){
        dfs(n-1);
    }
    else{
        for(register int i = 1; i <= 9; i++){
            if(check(n, i) == true){
                board[x][y] = i;
                dfs(n-1);
                if(flag == true){
                    return;
                }
                board[x][y] = 0;
            }
        }
    }

}

bool check(int now, int val){
    int x = (now - 1)/9 + 1, y = (now - 1)%9 + 1;
    for(register int i = 1; i <= 9; i++){
        if(board[x][i] == val){
            return false;
        }
        if(board[i][y] == val){
            return false;
        }
    }
   for(register int i = 3*((x-1)/3)+1; i <= 3*((x-1)/3)+3; i++){
       for(register int j = 3*((y-1)/3)+1; j <= 3*((y-1)/3)+3; j++){
           if(board[i][j] == val){
               return false;
           }
       }
   }
   return true;
}