/************************************************
 * Auther        : SR
 * Date          : 2022-04-17 14:49:04
 * LastEditTime  : 2022-04-17 17:27:32
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
struct Soul{
    int C, D;
};

bool cmp(Soul& A, Soul& B){
    if(A.D != B.D){
        return A.D > B.D;
    }
    else{
        return A.C > B.C;
    }
}

bool dfs(vector<vector<Soul> >& souls, int depth, int C_now, int D_now, int& ans){
    if(depth == 6){
        if(C_now >= 100){
            ans = D_now;
            return true;
        }
        return false;
    }
    if(souls[depth].empty()){
        if(dfs(souls, depth+1, C_now, D_now, ans)){
            return true;
        }
    }
    else{
        for(auto &soul : souls[depth]){
            if(dfs(souls, depth+1, C_now+soul.C, D_now+soul.D, ans)){
                return true;
            }
        }
    }
    
    return false;
}

int main(){
	int T;
    cin>>T;

    while(T--){
        int n;
        cin>>n;
        vector<vector<Soul> >souls = vector<vector<Soul> >(6, vector<Soul>());

        for(int i=0; i<n; i++){
            Soul temp;
            int P;
            cin>>P>>temp.C>>temp.D;
            souls[P-1].emplace_back(temp);
        }

        for(int i=0; i<6; i++){
            sort(souls[i].begin(), souls[i].end(), cmp);
        }

        int ans;
        if(dfs(souls, 0, 0, 0, ans)){
            cout<<ans;
        }
        else{
            cout<<"TAT";
        }

        if(T!=0){
            cout<<endl;
        }

    }
	return 0;
}
