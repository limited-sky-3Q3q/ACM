/**
 * TODO Auther: by SR
 * FilePath: \vscodefile\ACM\2019winter_vacation_training\day1div2\K.cpp
 * Date: 2020-02-05 13:15:24
 * LastEditTime: 2020-02-05 15:20:12
 * ! 今日运势: 吉，无bug
 * *BFS,找到最短路径就可以了
**/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<memory.h>
using std::cout;
using std::cin;
typedef long long ll;
const int INF = 0x3f3f3f3f;

void initialize();
void read();
void bfs(int);
void update(int, int);
void output(int, int);
void find_ans(const int x, const int y);

int move[7][7], maze[7][7];
bool ans[7][7];

int shortest = INF;
//bool flag = true;

int main(){
	read();
    initialize();
    bfs(1);
    
    find_ans(5, 5);
    output(1,1);
	return 0;
}

void initialize(){
    memset(move, INF, sizeof(move));
    memset(ans, 0, sizeof(ans));
    move[1][1] = 1;
}
void read(){
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            maze[i][j] = 1;
        }
    }
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            cin >> maze[i][j];
        }
    }
}

void bfs(const int n){
    /*
for(int i = 0; i <= 6; i++){
        for(int j = 0; j <=6; j++){
            if(move[i][j] == INF){
                cout << 0<<" ";
            }
            else cout <<move[i][j]<<" ";
        }
        cout <<"\n";
    }*/

   if(move[5][5] != INF){
       return;
   }
   for(register int i = 1; i <= 5; i++){
       for(register int j = 1; j <= 5; j++){
           if(move[i][j] == n){
               update(i, j);
           }
       }
   }
   bfs(n+1);
}

void update(const int x, const int y){
    if(move[x+1][y] == INF && maze[x+1][y] == 0){
        move[x+1][y] = move[x][y] + 1;
    }
    if(move[x][y+1] == INF && maze[x][y+1] == 0){
        move[x][y+1] = move[x][y] + 1;
    }
    if(move[x-1][y] == INF && maze[x-1][y] == 0){
        move[x-1][y] = move[x][y] + 1;
    }
    if(move[x][y-1] == INF && maze[x][y-1] == 0){
        move[x][y-1] = move[x][y] + 1;
    }
    return;
}

void output(const int x, const int y){
    printf("(%d, %d)\n", x-1, y-1);
    ans[x][y] = false;
    if(ans[x+1][y]){
        output(x+1,y);
    }
    if(ans[x][y+1]){
        output(x,y+1);
    }
    if(ans[x-1][y]){
        output(x-1,y);
    }
    if(ans[x][y-1]){
        output(x,y-1);
    }
    return;
}

void find_ans(const int x, const int y){
    ans[x][y] = true;
    if(x==1 && y==1){
        return;
    }
    int temp = INF,i=0,j=0;
    if(move[x+1][y] < temp){
        i = 1, j = 0;
        temp = move[x+1][y];
    }
    if(move[x][y+1] < temp){
        i = 0, j = 1;
        temp = move[x][y+1];
    }
    if(move[x-1][y] < temp){
        i = -1, j = 0;
        temp = move[x-1][y];
    }
    if(move[x][y-1] < temp){
        i = 0, j = -1;
        temp = move[x][y-1];
    }
    find_ans(x+i, y+j);
    return;
}