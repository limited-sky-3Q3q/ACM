/************************************************
 * Auther        : SR
 * Date          : 2022-04-12 20:35:06
 * LastEditTime  : 2022-04-12 20:50:17
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

int main(){
	int A[250000], B[250000], pos[250000], n, count=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>A[i];
    }
    for(int i=1; i<=n; i++){
        cin>>B[i];
        pos[B[i]] = i;
    }

    for(int i=1; i<=n; i++){
        if(n%2 == 1){
            if(B[i] + A[i] != n*2 + 1 ){// B[i] != n - A[i]  
                int temp;
                temp = B[i];
                B[i] = n - A[i];
                int chang_pos = pos[n - A[i]];
                B[chang_pos] = temp;
                pos[B[i]] = i;
                pos[B[chang_pos]] = chang_pos;
                
                count++;
            }
        }
        else{
            if(B[i] + A[i] != n*2  ){// B[i] != n - A[i]  
                int temp;
                temp = B[i];
                B[i] = n - A[i];
                int chang_pos = pos[n - A[i]];
                B[chang_pos] = temp;
                pos[B[i]] = i;
                pos[B[chang_pos]] = chang_pos;
                
                count++;
            }
        }
        
    }
    cout<<count;
	return 0;
}
