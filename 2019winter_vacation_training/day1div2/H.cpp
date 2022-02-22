/**
 * TODO Auther: by SR
 * Date: 2020-02-04 10:12:40
 * LastEditTime: 2020-02-04 14:16:31
 * ! 今日运势: 吉，无bug
 * *两层冒泡排序，直接解决双重排列，不过好浪费时间。
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<memory.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;

struct eg{
    char nb[29];
    int score=0;
};

int main(){
    eg que[1003], swap;
	int n, m, g, temp, val[13];
    while(cin >> n){
        if(n == 0){
            break;
        }
        cin>>m>>g;
        for(int i = 1; i <= m; i++){
            cin >> val[i];
        }
        int pos, counter = 0;
        for(int i = 1; i <= n; i++){
            cin>>que[i].nb>>temp;
            int pos;
            que[i].score = 0;//!不要忘记初始化！！
            for(int j = 1; j <= temp; j++){
                cin >> pos;
                que[i].score += val[pos];
            }
            if(que[i].score >= g){
                counter++;
            }
        }
        cout<<counter<<"\n";
        
        for(int i = 1; i <= n-1; i++){
            for(int j = 1; j <= n-1; j++){
                if(que[j].score < que[j+1].score){
                    swap = que[j];
                    que[j] = que[j+1];
                    que[j+1] = swap;
                }
                else if(que[j].score == que[j+1].score){
                    if(strcmp(que[j].nb, que[j+1].nb)>0){
                        swap = que[j];
                        que[j] = que[j+1];
                        que[j+1] = swap;
                    }
                }
            }
        }
        for(int i = 1; i <= counter; i++){
            cout <<que[i].nb<<" "<<que[i].score<<"\n";
        }
    }
	return 0;
}
