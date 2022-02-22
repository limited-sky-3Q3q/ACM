/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200329\div2\H.cpp
 * Date: 2020-03-31 17:58:00
 * LastEditTime: 2020-04-02 15:02:18
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
int num[30]={0};
int ans[30][30]={0};//暂存部分答案
bool vis[30][30]={0};
int main(){
	int T,n,m,k;
    char *a, *b,c,d;
    cin>>T;
    while(cin>>n>>m>>k){
        ll total=0;
        a=new char[n+1];
        b=new char[m+1];
        memset(num, 0, sizeof num);
        memset(ans, 0, sizeof ans);
        memset(vis, 0, sizeof vis);
        cin>>a>>b;
        for(int i=0; i<m; i++){//预处理
            num[b[i]-'a']++;
        }
        
        for(int i=0; i<n-k+1; i++){
            c=a[i];d=a[i+k-1];//有顺序之分
            if(vis[c-'a'][d-'a']){//已判断过的组合
                //不用加上
                //total += ans[c-'a'][d-'a'];
                continue;
            }
            
            int temp1=0, temp2=0;//遇到的左右数的个数
            if(c==d){//头尾相同
                for(int i=num[d-'a']; i>=1; i--){
                    ans[c-'a'][d-'a'] += i;
                }
                total += ans[c-'a'][d-'a'];
                vis[c-'a'][d-'a'] = true;
            }
            else{
                if(num[c-'a']==0 || num[d-'a']==0){//不可能
                    vis[c-'a'][d-'a']=true;
                    ans[c-'a'][d-'a']=0;
                }
                for(int j=0; j<m; j++){//从左到右判断
                    if(b[j]==c){//遇到左数
                        ans[c-'a'][d-'a'] += num[d-'a']-temp2;
                        temp1++;
                    }
                    else if(b[j]==d){//遇到右数
                        temp2++;
                    }
                    if(temp1==num[c-'a'] || temp2==num[d-'a']){//到头了
                        vis[c-'a'][d-'a']=true;
                        total += ans[c-'a'][d-'a'];
                        break;
                    }
                }
            }
            
        }
        cout<<total<<'\n';
        delete [] a;
        delete [] b;
    }
	return 0;
}
