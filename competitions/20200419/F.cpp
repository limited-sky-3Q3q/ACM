/************************************************
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\competitions\20200419\F.cpp
 * Date: 2020-04-19 14:42:54
 * LastEditTime: 2020-04-19 17:04:34
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;

struct edge{
    vector<int>to;
}e[10004];

int fa[10004];
int find(int a){
    return fa[a]==a? a:find(fa[a]);
}

vector<int>ans[10004];//1到每个数之间的数
map<int, int>have;//出现次数
int main(){
    int t,n,sum;
    fa[1]=1;
    scanf("%d", &t);
    sum=t;
    while(t--){
        scanf("%d", &n);

        for(int i=1; i<=n; i++){
            e[i].to.clear();
            ans[i].clear();
        }
        
        int u,v;
        for(int i=1; i<n; i++){
            scanf("%d%d", &u,&v);
            e[u].to.push_back(v);
            e[v].to.push_back(u);
            fa[i]=i;
        }
        //bfs
        ans[1].push_back(1);
        queue<int>Q;
        Q.push(1);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            for(int i=e[u].to.size()-1; i>=0; i--){
                int v=e[u].to[i];
                if(v==fa[u])
                    continue;
                fa[v]=u;
                Q.push(v);

                ans[v]=ans[u];
                if(v!=1)
                    ans[v].push_back(v);
                //cout<<"!";
            }
        }
    
        int QQ,K;
        scanf("%d", &QQ);
        //cout<<"\nCase "<<sum-t<<":";
        printf("Case %d:\n",sum-t);
        for(int i=0; i<QQ; i++){
            scanf("%d", &K);
            //memset(have, 0, sizeof have);
            //for(int i=0; i<=n; i++)have[i].clear();
            have.clear();

            for(int i=0; i<K; i++){
                scanf("%d%d", &u,&v);
                int MAX=max(ans[u].size(), ans[v].size());

                if(u==v){
                    have[u]++;
                    continue;
                }
                if(MAX==1){
                    have[ans[u][0]]++;
                    continue;
                }
                if(ans[u].size()==1){
                    for(int j=0; j<MAX; j++)
                        have[ans[v][j]]++;
                    continue;
                }
                if(ans[v].size()==1){
                    for(int j=0; j<MAX; j++)
                        have[ans[u][j]]++;
                    continue;
                }
                for(int j=0; j<MAX-1; j++){
                    if(ans[u][j+1] != ans[v][j+1]){//找到汇合点
                        for(int k=ans[u].size()-1; k>j; k--)
                            have[ans[u][k]]++;
                        for(int k=ans[v].size()-1; k>j; k--)
                            have[ans[v][k]]++;
                        have[ans[u][j]]++;
                        break;
                    }
                }
            }
            int tot=0;
            for(auto it = have.begin(); it != have.end(); it++)
                if(it->second==K)tot++;
            printf("%d\n",tot);
        }
    }

	return 0;
}
