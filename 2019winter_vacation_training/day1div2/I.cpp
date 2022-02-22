/**
 * TODO Auther: by SR
 * Date: 2020-02-04 15:05:32
 * LastEditTime: 2020-02-04 17:57:58
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
using namespace std;
typedef long long ll;
int n, k,ans;
bool row[10],x[10];
int board[10][10];
void dfs(const int, const int);
void solve(int, int);
int main(){
    while(cin>>n>>k){
        if(n==-1 && k==-1){
            break;
        }
        //memset(row, 1, sizeof(row));
        char ctemp;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >>ctemp;
                if(ctemp == '#'){
                    board[i][j] = 0;
                }
                else{
                    board[i][j] = -1;
                }
            }
        }
        ans = 0;
        for(int i = 0; i <10;i++){//初始化
            row[i] = true;
            x[i] = false;
        }
        solve(0, 1);
        cout<<ans<<"\n";
    }
	return 0;
}

void dfs(const int l_pos, const int counter){//重构一遍后就对了
    if(counter == k){//两个判断的顺序不能颠倒，//?第一种情况里可能存在 l_pos == n+1的情况
        ans++;//每次到这里时就枚举到了一种可行的选择
        return;
    }
    if(l_pos > n){//当counter < k时递归到尽头，说明不存在可行的选择
        return;
    }
    if(x[l_pos] == false){
        dfs(l_pos+1,counter);
    }
    else{
        for(int i = 1; i <= n; i++){
            if(board[l_pos][i] == 0 && row[i] == true){
                row[i] = false;
                dfs(l_pos+1, counter+1);
                row[i] = true;
            }
        }
    }
    return;
}

void solve(const int counter, const int l){
    if(l > n+1){
        return;
    }
    if(counter >= k){
        int pos;//找出左值
        for(int i = 1; i <= n; i++){
            if(x[i]){
                pos = i;
                break;
            }
        }
        dfs(pos, 0);
        return;
    }
    for(register int i = l; i <= n; i++){
        x[i] = true;
        solve(counter+1, i+1);
        x[i] = false;
    }

}