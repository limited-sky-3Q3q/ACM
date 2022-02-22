/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day3div2\B.cpp
 * Date: 2020-02-12 13:57:30
 * LastEditTime: 2020-02-12 17:10:07
 * ! 今日运势: 吉，无bug
 * 还是跑最小生成树。。。想的太复杂了
 * TODO 用cin，cout会TLE，看来还是得用scanf，printf
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
//#include<memory.h>
using namespace std;
typedef long long ll;
const int MAXN = 50004;
const int INF = 0x3f3f3f3f;

struct eg{
    int girl, boy, weight;
}edge[MAXN];
bool cmp(eg a, eg b){
    return a.weight > b.weight;
}

int N, M, R, ans, c, fa[MAXN];
int find(const int a){
    return fa[a]==a ? a : fa[a]=find(fa[a]);
}
int main(){
    /*
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    */
	int T;
    scanf("%d", &T);
    //cin>>T;
    while(T--){
        //N==girl, M==boy
        //cin>>N>>M>>R;//read
        scanf("%d%d%d",&N,&M,&R);
        for(register int i=1; i<=R; i++){
            //cin>>edge[i].girl>>edge[i].boy>>edge[i].weight;
            scanf("%d%d%d", &(edge[i].girl), &(edge[i].boy), &(edge[i].weight));
            edge[i].boy = N + edge[i].boy;
        }

        //init
        for(register int i=0; i<=N+M; i++){
            fa[i]=i;
        }
        sort(edge+1, edge+R+1, cmp);
        
        //solve kruscal
        int fx,fy, ans=0;
        for(register int i=1; i<=R; i++){
            fx=find(edge[i].girl);
            fy=find(edge[i].boy);
            if(fx != fy){
                fa[fx]=fy;
                ans += edge[i].weight;
            }
        }

        //output
        //cout<<(N+M)*10000 - ans<<"\n";
        printf("%d\n", (N+M)*10000 - ans);
    }
	return 0;
}

