/************************************************
 * Auther        : SR
 * Date          : 2022-04-24 19:57:30
 * LastEditTime  : 2022-04-24 20:58:08
************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param a int整型vector 
     * @return int整型
     */
    int getNumber(vector<int>& a) {
        // write code here
        if(a.size() == 1){
            return a[0];
        }
        
        int len = pow(a.size(), 0.5) + 1;
        vector<bool>erase_poses(a.size(), 0);
        erase_poses[0]=true;
        for(int i=2; i<len; i++){
            for(int erase_pos = i+i; erase_pos-1<a.size(); erase_pos += i){
                erase_poses[erase_pos - 1] = true;// 实际下标
            }
        }
        
        for(int i=a.size()-1; i>=0; i--){
            if(erase_poses[i]){
                a.erase(a.begin() + i);
            }
        }
        
        return getNumber(a);
    }
};

int main(){
	vector<int>test(4);
    test = {1,2,3,4};
    Solution A;
    // test.erase(test.begin() + 3);

    A.getNumber(test);
    
	return 0;
}
