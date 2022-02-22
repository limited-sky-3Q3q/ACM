/************************************************
 * TODO Auther: by SR
 * FilePath: \digital designc:\Users\SR\Documents\vscodefile\ACM\competitions\20200524\L.cpp
 * Date: 2020-05-24 13:34:20
 * LastEditTime: 2020-05-24 15:17:28
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
//bool p[100005];
int que[100005];

int main(){
    freopen("reflection.in", "r", stdin);
    int T, Q,ans;
    scanf("%d", &T);
    while(T--){
        //memset(p, 0, sizeof p);
        vector<int>p;
        scanf("%d", &Q);
        for(int i=0; i<Q; i++)
            scanf("%d", &que[i]);
        
        for(int i=0; i<Q; i++){
            ans = 0;
            int a = 1;

            if(p.size() > 0 && que[i] < p[0]){
                ans += a*(que[i] - p[0]);
            }
            else if(p.size() > 0){
                for(int j=0; j<p.size(); j++){
                    if(que[i] <= p[j]){
                        if(j == 0){
                            ans += a*que[i];
                        }
                        else{
                            ans += a*(que[i] - p[j-1]);
                        }
                        break;
                    }
                    
                    if(j == 0){
                        ans += a*p[j];
                    }
                    else{
                        ans += a*(p[j] - p[j-1]);
                    }
                    a = -a;
                    
                }
                if(p[p.size()-1] <= que[i]){
                    ans += a*(que[i] - p[p.size()-1]);
                }
            }
            if(p.size() == 0){
                ans = que[i];
            }

            
            int l=0,r=p.size()-1;
            
            if(p.size() == 0){
                p.push_back(que[i]);
            }
            else if (p.size() == 1){
                if(p[0] == que[i])
                    p.erase(p.begin());
                else if(p[0] < que[i])
                    p.push_back(que[i]);
                else    
                    p.insert(p.begin(), que[i]);
            }
            else{
                while(l < r){
                    int mid = (l + r)/2;
                    if(mid == l){
                        if(p[r] > que[i] && p[l] < que[i])
                            p.insert(p.begin() + r, que[i]);
                        else if(p[r] == que[i])
                            p.erase(p.begin()+r);
                        else if(p[l] == que[i])
                            p.erase(p.begin()+l);
                        break;
                    }
                    
                    
                    if(p[mid] > que[i]){
                        r = mid;
                        continue;
                    }else if(p[mid] < que[i]){
                        l = mid;
                        continue;
                    }else{
                        p.erase(p.begin()+mid);
                        break;
                    }
                }
            }
            
            printf("%d\n", ans);
        }
        
        
    }
    
	return 0;
}
