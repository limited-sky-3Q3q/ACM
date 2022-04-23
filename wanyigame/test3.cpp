/************************************************
 * Auther        : SR
 * Date          : 2022-04-17 14:49:08
 * LastEditTime  : 2022-04-17 17:04:45
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

struct Pos{
    int x, y;
};

int n,m,k;
const Pos move_d[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(queue<Pos>Q_now, int depth, vector<vector<int> >& vis, vector<vector<char> >& maze, int& d_now, queue<Pos>& Q_out){
    // 只有更优才更新
    // bfs K层
    if(depth == 0){
        return;
    }
    
    // move
    queue<Pos>Q_next;

    while(!Q_now.empty()){
        Pos pos_now = Q_now.front();
        Q_now.pop();

        for(int i=0; i<4; i++){// move to next level
            Pos pos_next = Pos{pos_now.x + move_d[i].x, pos_now.y + move_d[i].y};
            if( pos_next.x >= 0 && pos_next.x < n
                &&
                pos_next.y >= 0 && pos_next.y < m){// moveable

                if(maze[pos_next.x][pos_next.y] == '-'){
                    if(vis[pos_next.x][pos_next.y] > d_now + 1){
                        vis[pos_next.x][pos_next.y] =  d_now + 1;
                        Q_next.emplace(pos_next);
                        Q_out.emplace(pos_next);
                    }
                }
                else if(maze[pos_next.x][pos_next.y] == 'M'){
                    Q_next.emplace(pos_next);
                }
                else if(maze[pos_next.x][pos_next.y] == 'E'){
                    vis[pos_next.x][pos_next.y] = min(vis[pos_next.x][pos_next.y], d_now + 1);
                    return;
                }
            }
        }
    }

    bfs(Q_next, depth-1, vis, maze, d_now, Q_out);

}

int main(){
    int T;
    cin>>T;
	while(T--){
		
        cin>>n>>m>>k;
        vector<vector<char> >maze(n, vector<char>(m));
        vector<vector<int> >vis(n, vector<int>(m, INF-1));
        queue<Pos>Q;
        Pos end;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>maze[i][j];
                if(maze[i][j] == 'S'){
                    Q.emplace(Pos{i, j});
                    vis[i][j] = 0;
                }
                else if(maze[i][j] == 'E'){
                    end = Pos{i, j};
                }
            }
        }

        while(!Q.empty()){
            Pos pos_now = Q.front();
            Q.pop();

            queue<Pos>first_level;
            first_level.emplace(pos_now);
            bfs(first_level, k, vis, maze, vis[pos_now.x][pos_now.y], Q);// 只有更优才更新 k层

            // if(vis[end.x][end.y] != INF-1){
            //     break;
            // }
        }

        if(vis[end.x][end.y] == INF-1){
            cout<<-1<<endl;
        }
        else{
            cout<<vis[end.x][end.y]<<endl;
        }
	}
	return 0;
}
