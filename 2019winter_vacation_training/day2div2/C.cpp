/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day2div2\C.cpp
 * Date: 2020-02-07 17:49:49
 * LastEditTime: 2020-02-08 22:25:03
 * ! 今日运势: 吉，无bug
 * *试着用cin.tie 和解绑来加速cincout , 加速后358，没加速前483，但用scanfprintf的话296。。。。
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
#include<vector>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

void update();
int bs(const int l,const int r);

vector<int>num;
int cnt = 0, now;
int main(){
    int n,k;
    char q;
    while(cin>>n>>k){
        cnt = 0;
        num.clear();
        num.push_back(-INF);
        
        for(register int i = 0; i < n; i++){
            cin>>q;
            if(q == 'I'){
                cin>>now;
                //scanf("%d", &now);
                update();
            }
            else{
                cout<<num[k-1]<<"\n";
                //printf("%d\n", num[k-1]);
            }
            /*
            for(int i = 0; i < cnt; i++){
                cout<<num[i]<<" ";
            }
            cout<<"\n";*/
        }
    }
	return 0;
}

void update(){
    int pos = bs(0, cnt++);
    num.insert(num.begin()+pos, now);
}

int bs(const int l,const int r){
    if(l == r){
        return l;
    }
    int mid = l + ((r - l)>>1);
    
    if(now > num[mid]){
        return bs(l, mid);
    }
    else{
        return bs(mid+1,r);
    }
    
}