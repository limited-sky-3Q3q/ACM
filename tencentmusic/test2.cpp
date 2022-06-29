/************************************************
 * Auther        : SR
 * Date          : 2022-04-27 18:52:16
 * LastEditTime  : 2022-04-27 19:47:15
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
     * 返回值的树节点中val表示节点权值
     * @param root TreeNode类 给定的初始树节点中的val表示节点编号
     * @param op int整型vector<vector<>> op的组成为[[id,v],[id,v],[id,v],...]
     * @return TreeNode类
     */

    void dfs(TreeNode* root, map<int, int>&ops, int xor_val){
        root->val = xor_val;
        // cout<<xor_val<<' ';
        if(root->left){
            dfs(root->left, ops, xor_val ^ ops[root->left->val]);
        }
        if(root->right){
            dfs(root->right, ops, xor_val ^ ops[root->right->val]);
        }

        return;
    }

    TreeNode* xorTree(TreeNode* root, vector<vector<int> >& op) {
        // write code here
        map<int, TreeNode*>index;
        map<int, int>ops;
        
        for(auto & oo : op){
            ops[oo[0]] = (oo[1]) ^ (ops[oo[0]]);
        }
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* ptr = Q.front();
            Q.pop();
            index[ptr->val] = ptr;
            if(ptr->left){
                Q.push(ptr->left);
            }
            if(ptr->right){
                Q.push(ptr->right);
            }
        }

        dfs(root, ops, ops[root->val] ^ 0);

        return root;
    }
};

int main(){
	
	return 0;
}
