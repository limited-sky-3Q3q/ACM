#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<vector>
#define INF 0x3f3f3f3f//巨大无比的一个数 
using namespace std;
int n, q[1001][1001], minn[100001], ans;//minn表示不在最小生成树中的点与在最小生成树中的点相连的最小边权 
bool f[100001];//不在最小生成树中的点f等于false，在就等于true 
int main()
{
    memset(minn, INF, sizeof(minn));//初始化 
    minn[1] = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &q[i][j]);//输入邻接矩阵 
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int k = 0;
        for(int j = 1; j <= n; j++)
        {
            if(!f[j] && minn[j] < minn[k])//寻找权值最短的边（且不能是已经在最小生成树中的点） 
            {
                k = j;
            }
        }
        f[k] = true;//把它加入最小生成树 
        for(int j = 1; j <= n; j++)
        {
            if(!f[j] && q[k][j] < minn[j])//利用新点改变其他不在最小生成树中的点的边的权值 
            {
                minn[j] = q[k][j];
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        ans += minn[i];//把所有在最小生成树中的点的权值加起来 
    }
    printf("%d", ans);
    return 0;
}