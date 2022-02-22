/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200329\div2\A.cpp
 * Date: 2020-04-02 16:22:26
 * LastEditTime: 2020-04-02 17:02:29
 * !今日运势: 吉，无bug
 * *有点诡异
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
//int a,b;
int spe[2][10];
int main(){
	int T,a,b,lena,lenb,sign;
    cin>>T;
    while(T--){
        cin>>a>>b;
        lena=lenb=0;
        if((a>0&&b>0)||(a<<0&&b<0)){//同号
            sign=1;
        }
        else{
            sign=-1;
        }
        
        //a = abs(a); b = abs(b);
        while(a != 0){
            spe[0][lena] = a%10*pow(10, lena);
            lena++;
            a /= 10;
        }
        while(b != 0){
            spe[1][lenb] = b%10*pow(10, lenb);
            lenb++;
            b /= 10;
        }

        bool flag=false;
        //if(sign==1){//正
            for(int i=0; i<lena; i++){
                for(int j=0; j<lenb; j++){
                    if(spe[0][i]==0 || spe[1][j]==0){
                        continue;
                    }
                    if(!flag)flag=true;//第一次
                    else{
                        cout<<" + ";
                    }
                    cout<<spe[0][i]<<" x "<<spe[1][j];
                }
            }
        //}
        /*
        else{//负
            for(int i=0; i<lena; i++){
                for(int j=0; j<lenb; j++){
                    if(spe[0][i]==0 || spe[1][j]==0){
                        continue;
                    }
                    if(!flag){
                        flag=true;//第一次
                        //cout<<-spe[0][i]<<" x "<<spe[1][j];
                    }
                    else{
                        cout<<" - "<<spe[0][i]<<" x "<<spe[1][j];
                    }
                }
            }
        }
        */
        cout<<'\n';
    }
	return 0;
}
