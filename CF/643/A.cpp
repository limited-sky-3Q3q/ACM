/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\CF\643\A.cpp
 * Date: 2020-05-16 19:44:34
 * LastEditTime: 2020-05-17 10:14:19
 * !��������: ������bug
 * ���޴ε�ѭ��������0λ��֮�����0*n ������һֱ���ֲ���
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
//using ll = long long;

ll getAdd(ll x){//�ú�ѧѧ
    ll a=10, b=0;
    while(x>0){
        ll y = x % 10;
        x /= 10;
        a = min(a, y);
        b = max(b, y);
    }

    return a*b;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x, k;
        cin>>x>>k;
        //k--;
        while(--k){
            ll y = getAdd(x);
            if(y == 0) break;
            x += y;
        }
        cout<<x<<"\n";
    }
    
	return 0;
}


