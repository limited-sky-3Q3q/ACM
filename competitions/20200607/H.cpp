/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200607\H.cpp
 * Date: 2020-06-07 13:50:15
 * LastEditTime: 2020-06-08 11:07:41
 * !��������: ������bug
 * ֱ�ӱȽ����ʼ��ɣ�����ģ��
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;
typedef long long ll;
struct info{
    string name;
    ll p,c,t,r;
    ll i;
    bool operator < (const info&a)const{
        if(p == a.p)
            return i > a.i;
        return p > a.p;
    }
}que[105];
ll gcd(int a, int b){
    if(a==0)
        return b;
    return gcd(b%a, a);
}
bool cmp(info a, info b){
    return a.p < b.p;
}
int main(){
    char str[1000];
    int l,m;
    cin>>l>>m;
    getchar();
    //memset(str, 3, sizeof str);
    for(int i=1; i<=m; i++){
        cin.getline(str, 1000);
        int left = 0;

        que[i].i = i;
        
        for(int j = left; 1; j++){
            if(str[j] != ','){
                que[i].name += str[j];
            }
            else{
                left = j+1;
                break;
            }
        }

        for(int j=left; 1; j++){
            if(str[j] != ','){
                que[i].p = que[i].p*10 + ll(str[j] - '0');
            }
            else{
                left = j+1;
                break;
            }
        }
        for(int j=left; 1; j++){
            if(str[j] != ','){
                que[i].c = que[i].c*10 + ll(str[j] - '0');
            }
            else{
                left = j+1;
                break;
            }
        }
        for(int j=left; 1; j++){
            if(str[j] != ','){
                que[i].t = que[i].t*10 + ll(str[j] - '0');
            }
            else{
                left = j+1;
                break;
            }
        }
        for(int j=left; 1; j++){
            if(str[j] != 0){
                que[i].r = que[i].r*10 + ll(str[j] - '0');
            }
            else{
                break;
            }
        }
    }

    int len=0;
    priority_queue<info>q;
    for(int i=1; i<=m; i++){
        if(que[i].c*que[i].t*10080 >= l*(que[i].t + que[i].r)){
            q.push(que[i]);
        }

        
        //int T = (que[i].t + que[i].r)*10080/gcd((que[i].t + que[i].r), 10080);
        /*
        bool flag = true;
        for(ll T=1; T <=que[i].r + que[i].t; T++){
            ll sum = T*l;//Ҫ�޽��������
        
            ll n = (T*10080)/(que[i].r + que[i].t);//������������
            ll last = (T*10080)%(que[i].r + que[i].t);
            last = min(last, que[i].t);
            
            ll total = (n*que[i].t + last)*que[i].c;
            if(total >= sum){//����Ҫ��
                continue;
            }
            else{
                flag = false;
                break;
            }
        }
        
        if(flag){
            //ans[len++] = que[i];
            q.push(que[i]);
        }
        */
       
        
    
    }


    if(q.empty()){
        cout<<"no such mower";
        return 0;
    }
    else{
        info first = q.top();
        cout<<first.name<<'\n';
        q.pop();
        while(!q.empty() && q.top().p == first.p){
            cout<<q.top().name<<'\n';
            q.pop();
        }
    }
    
	return 0;
}
