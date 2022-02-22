/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200501\E.cpp
 * Date: 2020-05-01 15:57:58
 * LastEditTime: 2020-05-01 16:20:38
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
int spos[5003], dpos[5003];
int que[5003],d[5003][2];
int ans[5003];
bool vis[5003];
bool cmp1(int a, int b){//spos
    return que[a]>que[b];
}
bool cmp2(int a, int b){//dpos
    return d[a][1]<d[b][1];
}
int main(){
    int n,m;
    cin>>n>>m;
	for(int i=1; i<=n; i++){
        cin>>que[i];
    }
    for(int i=1; i<=m; i++){
        cin>>d[i][0];
    }
    for(int i=1; i<=m; i++){
        cin>>d[i][1];
    }
    
    for(int i=0; i<= n; i++){
        spos[i] = i;
    }
    for(int i=0; i<= m; i++){
        dpos[i] = i;
    }
    sort(spos+1, spos+n+1, cmp1);//人多到人少
    sort(dpos+1, dpos+m+1, cmp2);//便宜到贵
    int ans[5003];
    bool flag=false;
    for(int i=1; i<=n; i++){//人多的先选
        flag = false;
        for(int j=1; j<=m; j++){
            if(!vis[dpos[j]] && que[spos[i]] <= d[dpos[j]][0]){//够住且便宜
                vis[dpos[j]] = true;
                ans[spos[i]] = dpos[j];
                flag = true;
                break;
            }
        }
        if(flag)
            continue;
        else{
            cout<<"impossible";
            return 0;
        }
            
    }
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
	return 0;
}
