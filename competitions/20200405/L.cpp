/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200405\L.cpp
 * Date: 2020-04-05 13:25:41
 * LastEditTime: 2020-04-05 16:16:07
 * !今日运势: 吉，无bug
 * qnmd二分搜索
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
ll K,que,temp,ans;
ll cnt=0;//除了头外有几个1
//char bit[100];
string bit;
/*
void bin(ll l, ll r){
    if(l+1 >= r){
        ll last=l;//剩余要移除的位数
        temp=que;
        ll pos=bit.length();
        if(last < cnt){//移除last个1
            for(int i=bit.length()-2; i>=0; i--){
                if(!last){//移除完了
                    if(temp <= K){
                        ans = l;
                        return;
                    }
                    else{
                        ans = r;
                        return;
                    }
                }
                if(temp&(1ll<<i)){//1
                    //que = que^(1ll<<i);
                    ll sub_temp=temp;
                    for(int j=i-1; j>=0; j--){
                        if(sub_temp&(1ll<<j))//1
                            sub_temp = sub_temp^(1ll<<j);
                    }
                    temp -= sub_temp;
                    sub_temp = sub_temp^(1ll<<i);
                    sub_temp = (sub_temp>>1);
                    temp += sub_temp;
                    last--;
                }
                if(!last){//移除完了
                    if(temp <= K){
                        ans = l;
                        return;
                    }
                    else{
                        ans = r;
                        return;
                    }
                }
            }
        }
        else{
            temp = (1ll<<(bit.length()-1));
            temp = (temp>>(last));
            if(temp <= K){
                ans = l;
                return;
            }
            else{
                ans = r;
                return;
            }
        }
    }
    
    ll mid= (l+r)/2;
    ll last=mid;//剩余要移除的位数
    temp=que;
    ll pos=bit.length();
    if(last < cnt){//移除last个1
        for(int i=bit.length()-2; i>=0; i--){
            if(!last){//移除完了
                if(temp <= K){
                    r=mid;
                    bin(l, r);
                    return;
                }
                else{
                    l=mid;
                    bin(l, r);
                    return;
                }
            }
            if(temp&(1ll<<i)){//1
                //que = que^(1ll<<i);
                ll sub_temp=temp;
                for(int j=i-1; j>=0; j--){
                    if(sub_temp&(1ll<<j))//1
                        sub_temp = sub_temp^(1ll<<j);
                }
                temp -= sub_temp;
                sub_temp = sub_temp^(1ll<<i);
                sub_temp = (sub_temp>>1);
                temp += sub_temp;
                last--;
            }
            if(!last){//移除完了
                if(temp <= K){
                    r=mid;
                    bin(l, r);
                    return;
                }
                else{
                    l=mid;
                    bin(l, r);
                    return;
                }
            }
        }
    }
    else{
        temp = (1ll<<(bit.length()-1));
        temp = (temp>>(last));
        if(temp <= K){
            r=mid;
            bin(l, r);
            return;
        }
        else{
            l=mid;
            bin(l, r);
            return;
        }
    }
    return;
*/
int main(){
    bit.clear();
    cin>>K>>bit;
    
    if(bit[0]=='-'){
        cout<<0;
        return 0;
    }
    
    temp=0;
    for(int i=bit.length()-1; i>=0; i--){
        //que += (bit[i]-'0')*pow(2, temp++);
        que += ll(bit[i]-'0')*(1ll<<(temp++));
    }
    if(que<=K){
        cout<<0;
        return 0;
    }

    temp=K;
    ll len=0;
    while(temp){
        len++;
        temp = (temp>>1);
    }
    temp = que;
    for(int i=0; i<bit.length()-1; i++){
        if(que&(1ll<<i))cnt++;//除了头位外1的个数
    }
    //bin(bit.length()-len, bit.length());
    ans=0;
    ll length=bit.length();
    bool flag=true;
    while(que>K){
        if(flag)
            for(int i=length-2; i>=0; i--){
                if(i==0)flag=false;
                if(que&(1ll<<i)){//1
                    temp=que;
                    for(int j=i-1; j>=0; j--){
                        if(temp&(1ll<<j))//1
                            temp = temp^(1ll<<j);
                    }
                    que -= temp;
                    temp = temp^(1ll<<i);
                    temp = (temp>>1);
                    que += temp;
                    ans++;
                    length--;
                    //if(i==0)flag=false;
                    break;
                }
                
            }
        else{
            que = (que>>1);
            ans++;
        }
    }
    cout<<ans;
	return 0;
}
