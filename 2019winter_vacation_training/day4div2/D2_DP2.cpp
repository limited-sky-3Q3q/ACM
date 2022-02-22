/**
 * TODO Auther: by SR
 * Date: 2020-01-16 16:04:02
 * LastEditTime: 2020-02-04 19:16:20
 * ! 今日运势: 吉，无bug
 * ? 求两个字符串的LCS的长度的
 * TODO 同时求该子序列
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<cstring>
#include<string>
using namespace std;

char a[10004],b[10004];
int num[10104][10104];//记录中间结果的数组 //!妈蛋这是int 型的数组啊！！！！！！！！我咋开成char型的了，搞了我好几天卡在这。
int flag[10104][10104];//标记数组，用于标记下标的走向，构造出公共子序列
void LCS();
void getLCS();//采用倒推的方式求最长公共子序列

int main(){	
	while(cin>>a>>b){
		LCS();
		cout<<"  j ";
		for(int i = 1; i <= strlen(b); i++)cout<<i<<" ";
		cout<<"\n";
		for(int i = 0; i <= strlen(a); i++){

			if(i)cout << i<<" ";
			else{
				cout<<"i ";
			}
			for(int j = 0; j <= strlen(b); j++){
				cout << num[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout << num[strlen(a)][strlen(b)];
		cout << "\n";
		getLCS();
	}
	return 0;
}

void LCS(){
	for(int i = 1; i <= strlen(a);i++){
		for(int j = 1; j <= strlen(b); j++){
			if(a[i-1] == b[j-1]){
				num[i][j] = num[i-1][j-1] + 1;
				flag[i][j] = 1;//向右下标记
			}
			else if(num[i][j-1] > num[i-1][j]){
				num[i][j] = num[i][j-1];
				flag[i][j] = 2;//向右标记
			}
			else{
				num[i][j] = num[i-1][j];
				flag[i][j] = 3;//向下标记
			}
		}
	}

}

void getLCS(){
	char res[500];
	
	int i = strlen(a), j = strlen(b);
	int k = 0;
	while(i > 0 && j > 0){
		if(flag[i][j] == 1){
			res[k] = a[i-1];
			k++, i--, j--;
		}
		else if(flag[i][j] == 2){
			j--;
		}
		else if(flag[i][j] == 3){
			i--;
		}
	}

	for(int i = k-1; i >= 0; i--){
		printf("%c",res[i]);
	}
	cout << "\n";
}