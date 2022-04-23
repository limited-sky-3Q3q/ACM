/************************************************
 * Auther        : SR
 * Date          : 2022-04-12 19:33:44
 * LastEditTime  : 2022-04-12 20:32:51
************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int maxn = 100;

int x_now, y_now, x_touch, y_touch;

struct pos{
    int x,y;
};


int touch(vector<pos>& touch_blocks, vector<vector<char> >& maze, int touch_i){

    vector<vector<int> > vis(maze.size(), vector<int>(maze[0].size(), 0));
    vis[x_now][y_now] = 1;

    int target_x = touch_blocks[touch_i].x - 1, target_y = touch_blocks[touch_i].y - 1;
    queue<pos>Q;
    Q.push({x_now, y_now});
    bool flag = true;

    while(!Q.empty()){
        int x = Q.front().x, y = Q.front().y;
        Q.pop();
        
        if((x ==  target_x && (y-1 == target_y || y+1 == target_y))
            ||
            (y ==  target_y && (x-1 == target_x || x+1 == target_x))){
            
            x_now = x;
            y_now = y;
            flag = false;
            break;
        }
        
        // moveable
        if(x+1 < maze[0].size() && maze[y][x+1] != '#' && !vis[y][x+1]){
            vis[y][x+1] = vis[y][x] + 1;
            Q.push({x+1, y});
        }
        if(x-1 >= 0 && maze[y][x-1] != '#' && !vis[y][x-1]){
            vis[y][x-1] = vis[y][x] + 1;
            Q.push({x-1, y});
        }
        if(y+1 < maze.size() && maze[y+1][x] != '#' && !vis[y+1][x]){
            vis[y+1][x] = vis[y][x] + 1;
            Q.push({x, y+1});
        }
        if(y-1 >= 0 && maze[y-1][x] != '#' && !vis[y-1][x]){
            vis[y-1][x] = vis[y][x] + 1;
            Q.push({x, y-1});
        }

    }

    if(flag){
        return -1;
    }
    else{
        return vis[y_now][x_now] - 1;
    }
}

int main(){
	int n,m,k;
    int x_end, y_end;
    cin>>n>>m>>k;

    vector<vector<char> > maze(n, vector<char>(m));
    vector<pos>touch_blocks;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>maze[i][j];
            if(maze[i][j] == 'S'){
                x_now = j;
                y_now = i;
            }
            else if(maze[i][j] == 'F'){
                x_end = j;
                y_end = i;
            }
        }
    }
    
    touch_blocks.push_back({0, 0});
    for(int i=0; i<k; i++){
        pos ppp;
        cin>>ppp.x>>ppp.y;
        touch_blocks.push_back(ppp);
    }

    int ans = 0;
    for(int i=1; i<touch_blocks.size(); i++){
        int temp = touch(touch_blocks, maze, i);
        if(temp == -1){
            cout<<temp;
            return 0;
        }

        ans += temp;
    }

    cout<<ans;
	return 0;
}
