/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200517\G.cpp
 * Date: 2020-05-17 13:37:25
 * LastEditTime: 2020-05-17 14:11:14
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
    ll n=0, temp,ans;
    ll t;
    while(cin>>t){
        temp = 1;
        ans = 0;
        int bit[64];
        memset(bit, 0, sizeof bit);
        
        ll cnt = 1;//t多少位
        while(temp < t){
            temp = (temp<<1);
            cnt++;
        }

        if(cnt>=4){
            ans += (cnt)*(cnt-1)*(cnt-2)/6;
            int a=-1,b=-1;

            for(int i=0; i<cnt; i++){
                if(t & (1ll<<i)){
                    bit[i]=1;
                }
            }

            for(int i=cnt-2; i>=0; i--){
                if(bit[i]){
                    a=i;
                    for(int j=i-1; j>=0; j--){
                        if(bit[j]){
                            b=j;
                            break;
                        }
                    }
                    break;
                }
            }
            if(a==-1){
                
            }else if(b==-1){

            }else{
                
            }


        }else if(cnt == 3){
            
        }else{
            ans = 0;
        }
        
        
    }
	return 0;
}
