/************************************************
 * Auther        : SR
 * Date          : 2022-04-07 18:42:04
 * LastEditTime  : 2022-04-08 17:25:42
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
int T,n,m;

int partition(vector<int>& nums, int l, int r) {
    // 以 nums[l] 作为基准数
    int i = l, j = r;
    while (i < j) {
        while (i < j && nums[j] >= nums[l]) j--;
        while (i < j && nums[i] <= nums[l]) i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[l]);
    return i;
}

void quickSort(vector<int>& nums, int l, int r) {
    // 子数组长度为 1 时终止递归
    while (l < r) {
        // 哨兵划分操作
        int i = partition(nums, l, r);
        // 仅递归至较短子数组，控制递归深度
        if (i - l < r - i) {
            quickSort(nums, l, i - 1);
            l = i + 1;
        } else {
            quickSort(nums, i + 1, r);
            r = i - 1;
        }
    }
}





int main(){


	// 调用
	vector<int> nums = { 4, 1, 3, 2, 5, 1 };
	quickSort(nums, 0, nums.size() - 1);
	return 0;
}
