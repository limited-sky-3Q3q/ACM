/************************************************
 * Auther        : SR
 * Date          : 2022-04-24 20:29:07
 * LastEditTime  : 2022-04-24 21:42:56
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

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param a ListNode类vector 指向每段碎片的开头
     * @return ListNode类
     */
    struct head_tail{
        ListNode* head, *tail;
    };
    
    ListNode* solve(vector<ListNode*>& a) {
        // write code here
        vector<head_tail>head_tails(a.size());
        map<int, ListNode*>map_map;//实际链表

        {
            ListNode* ptr = new ListNode(a[0]->val);
            
            map_map[ptr->val] = ptr;
            while(a[0]->next){
                a[0] = a[0]->next;
                ptr->next = new ListNode(a[0]->val);
                ptr = ptr->next;
                map_map[ptr->val] = ptr;
            }
        }

        for(int i=1; i<a.size(); i++){
            // ListNode* head = a[i];
            // ListNode* tail = head;
            // while(tail->next){
            //     tail = tail->next;
            // }
            // head_tails[i].head = head;
            // head_tails[i].tail = tail;
            
            ListNode* ptr = a[i];
            
            do{
                if(!map_map[ptr->next->val]){
                    if(!map_map[ptr->val]){
                        map_map[ptr->val] = new ListNode(ptr->val);
                    }

                    map_map[ptr->val]->next = new ListNode(ptr->next->val);
                    map_map[ptr->next->val] = map_map[ptr->val]->next;

                }
                ptr = ptr->next;
            }while(ptr->next)
        }
        

        for(auto &a : map_map){
            return a.second;
        }


    }
};

int main(){
	
	return 0;
}
