/**
 * TODO Auther: by SR
 * Date: 2020-02-03 17:16:54
 * LastEditTime: 2020-02-03 17:50:49
 * ! 今日运势: 吉，无bug
 * *其实随便一种排序都可以求逆序列数的吧。
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;

void merge_sort(int, int);

int que[MAXN],temp[MAXN];
ll ans;
int main(){
	int n;
    cin >> n;
    for(register int i = 1; i <= n; i++){
        cin >> que[i];
    }
    merge_sort(1,n);
    cout << ans;
	return 0;
}

void merge_sort(int l, int r){
    //cout << l <<" "<<r<<"\n";
    if(l == r){
        return;
    }
    int mid = l + ((r-l)>>1);
    //cout << mid<<"\n";
    merge_sort(l, mid);merge_sort(mid+1, r);


    int pos = l, p1 = l, p2 = mid+1;
    while(p1 <= mid && p2 <= r){
        if(que[p1] <= que[p2]){
            temp[pos++] = que[p1++];
        }
        else{
            ans += mid+1 - p1;
            temp[pos++] = que[p2++];
        }
    }
    while(p1 <= mid){
        temp[pos++] = que[p1++];
    }
    while(p2 <= r){
        temp[pos++] = que[p2++];
    }

    for(register int i = l; i <= r; i++){
        que[i] = temp[i];
    }
    return;
}
