/*
#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<string>
#include<queue>
#include<vector>
#include<map>
#define ll long long
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define dep(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
const int maxn=18;
int n,m,k,mm;
ll tmp,cnt,ans;
bool c[maxn][maxn];
ll dp[(1<<17)+5][2];
ll dfs(int i,int zt,int fg)
{// 逐位判断，当前判断第i位
 // zt表示1到n这些数中哪一些数的位置是确定的
    //到头了
    if(i==n+1&&zt==mm) return fg;//满足条件，return 1 
    else if(i==n+1||zt==mm) return 0; //不满足，return 0
    //数据已计算就直接return
    if(dp[zt][fg]!=-1) return dp[zt][fg];
    
    ll sum=0;
    rep(j,0,n-1)
    if(!(zt&(1<<j))){//如果算上第j位之后还有一些数的位置不确定
    //            c[][]不是0就是1
        int x=(fg|c[i][j+1]);//更新是否满足条件的状态
        sum+=dfs(i+1,zt|(1<<j),x);
    }
    dp[zt][fg]=sum;
    return dp[zt][fg];
}
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        memset(dp,-1,sizeof(dp));
        memset(c,0,sizeof(c));
        scanf("%d%d",&n,&m);
        mm=(1<<n)-1;
        rep(i,0,m-1){
            int x,y;
            scanf("%d%d",&x,&y);
            c[x][y]=1;
        }
        //     即dp[0][0]
        ll ans=dfs(1,0,0);//初始状态为0
        printf("Case %d: %lld\n",cas++,ans);
    }
    return 0;
}
*/
//TODO-----------------------------------------------------------------------
#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<string>
#include<queue>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;
int n,m,g[20][20];
LL fac[20],dp[1<<18];  //dp[i][state]代表长度为i的排列使用数字情况state的不完美数量 

int main()
{
    int T,Case=0; cin>>T;
    fac[0]=1; for (int i=1;i<=17;i++) fac[i]=fac[i-1]*i;
    while (T--) {
        scanf("%d%d",&n,&m);
        int ALL=(1<<n)-1;
        memset(g,0,sizeof(g));
        for (int i=1;i<=m;i++) {
            int x,y; scanf("%d%d",&x,&y);
            g[x][y]=1;  //x位置不能y 
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1; LL sum=0;
        for (int i=1;i<=n;i++) {  //长度i:现在填到第i位
            for (int j=ALL;j>=0;j--) {  //数字使用情况state 
                for (int k=1;k<=n;k++) {  //这一位置填数字k 

                    if ((1<<(k-1))&j) continue;//j状态下，数字k已经被取过了
                    
                    if (g[i][k]) continue;//第i位填k符合条件，continue
                    //else 第i位填k不符合条件，那么状态j在第i位填上数字k后不符合条件
                    
                    cout<<"K=="<<k<<" j=="<<j<<" dp[j]=="<<dp[j]<<"\n";
//*状态j填上数字k后不满足条件的排列个数 加上 状态j不满足条件的排列个数
                dp[(1<<(k-1))|j]      +=        dp[j];
                }
                dp[j]=0;//TODO ????????????
            }
        }
        for (int i=0;i<=ALL;i++) sum+=dp[i];
        printf("Case %d: %lld\n",++Case,fac[n]-sum);
    }
    return 0;
}