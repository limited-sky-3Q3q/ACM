/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\temp\L.cpp
 * Date: 2020-03-01 14:56:55
 * LastEditTime: 2020-03-01 16:26:01
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;

char s[200005]={0};
int slen;
int flag,cnt;
stack<int>spos;
queue<char>p;
void check(int a){
    if(a==1){
        if(flag==200005){
            spos.pop();
        }
        else if(flag!=200005 && flag==cnt+1){
            spos.pop();
        }
    }
    
    if(p.empty()){
        cout<<"YES\n";
        return;
    }
    
    if(flag!=200005 && cnt>=flag){
        cout<<"NO\n";
        return;
    }
    int i;
    for(spos.empty()?i=0:i=(spos.top()+1); i<slen; i++){
        if(s[i]==p.front()){
            flag=200005;
            spos.push(i);
            cout<<"YES\n";
            return;
        }
    }
    flag=cnt;
    cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    string c;
    char ch;
	cin>>s>>n;
    slen=strlen(s);
    flag=200005;cnt=0;
    for(int i=1; i<=n; i++){
        cin>>c;
        if(c=="pop"){
            cnt--;
            p.pop();
            check(1);
        }
        else{
            cnt++;
            cin>>ch;
            p.push(ch);
            check(2);
        }
    }
    
	return 0;
}
