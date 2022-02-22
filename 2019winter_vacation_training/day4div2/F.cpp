/**
 * TODO Auther: by SR
 * Date: 2020-01-21 16:55:07
 * LastEditTime: 2020-01-24 10:33:06
 * ! 今日运势: 吉，无bug
 * ?完全背包问题
 * *这里是找最小值，不是找最大值。。
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
#define INF 0x3f3f3f3f
int ans[10004],P[50004],W[10004];
int n,weight;
void min_bag();
int main(){
	int T;
    cin >> T;
    while(T--){
        
        cin >> n >> weight;
        weight -= n;
        cin >> n;
        for(int j = 0; j <= weight; j++){//memset
            ans[j] = INF;
        }
        ans[0] = 0;//!注意是ans[0]要初始化为0，不是ans[1]要初始化为0。
        for(int i = 1; i <= n; i++){
            cin >> P[i] >> W[i];
        }
        min_bag();
    
    }
	return 0;
}

void min_bag(){
    for(int i = 1; i <= n; i++){
        for(int j = W[i]; j <= weight; j++){
            ans[j] = min(ans[j], ans[j - W[i]] + P[i]);//相比最大值问题，主要是把max改成min，还有上面的初始化。
        }//TODO 从小到大，只会更新W[i]的倍数位置的值，其他值依然为INF。
    }
    if(ans[weight] != INF){
        cout<<"The minimum amount of money in the piggy-bank is "<<ans[weight]<<"."<<"\n";//没错后面有个句号。
    }
    else{
        cout<<"This is impossible."<<"\n";
    }
}