/**
 * TODO Auther: by SR
 * Date: 2020-01-29 10:42:55
 * LastEditTime: 2020-01-29 17:40:32
 * ! 今日运势: 吉，无bug
 * 数位DP
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

int solve(int);
void DP();

int ans[100][12] = {0},num[20] = {0};
int l,r;

int main(){
	DP();
    /*
	for(int i = 0; i <= 7; i++){
		for(int j = 0; j <= 9; j++){
			cout << ans[i][j] <<" ";
		}
		cout << "\n";
	}
	cout << solve(r) << " " << solve(l)<<"\n";
	*/
	while(cin >> l >> r){
		if(l == 0 && r == 0){
			break;
		}
		//cout <<solve(r) <<" "<< solve(l)<<"\n";
		
		cout <<solve(r+1) - solve(l)<<"\n";
	}
	return 0;
}

void DP(){
	ans[0][0] = 1;
	for(register int i = 1; i <= 9; i++){
		for(register int j = 0; j <= 9; j++){
			if(j == 4){
				ans[i][j] = 0;
			}
			else if(j == 6){
				for(register int k = 0; k <= 9; k++){
					ans[i][j] += (k == 2||k == 4)?0:ans[i-1][k];
				}
			}
			else{
				for(register int k = 0; k <= 9; k++){
					ans[i][j] += (k == 4)?0:ans[i-1][k];
				}
			}
		}
	}
	return;
}

int solve(int now){//TODO 主要错误的的地方！！！
	int sum = 0;
	int len = 0;
	while(now){
		num[++len] = now % 10;
		now = now / 10;
	}
	num[len + 1] = 0;
	for(register int i = len; i >= 1; i--){//从最高位到最低位
		for(register int j = 0; j < num[i]; j++){//从0到num[i]的前一个数
            //TODO 这个判断必须加上
            if(num[i+1] == 6 && j == 2){
                continue;
            }
			sum += ans[i][j];
		}
		if(num[i] == 4){
			break;
		}
//TODO 判断上一位和这一位是否是62，不能判断这一位和下一位，否则会造成漏加
		if(num[i+1]*10 + num[i] == 62){
			break;
		}
	}
	return sum;
}
