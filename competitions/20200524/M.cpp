/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200524\M.cpp
 * Date: 2020-05-24 16:34:13
 * LastEditTime: 2020-05-26 11:13:48
 * !今日运势: 吉，无bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;

struct Qr{
    //标记， 坐标， 
    int f, x, p;
    //按x从小到大， x相同则按f从小到大
    bool operator < (const Qr &a)const{
        return x == a.x ? f < a.f : x < a.x;
    }
}qr[MAXN];
int c[MAXN];
int xi[MAXN], cntX, tot;
int X[MAXN], Y[MAXN], Q[MAXN], R[MAXN], D[MAXN];
int ans[MAXN];

#define lowb(x) ((x)&(-(x)))//最小位的1保留，其他全为0
void update(int x, int v){
    while(x <= cntX) c[x] += v, x += lowb(x);
}
int query(int x){
    int ret = 0;
    while(x) ret += c[x], x -= lowb(x);
    return ret;
}

int main(){
    freopen("business.in","r",stdin);
    int T,N,M;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &N, &M);
        for(int i=1; i<=N; i++)
            scanf("%d%d%d", &X[i], &Q[i], &R[i]);
        for(int i=1; i<=M; i++)
            scanf("%d%d", &Y[i], &D[i]);

        // D <= Q + Y - X 变成 D - Y <= Q - X
        for(int i=1; i<=N; i++){
            xi[++cntX] = Q[i] - X[i];//？
        }
        for(int i=1; i<=M; i++){
            xi[++cntX] = D[i] - Y[i];
        }

        
        sort(xi+1, xi+1+cntX);//？sort全部？？？？
        cntX = unique(xi+1, xi+1+cntX) - xi - 1;//不重复序列的长度
        for(int i=1; i<=N; i++){
            //p 相当于坐标
            int p = lower_bound(xi+1, xi+1+cntX, Q[i]-X[i]) - xi;//最小的能达到Q[i] - X[i]的值
            qr[++tot] = {0, X[i], p};
            qr[++tot] = {0, X[i] + R[i] + 1, -p};
        }
        for(int i=1; i<=M; i++){
            int p = lower_bound(xi+1, xi+1+cntX, D[i]-Y[i]) - xi;//同上
            qr[++tot] = {i, Y[i], p};
        }
        
        sort(qr+1, qr+1+tot);
        
        for(int i=1; i<=tot; i++){
            if(qr[i].f == 0){//商店
                int w = qr[i].p > 0 ? 1:-1;
                update(abs(qr[i].p), w);
            }
            else{//人
                ans[qr[i].f] = query(cntX) - query(qr[i].p-1);
            }
        }
        
        for(int i=1; i<=M; i++){
            printf("%d%c", ans[i], i==M ? '\n' : ' ');
        }

        for(int i=1; i<=tot; i++){
            if(qr[i].f == 0){//初始化
                int w = qr[i].p > 0 ? 1:-1;
                update(abs(qr[i].p), -w);
            }
        }

        //大便
        /*
        for(int i=0; i<M; i++){
            ans = 0;
            for(int j=0; j<N; j++){
                if(Y[i] < X[j])
                    break;
                if(Y[i] > X[j] + R[j])
                    continue; 
                if(Q[j] + Y[i] - X[j] >= D[i])
                    ans++;
            }
            printf("%d ", ans);
        }
        cout<<"\n";
        */
    }
	return 0;
}


/*
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(a) ((int)a.size())
#define pb push_back
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define gmid (l + r >> 1)
const int maxn = 3e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
 
struct Qr{
    int f, x, p;
    bool operator < (const Qr &o) const{
        return x == o.x ? f < o.f : x < o.x;
    }
} qr[maxn];
int c[maxn];
int xi[maxn], cntX;
int X[maxn], Q[maxn], R[maxn], Y[maxn], D[maxn];
int ans[maxn];
int n, m, tot;
 
#define lowb(x) ((x)&(-(x)))
void update(int x, int v){
 
    while(x <= cntX) c[x] += v, x += lowb(x);
}
 
int query(int x){
 
    int ret = 0;
    while(x) ret += c[x], x -= lowb(x);
    return ret;
}
 
int main(){
 
    freopen("business.in", "r", stdin);
    int t; scanf("%d", &t);
    while(t--){
 
        scanf("%d%d", &n, &m);
        cntX = tot = 0;
        for(int i = 1; i <= n; ++i){
 
            scanf("%d%d%d", &X[i], &Q[i], &R[i]);
        }
        for(int i = 1; i <= m; ++i){
 
            scanf("%d%d", &Y[i], &D[i]);
        }
        for(int i = 1; i <= n; ++i){
 
            xi[++cntX] = Q[i] - X[i];
        }
        for(int i = 1; i <= m; ++i){
 
            xi[++cntX] = D[i] - Y[i];
        }
        sort(xi + 1, xi + 1 + cntX);
        cntX = unique(xi + 1, xi + 1 + cntX) - xi - 1;
        for(int i = 1; i <= n; ++i){
 
            int p = lower_bound(xi + 1, xi + 1 + cntX, Q[i] - X[i]) - xi;
            qr[++tot] = {0, X[i], p};
            qr[++tot] = {0, X[i] + R[i] + 1, -p};
        }
        for(int i = 1; i <= m; ++i){
 
            int p = lower_bound(xi + 1, xi + 1 + cntX, D[i] - Y[i]) - xi;
            qr[++tot] = {i, Y[i], p};
        }
        sort(qr + 1, qr + 1 + tot);
        for(int i = 1; i <= tot; ++i){
 
            if(qr[i].f == 0){
 
                int w = qr[i].p > 0 ? 1 : -1;
                update(abs(qr[i].p), w);
            }
            else{
 
                ans[qr[i].f] = query(cntX) - query(qr[i].p - 1);
            }
        }
        for(int i = 1; i <= m; ++i){
 
            printf("%d%c", ans[i], i == m ? '\n' : ' ');
        }
        for(int i = 1; i <= tot; ++i){
 
            if(qr[i].f == 0){
 
                int w = qr[i].p > 0 ? 1 : -1;
                update(abs(qr[i].p), -w);
            }
        }
    }
    return 0;
}
*/