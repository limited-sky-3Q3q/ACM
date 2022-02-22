/*
 * @Auther: by SR
 * @Date: 2020-01-14 13:41:01
 * @LastEditTime : 2020-01-14 17:00:47
 */

//http://acm.hdu.edu.cn/showproblem.php?pid=1950


#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 40005
int arr[MAXN],ans[MAXN],len;
int main()//o(NlogN)的做法
{
    int T,N;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i = 1; i <= N; i++)scanf("%d",&arr[i]);

        ans[1] = arr[1];
        len = 1;

        for(int i = 2; i <= N; i++){//核心部分
            
            //在后方发现比当前的最大值ans[len]更大的数arr[i],说明有更长的序列，故ans[++len]=arr[i]
            if(arr[i] > ans[len])ans[++len] = arr[i];
            
            
            else{//不然,对arr[i]。。。咦？这有啥用？不能省略，省略会WA
                //不然，更新之前的ans，因为ans数组的有序性，把第一个比arr[i]大的ans的值更新为arr[i]
                //重点是需要更新ans[len]的情况
                int pos = lower_bound(ans,ans + len,arr[i]) - ans;//找到下界的位置
                ans[pos] = arr[i];
            }
        }
        printf("%d\n",len);
    }
    
    return 0;
}