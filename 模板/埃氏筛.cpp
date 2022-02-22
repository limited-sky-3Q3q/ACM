/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ģ��\����ɸ.cpp
 * Date: 2020-09-28 20:21:12
 * LastEditTime: 2020-09-28 20:32:12
 * !��������: ������bug
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
 
const long long maxn = 10000007 + 10;
const long long maxp = 700000;
int vis[maxn];    // i�Ǻ���visΪ1��i��������visΪ0
long long prime[maxp];
 
void sieve(long long n){
    long long m = (long long)sqrt(n + 0.5);
    memset(vis, 0, sizeof(vis));
    vis[2] = 0;
    for (long long i = 3; i <= m; i += 2) {//ʱ�仹���е�ã�ʹ��ʱ�������Ҫ��ǰ���
        if(!vis[i])
            for (long long j = i * i; j <= n; j += i)//n*i(n<i)��Ϊ������
                vis[j] = 1;
        if(i * i > n)
            break;
    }
}
 
long long gen(long long n){
    sieve(n);
    long long c = 1;
    prime[0] = 2;
    for (long long i = 3; i <= n; i += 2)
        if(!vis[i])
            prime[c++] = i;
    return c;
}
 
int main()
{
    long long n, c;
    cout << "ˢ������n��";
    cin >> n;
    c = gen(n);
    for (long long i = 0; i < c; i++)
        printf("%lld", prime[i]);
    cout << endl << c;
    return 0;
}