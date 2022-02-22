/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day1div2\L.cpp
 * Date: 2020-02-05 16:26:25
 * LastEditTime: 2020-02-05 19:20:32
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
const int  INF = 0x3f3f3f3f, MAXN = 100000;

int ans[MAXN+10] = {0};
void bfs(int);
void update(const int now, const int counter);

int k, n;
int main(){

    cin>>n>>k;
    memset(ans, 0, sizeof(ans));
    ans[n] = 1;
    bfs(1);
    /*
    for(int i = 0; i <= 50; i++){
        cout << ans[i]<<" ";
    }cout<<endl;*/


    cout << (n==k ? 0:ans[k]-1);
    
	return 0;
}

void bfs(const int counter = 1){
    if(k == n){
        return;
    }
    if(ans[k] != 0){
        return;
    }
    for(register int i = 0; i <= MAXN; i++){
        if(ans[i] == counter){
            update(i, counter);
        }
        if(ans[k] != 0){
            return;
        }
    }
    bfs(counter + 1);
    return;
}
 
 void update(const int now, const int counter){
     if(now != 0){
         if(ans[now-1] == 0){
             ans[now-1] = counter + 1;
         }
     }
     if(now != MAXN){
         if(ans[now+1] == 0){
             ans[now+1] = counter + 1;
         }
     }
     if(now*2 <= MAXN){
         if(ans[now*2] == 0){
             ans[now*2] = counter + 1;
         }
     }
    /*
     for(int i = 0; i <= 50; i++){
        cout << ans[i]<<" ";
    }cout<<endl;*/

     return;
 }