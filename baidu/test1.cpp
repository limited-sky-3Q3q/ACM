/************************************************
 * Auther        : SR
 * Date          : 2022-04-12 19:28:14
 * LastEditTime  : 2022-04-12 19:32:39
************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int maxn = 100;

struct move_d{
    int x,y;
};

int main(){
	map<char, move_d> move_ds;
    move_ds['L'] = {-1, 0};
    move_ds['R'] = {1, 0};
    move_ds['U'] = {0, 1};
    move_ds['D'] = {0, -1};

    move_d pos_now = {0, 0};

    char ch;
    while(ch = getchar()){
        pos_now.x += move_ds[ch].x;
        pos_now.y += move_ds[ch].y;
    }
    
    cout<<'('<<pos_now.x<<','<<pos_now.y<<')';
	return 0;
}
