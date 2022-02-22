/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\temp\C.cpp
 * Date: 2020-03-01 13:28:55
 * LastEditTime: 2020-03-01 14:10:58
 * ! 今日运势: 吉，无bug
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
struct position{
    int l,r,i;
}pos[200005];

int posl[200005],posr[200005];
bool cmp1(int a,int b){
    return pos[a].l<pos[b].l;
}
bool cmp2(int a,int b){
    return pos[a].r<pos[b].r;
}
bool buy[200005];
int p[200005],len;

int main(){
    int n;
	cin>>n;
    for(int i=1; i<=n; i++){
        scanf("%d%d",&pos[i].l,&pos[i].r);
        pos[i].i=i;
    }

    int now,ans=0;
    for(int i=1; i<=n; i++){
        posl[i]=posr[i]=i;
    }
    memset(buy, false, sizeof(buy));
    sort(posl+1, posl+n+1,cmp1);
    sort(posr+1, posr+n+1,cmp2);

    int l,r,l_now=1;
    len=0;
    for(int i=1; i<=n; i++){
        if(buy[posr[i]])continue;
        ans++;
        p[len++]=pos[posr[i]].r;
        l=pos[posr[i]].l;
        r=pos[posr[i]].r;
        for(int j=l_now; j<=n; j++){
            if(pos[posl[j]].l>r){
                l_now=j;
                break;
            }
            buy[posl[j]]=true;
        }
    }
    cout<<ans<<"\n";
    for(int i=0; i<len; i++){
        printf("%d ",p[i]);
    }
	return 0;
}
