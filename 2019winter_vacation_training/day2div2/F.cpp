/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day2div2\F.cpp
 * Date: 2020-02-10 10:03:47
 * LastEditTime: 2020-02-10 10:29:44
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN = 1003;

void init(const int n);
int find(const int a);
void merge(const int a, const int b);
int count(const int n);

int fa[MAXN];

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T,n,m;
    int a,b;
    cin>>T;
    while(T--){
        cin>>n>>m;
        init(n);
        for(int i = 1; i <= m; i++){
            cin>>a>>b;
            merge(a, b);//!
        }
        cout<<count(n)<<"\n";
    }
    
	return 0;
}

void init(const int n){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
    return;
}

int find(const int a){//找到a的根节点
    return a == fa[a] ? a : fa[a] = find(fa[a]);
    /*                       把a挂到根节点下    */
}

void merge(const int a, const int b){
    //合并a和b所在的两颗树
    fa[find(a)] = find(b);//把a的根节点挂到b的根节点下
    return;
}

int count(const int n){
    int cnt = 0;
    map<int, bool>mp;
    for(int i = 1; i <= n; i++){
        if(!mp[find(i)]){
            cnt++;
            mp[find(i)] = true;
        }
    }
    return cnt;
}