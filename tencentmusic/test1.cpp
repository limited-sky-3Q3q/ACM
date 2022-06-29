/************************************************
 * Auther        : SR
 * Date          : 2022-04-27 18:52:11
 * LastEditTime  : 2022-04-28 10:05:46
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




struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param a int整型vector 
     * @return TreeNode类vector
     */

    vector<TreeNode*> deleteLevel(TreeNode* root, vector<int>& a) {
        // write code here
        // set<int, int>deleted_levels(a.begin(), a.end());
        map<int, bool>deleted_levels;

        sort(a.begin(), a.end());
        if(a[0] != 1){
            a.push_back(0);
        }
        
        for(auto &level : a){
            deleted_levels[level] = true;
        }
        vector<TreeNode*> ans, node_to_leave;
       
        

        // if(a[0] != 1){
        //     ans.push_back(root);
        // }


        queue<TreeNode*>Q_now, Q_next;
        int level_now = 0;
        Q_next.push(root);

        while(!Q_next.empty()){
            Q_now = Q_next;
            while(!Q_next.empty()){
                Q_next.pop();
            }
            level_now++;
            
            while(!Q_now.empty()){
                TreeNode* ptr = Q_now.front();
                Q_now.pop();
                
                if(ptr->left){
                    Q_next.push(ptr->left);
                    // if(deleted_levels[level_now+1]){
                    //     node_should_delete.push_back(ptr->left);
                    // }
                }
                if(ptr->right){
                    Q_next.push(ptr->right);
                    // if(deleted_levels[level_now+1]){
                    //     node_should_delete.push_back(ptr->right);
                    // }
                }

                if(deleted_levels[level_now+1]){
                    node_to_leave.push_back(ptr);
                }
                if(!deleted_levels[level_now] && deleted_levels[level_now-1]){
                    ans.push_back(ptr);
                }
            }
        }
        
        for(auto &ptr : node_to_leave){
            ptr->right = nullptr;
            ptr->left = nullptr;
        }

        return ans;
    }
};

int main(){
	cout<<((1<<16));
	return 0;
}
