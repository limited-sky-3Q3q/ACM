/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\temp2\L.cpp
 * Date: 2020-03-08 15:32:07
 * LastEditTime: 2020-03-08 16:57:55
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<map>
using namespace std;
typedef long long ll;
struct what{
    int typ,num;
};
map<string,int>exi1,exi2;
what a[3003],b[3003];
int main(){
	int n,m;
    exi1.clear();
    exi2.clear();
    string tmp;
    string ch;
    cin>>n;
    int len=0,pos=1;
    for(int i=0; i<n; i++){
        cin>>tmp;
        if(tmp=="define"){
            cin>>ch;
            if(exi1[ch]==0){
                exi1[ch]=pos++;
            }
            a[len++]={1,exi1[ch]};
        }
        else if(tmp=="print"){
            cin>>ch;
            if(exi1[ch]==0){
                exi1[ch]=pos++;
            }
            a[len++]={2,exi1[ch]};
        }
        else if(tmp=="read"){
            cin>>ch;
            if(exi1[ch]==0){
                exi1[ch]=pos++;
            }
            a[len++]={3,exi1[ch]};
        }
        else{
            string temp;
            temp.erase();
            for(int i=0; i<=tmp.length(); i++){
                if(tmp[i]=='='){
                    //temp+='\0';
                    a[len++]={4,exi1[temp]};
                    temp.erase();
                    
                }
                else if(tmp[i]=='+'){
                    //temp+='\0';
                    a[len++]={4,exi1[temp]};
                    temp.erase();
                    
                }
                else if(tmp[i]=='\0'){
                    //temp+='\0';
                    a[len++]={4,exi1[temp]};
                    temp.erase();
                    
                }
                else{
                    temp += tmp[i];
                }
                
            }
        }
    }

    cin>>m;
    len=0,pos=1;
    for(int i=0; i<m; i++){
        cin>>tmp;
        if(tmp=="define"){
            cin>>ch;
            if(exi2[ch]==0){
                exi2[ch]=pos++;
            }
            b[len++]={1,exi2[ch]};
        }
        else if(tmp=="print"){
            cin>>ch;
            if(exi2[ch]==0){
                exi2[ch]=pos++;
            }
            b[len++]={2,exi2[ch]};
        }
        else if(tmp=="read"){
            cin>>ch;
            if(exi2[ch]==0){
                exi2[ch]=pos++;
            }
            b[len++]={3,exi2[ch]};
        }
        else{
            string temp;
            temp.erase();
            for(int i=0; i<=tmp.length(); i++){
                if(tmp[i]=='='){
                    //temp+='\0';
                    b[len++]={4,exi2[temp]};
                    temp.erase();
                    
                }
                else if(tmp[i]=='+'){
                    //temp+='\0';
                    b[len++]={4,exi2[temp]};
                    temp.erase();
                    
                }
                else if(tmp[i]=='\0'){
                    //temp+='\0';
                    b[len++]={4,exi2[temp]};
                    temp.erase();
                    
                }
                else{
                    temp += tmp[i];
                }
                
            }
        }
    }
    
    
    
    for(int i=0; i<len; i++){
        if(a[i].typ==b[i].typ && a[i].num==b[i].num)continue;
        else{
            cout<<"NO";
            return 0;
        }
    }
    
    if(n!=m){
        cout<<"NO";
        return 0;
    }
    
    cout<<"YES";
	return 0;
}
