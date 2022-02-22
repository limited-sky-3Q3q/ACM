

/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200315\H.cpp
 * Date: 2020-03-15 12:45:41
 * LastEditTime: 2020-03-15 13:08:34
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<iomanip>
using namespace std;
typedef long long ll;
int p[100];
void manacher(char* s,int n){ 
	int mx = 0, id = 0;//初始化都是0
	 for(int i = 1;i<=n;++i){
		if(i<mx) 
            p[i] = in(mx - i , p[2 * id - i]);
		else
            p[i] = 1;//对应刚刚的三情况

		while( s[i-p[i]] == s[i+p[i]])//更新p[i]的半径
            ++p[i]; 

		if(i+p[i] > mx){ 
            mx = i + p[i]; id = i; 
        } //更新
	 }
 }



int main(){
	//cout<<log(1.0l/26,9000000000000000000);
    //cout<<log(10);
    //cout<<log(18000000000000000000ull)/log(26);
    
	return 0;
}
