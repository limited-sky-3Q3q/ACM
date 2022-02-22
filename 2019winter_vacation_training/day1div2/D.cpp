/**
 * TODO Auther: by SR
 * Date: 2020-01-10 14:57:16
 * LastEditTime: 2020-02-03 15:07:29
 * ! 今日运势: 吉，无bug
 * *刚开始想太复杂了，其实并不用考虑那么多的分支情况
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
using namespace std;
typedef long long ll;
const int MAXN = 2003;

char s[MAXN], ans[MAXN] = {0};
int solve(int, int);

int n;
int main(){
	cin >> n;
    for(register int i = 1; i <= n; i++){
        cin >> s[i];
    }
    int l = 1, r = n, temp;

    
    for(register int i = 1; i <= n; i++){
        temp = solve(l ,r);//solve函数找出应该加左值还是加右值
        if(temp == -1){
            ans[i] = s[l++];
        }
        else{
            ans[i] = s[r--];
        }
    }
    int cnt = 0;
    for(register int i = 1; i <= n; i++){
        cout << ans[i];
        if(++cnt % 80 == 0){
            cout << "\n";
        }
    }
	return 0;
}

int solve(int l, int r){
    if(l >= r){
        return -1;
    }

    if(s[l] > s[r]){
        return 1;
    }
    else if(s[l] < s[r]){
        return -1;
    }
    //s[l] == s[r]
    return solve(l+1, r-1);

}