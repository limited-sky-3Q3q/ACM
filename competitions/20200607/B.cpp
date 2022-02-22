/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200607\B.cpp
 * Date: 2020-06-07 12:44:30
 * LastEditTime: 2020-06-07 13:01:34
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
    int que[1003];

int main(){
    int n;
    cin>>n;
    char str[100];
    for(int i=1; i<=n; i++){
        //ch = getchar();
        cin>>str;
        if(isdigit(str[0])){    
            for(int j=0; j<strlen(str); j++){
                //que[i] += (str[j].)*pow(10, str.length()-1-i);
                que[i] = 10*que[i] + (str[j]-'0');
            }
        }
        else
            que[i] = -1;
    }

    bool flag = true;
    for(int i=1; i<=n; i++){
        if(que[i] == i)
            continue;
        if(que[i] == -1)
            continue;
        
        flag = false;
        break;
    }

    if(flag)
        cout<<"makes sense";
    else
        cout<<"something is fishy";
	return 0;
}
