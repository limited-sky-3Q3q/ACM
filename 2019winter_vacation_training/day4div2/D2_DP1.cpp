/**
 * TODO Auther: by SR
 * Date: Do not edit
 * LastEditTime: 2020-02-04 18:00:29
 * ! 今日运势: 吉，无bug
**/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

string a,b;
int num[1003][1003];//!一样开错类型了。。。
char flag[1003][1003];
int LCS(string , string);//只计算长度，不求出相应序列

int main()
{
    while(cin>>a>>b){
        LCS(a,b);
    }
    return 0;
}

int LCS(string x,string y){
    int lenx = x.length();
    int leny = y.length();
    int leftabove, left, above;//左上角 左 上
    
    int *compute = new int[leny + 1];//申请一个动态整型数组，长度为leny + 1; //? new int[]是创建一个int型数组, new int()是创建一个int型的数，初始值为括号里的值
    memset(compute,0,(leny + 1) * sizeof(int));
    for(int i = 1; i <= lenx; i++){
        leftabove = left = compute[0];
        above = compute[1];
        for(int t = 0;t <= leny; t++)cout << compute[t] << " ";
        cout << "\n";
        for(int j = 1; j <= leny; j++){
            if(x[i-1] == y[j-1])compute[j] = leftabove + 1;
            else if(left > above)compute[j] = left;
            else compute[j] = above;

            leftabove = above;
            above = compute[j+1];
            left = compute[j];
        }
    }
    cout << compute[leny]<<"\n";
    delete[] compute;
}

