/**
 * TODO Auther: by SR
 * Date: 2020-01-13 09:48:34
 * LastEditTime: 2020-01-20 11:37:42
 * ! 今日运势: 吉，无bug
 * ?P1439 把LCS转化为LIS
 * TODO 用的是哈希的思路
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
void LCS();
int hahash[100005],seq[100005],d[100005];
int n;
int main()
{
    cin >> n;
    int temp;
    for(int i = 1; i <= n; i++){
        scanf("%d",&temp);
        hahash[temp] = i;
    }
    for(int i = 1; i <= n; i++){//! 不是 cin >> b[a[i]];的关系
        scanf("%d",&temp);
        seq[i] = hahash[temp];
    }
    //for(int i = 0;i <= n; i++)cout << seq[i]<< " ";
    //cout << "\n";

    LCS();
	return 0;
}

void LCS(){
    d[1] = seq[1];
    int k = 1;
    for(int i = 2; i <= n; i++){
        if(seq[i] > d[k]){
            d[++k] = seq[i];
        } 
        else{
            int l = lower_bound(d,d + k,seq[i]) - d;
            d[l] = seq[i];
        }
        
    }
    cout << k;
}
