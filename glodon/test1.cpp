/************************************************
 * Auther        : SR
 * Date          : 2022-04-20 22:04:52
 * LastEditTime  : 2022-04-20 22:16:00
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




int main(){
	string str;
    cin>>str;

    bool states[7] = {0,0,0,0,0,0,0};
    bool nums_states[10][7] = {{1, 1, 1, 0, 1, 1, 1},
                               {0, 0, 1, 0, 0, 1, 0},
                               {1, 0, 1, 1, 1, 0, 1},
                               {1, 0, 1, 1, 0, 1, 1},
                               {0, 1, 1, 1, 0, 1, 0},
                               {1, 1, 0, 1, 0, 1, 1},
                               {1, 1, 0, 1, 1, 1, 1},
                               {1, 0, 1, 0, 0, 1, 0},
                               {1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 0, 1, 1}};

    int ans=0;
    for(auto &ch : str){
        int num = ch - '0';

        for(int i=0; i<7; i++){
            // light up
            if(states[i] != nums_states[num][i]
               &&
               nums_states[num][i] == true){
                states[i] = true;
                ans++;
            }
        }

        for(int i=0; i<7; i++){
            // light down
            if(states[i] != nums_states[num][i]
               &&
               nums_states[num][i] == false){
                states[i] = false;
                ans++;
            }
        }
    }

    cout<<ans;
	return 0;
}
