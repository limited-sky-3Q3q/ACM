/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200517\D.cpp
 * Date: 2020-05-17 15:12:43
 * LastEditTime: 2020-05-17 15:54:33
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<vector>
using namespace std;
typedef long long ll;
struct coord{
    double x,y;
}tree[50004];
ll N,W,H, a,b,c;
int main(){
    while(cin>>N>>W>>H){
        if(N + W + H == 0){
            return 0;
        }

        a=b=0;
        vector <double> k;
        coord mid = {double(W)/2, double(H)/2};
        bool flag=false;
        
        for(int i=0; i<N; i++){
            cin>>tree[i].x>>tree[i].y;
            if(tree[i].x > double(W)/2){
                k.push_back( (tree[i].y - mid.x) / (tree[i].x - mid.y) );
            }
        }

        sort(k.begin(), k.end());
        
        for(int i=0; i<k.size(); i++){
            int ans[250004],com[250004];
            int len=0,len2=0;
            memset(ans, 0, sizeof ans);
            memset(com, 0, sizeof com);
            a=b=c=0;
            for(int j=0; j<N; j++){
                if(tree[j].y > k[i]*(tree[j].x - mid.x) + mid.y){//上
                    a++;
                    if(a>(N/2))break;
                    ans[len++]=j;
                }else if(tree[j].y == k[i]*(tree[j].x - mid.x) + mid.y){
                    c++;
                    if(c>(N/2))break;
                    com[len2++]=j;
                }else{
                    b++;
                    if(b>(N/2))break;
                    //ans[1][len2++]=j;

                }
            }

            if(a == b || abs(a-b) <=  c){
                for(int j=0; j<a; j++){
                    cout<<ll(tree[ans[j]].x)<<' '<<ll(tree[ans[j]].y)<<'\n';
                }
                for(int j=0; j<(N/2 - a); j++){
                    cout<<ll(tree[com[j]].x)<<' '<<ll(tree[com[j]].y)<<'\n';
                }
                flag = true;
                break;
            }
        }
        if(flag)continue;


        int ans[250004],com[250004];
        int len=0,len2=0;
        memset(ans, 0, sizeof ans);
        memset(com, 0, sizeof com);
        a=b=c=0;
        for(int j=0; j<N; j++){
            if(tree[j].x > mid.x){//右
                a++;
                if(a>(N/2 + 1))break;
                ans[len++]=j;
            }else if(tree[j].x == mid.x){
                c++;
                if(c>(N/2 + 1))break;
                com[len2++]=j;
            }else{
                b++;
                if(b>(N/2 + 1))break;
            }
        }

        if(a == b || abs(a-b) <=  c){
            for(int j=0; j<a; j++){
                cout<<ll(tree[ans[j]].x)<<' '<<ll(tree[ans[j]].y)<<'\n';
            }
            for(int j=0; j<(N/2 - a); j++){
                cout<<ll(tree[com[j]].x)<<' '<<ll(tree[com[j]].y)<<'\n';
            }
            flag = true;
            continue;
        }

        len=0,len2=0;
        memset(ans, 0, sizeof ans);
        memset(com, 0, sizeof com);
        a=b=c=0;
        for(int j=0; j<N; j++){
            if(tree[j].y > mid.y){//上
                a++;
                if(a>(N/2 + 1))break;
                ans[len++]=j;
            }else if(tree[j].y == mid.y){
                c++;
                if(c>(N/2 + 1))break;
                com[len2++]=j;
            }else{
                b++;
                if(b>(N/2 + 1))break;
            }
        }

        if(a == b || abs(a-b) <=  c){
            for(int j=0; j<a; j++){
                cout<<ll(tree[ans[j]].x)<<' '<<ll(tree[ans[j]].y)<<'\n';
            }
            for(int j=0; j<(N/2 - a); j++){
                cout<<ll(tree[com[j]].x)<<' '<<ll(tree[com[j]].y)<<'\n';
            }
            flag = true;
            continue;
        }
        

    }
	return 0;
}
