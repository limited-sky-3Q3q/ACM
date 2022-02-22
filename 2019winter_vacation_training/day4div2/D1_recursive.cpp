/**
 * TODO Auther: by SR
 * Date: 2020-01-14 17:38:02
 * LastEditTime: 2020-01-16 10:53:49
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

string a,b;
int d[1000][1000] = {0};

//暴力递归穷举
//ab是逆序的话会炸
void LCS(int,int);

int main()
{
    while(cin>>a>>b){
        for(int i = 0;i < 1000;i++){
            for(int j = 0; j < 1000;j++){
                d[i][j] = 0;
            }
        }

        
        bool flag = true;
        for(int i = a.size()-1;i >= 0;i--){
            flag = true;
            for(int j = b.size(); j >= 0;j--){
                if(a[i] == b[j]){
                    flag = false;
                    break;
                }
            }
            if(flag)a[i] = 0;
        }
        for(int i = b.size()-1;i >= 0;i--){
            flag = true;
            for(int j = a.size(); j >= 0;j--){
                if(b[i] == a[j]){
                    flag = false;
                    break;
                }               
            }
            if(flag)b[i] = 0;
        }
        
        LCS(a.size(),b.size());
        int MAX = 0;
        for(int i = a.size() - 1; i >= 0;i--){
            for(int j = b.size() - 1;j >= 0;j--){
                if(d[i][j] > MAX)MAX = d[i][j];
            }
        }
        cout << MAX <<"\n";
    }
    
    return 0;
}

void LCS(int n1,int n2){
    if(a[n1] && b[n2]){
        if(n1 == 0 || n2 == 0){
            if(a[n1] == b[n2]){
                if(!d[n1][n2])d[n1][n2] = 1;
            }
            return;
        }
        else if(a[n1] == b[n2]){
            if(!d[n1-1][n2-1])LCS(n1-1,n2-1);

            d[n1][n2] = 1 + d[n1-1][n2-1];
        }
        else{
            if(!d[n1-1][n2])LCS(n1-1,n2);
            if(!d[n1][n2-1])LCS(n1,n2-1);

            d[n1][n2] = max(d[n1-1][n2],d[n1][n2-1]);
        }
        return;
    }
    else if(a[n1]){
        if(n1 == 0 || n2 == 0){
            return;
        }
        else LCS(n1,n2-1);   
    }
    else if(b[n2]){
        if(n1 == 0 || n2 == 0){
            return;
        }
        else LCS(n1-1,n2);
    }
    else {
        if(n1 == 0 || n2 == 0){
            return;
        }
        else LCS(n1-1,n2-1);
    }
    return;
}