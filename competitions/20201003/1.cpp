/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20201003\1.cpp
 * Date: 2020-02-08 22:26:31
 * LastEditTime: 2020-10-05 20:26:34
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<string>
#include<map>
#include<stdio.h>
using namespace std;
typedef long long ll;

//还没过*********************************************

const int MAXN = 15005;
int n,m;
string temp;
string i_name[MAXN];
map<string, int>name_i;
int rank1[MAXN], rank2[MAXN];

struct RECORD{
    int a,d,w,t;
}record[MAXN];

bool cmp(RECORD a, RECORD b){
    return a.t<b.t;
}

int main(){
    //read
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>i_name[i];
        name_i[i_name[i]] = i;
        rank1[i] = i;
    }
    
    getchar();
    for(int i=0; i<m; i++){
        getline(cin, temp, ',');
        record[i].a = name_i[temp];
        getline(cin, temp, ',');
        record[i].d = name_i[temp];
        getline(cin, temp, ',');
        record[i].w = temp=="win"?1:0;
        getline(cin, temp);
        record[i].t = (temp[0]-'0')*600 + (temp[1]-'0')*60 + (temp[3]-'0')*10 + temp[4] - '0';
    }

    //solve
    sort(record, record+m, cmp);

    for(int i=0; i<m; i++){
        if(record[i].w && (rank1[record[i].a] > rank1[record[i].d])){
            int ttt = rank1[record[i].a];
            rank1[record[i].a] = rank1[record[i].d];
            rank1[record[i].d] = ttt;
        }
    }
    
    for(int i=0; i<n; i++)
        rank2[rank1[i]] = i;

    for(int i=0; i<n; i++)
        cout<<i_name[rank2[i]]<<'\n';
        
    return 0;
}


/*
string i_name[15005];
map<string, int>name_i;
int rankk[15005];
int n,m,a,b,c;
string temp;

struct RECORD{
    int a,b,c,t;
}record[15005];

bool cmp(RECORD a, RECORD b){
    return a.t < b.t;
}

int main(){
    cin>>n>>m;

    //getchar();
    for(int i=0; i<n; i++){
        cin>>temp;
        i_name[i] = temp;
        name_i[temp] = i;
        rankk[i] = i;
    }

    getchar();
    
    for(int i=0; i<m; i++){
        
        getline(cin, temp, ',');
        record[i].a = name_i[temp];
        getline(cin, temp, ',');
        record[i].b = name_i[temp];
        getline(cin, temp, ',');
        record[i].c = (temp == "win") ? 1:0;
        getline(cin, temp);
        record[i].t = (temp[0] - '0')*600 + (temp[1] - '0')*60 + (temp[3] - '0')*10 + (temp[4] - '0');
        
    }

    sort(record, record+m, cmp);

    for(int i=0; i<m; i++){
        if(record[i].c){
            if(rankk[record[i].a] > rankk[record[i].b]){
                int ttt = rankk[record[i].a];
                rankk[record[i].a] = rankk[record[i].b];
                rankk[record[i].b] = ttt;
            }
        }
        else
            continue;
    }

    //sort(rankk, rankk+n);

    int rankkkkk[15005];
    for(int i=0; i<n; i++){
        rankkkkk[rankk[i]] = i;
    }

    //cout<<i_name[rankkkkk[0]];
    for(int i=0; i<n; i++){
        cout<<i_name[rankkkkk[i]]<<'\n';
    }
    
	return 0;
}
*/