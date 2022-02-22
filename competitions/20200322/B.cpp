/******************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200322\B.cpp
 * Date: 2020-03-22 14:14:25
 * LastEditTime: 2020-03-22 15:19:26
 * !今日运势: 吉，无bug
******************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
struct t{
    int o,d;
}white,black;
string name[12];
int team[11][11];
char win[1003];
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
    return;
}
queue<int>Q;
int win_times[12][12];
int main(){
    int most=0,t=0;
	int n,wd=0,bd=0;
    memset(team, 0, sizeof(team));
    memset(win_times, 0, sizeof(win_times));
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>name[i];
    }
    while(!Q.empty()){
        Q.pop();
    }
    for(int i=5; i<=n; i++){
        Q.push(i);
    }
    cin>>win;
    int len=strlen(win);
    white.o=1;black.o=2;
    white.d=3;black.d=4;
    int wf=1,ws=3,bf=2,bs=4;
    for(int i=0; i<len; i++){
        if(win[i]=='W'){
            swap(white.o,white.d);
            wd++;
            
            Q.push(black.d);
            if(team[bf][bs]<bd){
                team[bf][bs]=bd;
                if(most<bd){
                    most=bd;
                    t=0;
                    memset(win_times, 0 ,sizeof(win_times));
                    win_times[bf][bs]=++t;
                }
                else if(most==bd){
                    if(win_times[bf][bs]!=0||win_times[bs][bf]!=0){ }
                    else win_times[bf][bs]=++t;
                }
            }
            
            bd=0;
            black.d=black.o;
            bf=black.d;
            black.o=Q.front();
            bs=black.o;
            Q.pop();
        }
        else if(win[i]=='B'){
            swap(black.o,black.d);
            bd++;

            Q.push(white.d);
            if(team[wf][ws]<wd){
                team[wf][ws]=wd;
                if(most<wd){
                    most=wd;
                    t=0;
                    memset(win_times, 0 ,sizeof(win_times));
                    win_times[wf][ws]=++t;
                }
                else if(most == wd){
                    if(win_times[wf][ws]!=0||win_times[ws][wf]!=0){ }
                    else win_times[wf][ws]=++t;
                }
            }

            wd=0;
            white.d=white.o;
            wf=white.d;
            white.o=Q.front();
            ws=white.d;
            Q.pop();
        }
    }
    //team[bf][bs]=max(team[bf][bs], bd);
    if(team[bf][bs]<bd){
        team[bf][bs]=bd;
        if(most<bd){
            most=bd;
            t=0;
            memset(win_times, 0 ,sizeof(win_times));
            win_times[bf][bs]=++t;
        }
        else if(most==bd){
            if(win_times[bf][bs]!=0||win_times[bs][bf]!=0){ }
            else win_times[bf][bs]=++t;
        }
    }
    //team[wf][ws]=max(team[wf][ws], wd);
    if(team[wf][ws]<wd){
        team[wf][ws]=wd;
        if(most<wd){
            most=wd;
            t=0;
            memset(win_times, 0 ,sizeof(win_times));
            win_times[wf][ws]=++t;
        }
        else if(most == wd){
            if(win_times[wf][ws]!=0||win_times[ws][wf]!=0){ }
            else win_times[wf][ws]=++t;
        }
    }
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if(win_times[i][j]>win_times[j][i]){
                win_times[j][i]=-1;
            }
            else{
                win_times[i][j]=-1;
            }
        }
    }
    
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(win_times[j][k]==i){
                    cout<<name[j]<<" "<<name[k]<<"\n";
                    continue;
                }
                if(j==n&&k==n)break;
            }
        }
        
    }
    
	return 0;
}
