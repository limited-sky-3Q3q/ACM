/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\CF\643\D.cpp
 * Date: 2020-05-26 11:28:24
 * LastEditTime: 2020-05-26 12:04:18
 * !��������: ������bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
int N,S;
int main(){
    //ѡ��һ���Ӽ��޷���ʾ������K
    //�ж������ܷ��ʾ1��S��������
    cin>>N>>S;
    if(S-N+1 > N-1+1){
        cout<<"YES\n";
        for(int i=1; i<=N-1; i++){
            cout<<1<<' ';
        }
        cout<<S-N+1;
        cout<<'\n'<<S-N;
    }
    else{
        cout<<"NO";
    }
	return 0;
}
