/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\CF\643\B.cpp
 * Date: 2020-05-16 19:57:30
 * LastEditTime: 2020-05-17 10:22:06
 * !今日运势: 吉，无bug
 * 直接贪心
************************************************/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<vector>
using namespace std;
typedef long long ll;
//int T,n,temp,ans;
int main(){
    /*
    scanf("%d", &T);
    while(T--){
        ans = 0;
        memset(e, 0, sizeof e);
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &temp);
            e[temp]++;
        }
            

        for(int i=1; i<=n; i++){
            ans += e[i]/i;
            e[i+1] += e[i]%i;
        }
        printf("%d\n", ans);
    }
	return 0;
    */
   int t;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       vector <int> que(n);
       for(int i=0; i<n; i++){
           cin>>que[i];
       }
       sort(que.begin(), que.end());
       int ans = 0, cur = 0;//cur:团队人数
       //TODO *******************
       for(int i=0; i<n; i++){
           if(++cur == que[i]){//能够组成一个团
               ans++;
               cur = 0;
           }
       }
       cout<<ans<<"\n";
   }
}


/*

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            if (++cur == a[i]) {
                ans++;
                cur = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
*/