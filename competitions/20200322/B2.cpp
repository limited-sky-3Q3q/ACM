/******************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200322\B2.cpp
 * Date: 2020-03-22 15:27:46
 * LastEditTime: 2020-03-22 16:25:03
 * !今日运势: 吉，无bug
******************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;
typedef long long ll;
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
    return;
}
struct t{
    int o,d;
}white,black;
queue<int>Q;
string name[12];
int team[12][12];
char win[1003];
int s[12][12]={0};
int main(){
	int n,most=-1,t=0,wd=1,bd=1,now=0;
    memset(s,0,sizeof(s));
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>name[i];
    }
    for(int i=5; i<=n; i++){
        Q.push(i);
    }
    cin>>win;
    int len=strlen(win);
    int wf=1,bf=2,ws=3,bs=4;
    white.o=1;black.o=2;
    white.d=3;black.d=4;
    s[1][3]=s[3][1]=++now;
    s[2][4]=s[4][2]=++now;
    for(int i=0; i<len; i++){
        if(win[i]=='W'){
            swap(white.o, white.d);
            wd++;
            
            if(bd>most){
                most=bd;
                memset(team, 0, sizeof(team));
                t=0;
                team[bf][bs]=++t;
            }
            if(bd==most){
                if(team[bf][bs]==0&&team[bs][bf]==0){
                    team[bf][bs]=++t;
                }
            }

            bd=1;
            Q.push(black.d);
            black.d=black.o;
            bf=black.d;
            black.o=Q.front();
            bs=black.o;
            Q.pop();
            if(s[bf][bs]==0){
                s[bf][bs]=s[bs][bf]=++now;
            }
        }
        else if(win[i]=='B'){
            swap(black.o, black.d);
            bd++;
            
            if(wd>most){
                most=wd;
                memset(team, 0, sizeof(team));
                t=0;
                team[wf][ws]=++t;
            }
            if(wd==most){
                if(team[wf][ws]==0&&team[ws][wf]==0){
                    team[wf][ws]=++t;
                }
            }

            wd=1;
            Q.push(white.d);
            white.d=white.o;
            wf=white.d;
            white.o=Q.front();
            ws=white.o;
            Q.pop();
            if(s[wf][ws]==0){
                s[wf][ws]=s[ws][wf]=++now;
            }
        }
    }
    
    if(bd>most){
        most=bd;
        memset(team, 0, sizeof(team));
        t=0;
        team[bf][bs]=++t;
    }
    if(bd==most){
        if(team[bf][bs]==0&&team[bs][bf]==0){
            team[bf][bs]=++t;
        }
    }

    if(wd>most){
        most=wd;
        memset(team, 0, sizeof(team));
        t=0;
        team[wf][ws]=++t;
    }
    if(wd==most){
        if(team[wf][ws]==0&&team[ws][wf]==0){
            team[wf][ws]=++t;
        }
    }

    for(int i=1; i<=n*(n-1)/2; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(s[j][k]==i&&team[j][k]!=0){
                    cout<<name[j]<<" "<<name[k]<<"\n";
                }
            }
        }
    }
	return 0;
}
