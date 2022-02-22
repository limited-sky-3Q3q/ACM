/**
 * TODO Auther: by SR
 * Date: 2020-02-02 19:05:21
 * LastEditTime: 2020-02-02 21:37:06
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
const int MAXN = 1003;

int mininum();
bool check(const int);
int binray_search(int, int);

int R, n;
int X[MAXN];
int main(){
	while(cin>>R>>n){
        if(R == -1 && n == -1){
            break;
        }

        for(register int i = 1; i <= n; i++){
            cin >> X[i];
        }
        sort(X+1, X+n+1);X[n+1] = -1;
        /*
        for(int i = 0 ; i <= n+2; i++){
            cout << X[i] << " ";
        }
        cout <<"\n";
        */
       //cout << check(0)<<"\n";
        cout << mininum()<<"\n";
    }
	return 0;
}

int longest(const int now){
    for(int pos = now; pos <= n; pos++){
        
        if(X[pos] - X[now] > R){
            return pos-1;
        }
        if(X[pos] == X[pos+1]){
            continue;
        }
    }
    return n;
}

bool check(const int now){
    int a = now;
    int center;
    int left_bound = 1;
    int i = 1;
    while(i <= n){
        center = longest(left_bound);
        i = left_bound = longest(center)+1;
        a--;
    }
    //return -a;
    if(a <= -1){
        return false;
    }
    else{
        return true;
    }
    
}

int binary_search(int l, int r){
    //cout <<l <<" "<<r<<"\n";
    if(l+1 >= r){
        if(check(l)){
            return l;
        }
        else{
            return r;
        }
    }

    int mid = l + ((r - l)>>1);
    
    if(check(mid)){
        return binary_search(l, mid);
    }
    else{
        return binary_search(mid, r);
    }
}

int mininum(){
    return binary_search(1, n);
}