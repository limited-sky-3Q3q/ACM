/**
 * TODO Auther: by SR
 * Date: 2020-02-03 15:08:51
 * LastEditTime: 2020-02-03 15:52:36
 * ! 今日运势: 吉，无bug
 * 石子合并，无序
 * 贪心法
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll>stone;
void move(int);

int n;
int main(){
    ll temp, sum = 0;
    cin >> n;
    for(register int i = 1; i <= n; i++){
        cin >> temp;
        stone.push_back(temp);
    }
    sort(stone.begin(), stone.end());
    /*
    for(int j = 0; j < n ; j++){
            cout << stone[j]<<" ";
        }
        cout <<"\n";
    */

    for(int i = 2; i <= n; i++){
        
        sum += stone[1] + stone[0];
        stone[1] += stone[0];
        move(i);
        /*
        for(int j = 0; j < n; j++){
            cout << stone[j]<<" ";
        }
        cout <<"\n";
        */
    }
    cout << sum;
	return 0;
}

void move(int i){
    stone.erase(stone.begin());
    int pos = upper_bound(stone.begin(), stone.end(), stone[0]) - stone.begin();
    stone.insert(stone.begin()+pos, stone[0]);
    stone.erase(stone.begin());
}