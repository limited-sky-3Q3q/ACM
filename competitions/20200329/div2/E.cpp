/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200329\div2\E.cpp
 * Date: 2020-04-02 15:22:56
 * LastEditTime: 2020-04-02 16:11:47
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
char SB[10004];
struct WA{
    char WA;
    int pos;
}que[10004];
int main(){
	int T,n,m,k;
    cin>>T;
    while(T--){
        memset(que, 0, sizeof que);
        memset(SB, 0, sizeof SB);
        cin>>n>>m>>k;
        for(int i=0; i<n; i++){
            //scanf("%c", &SB[i]);
            cin>>SB[i];
        }
        for(int i=0; i<k; i++){
            SB[i]='S';
        }
        
        for(int i=0; i<m; i++){
            //scanf("%c%d", &que[i].WA, &que[i].pos);
            //scanf("%c", &que[i].WA);
            cin>>que[i].WA;
            if(que[i].WA=='A'){
                que[i].pos=0;
                continue;
            }
            else{
                //scanf("%d", &que[i].pos);
                cin>>que[i].pos;
            }
        }
        
        int ans=0,now=k;//知道前now组数据
        for(int i=0; i<m; i++){
            if(que[i].WA=='W'){
                if(que[i].pos <= now && SB[que[i].pos-1]=='S'){
                    ans++;
                }
                now = max(now, que[i].pos);
            }
            else{
                now=n;
            }
        }
        cout<<ans<<'\n';
    }
	return 0;
}
