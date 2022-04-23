/************************************************
 * Auther        : SR
 * Date          : 2022-04-06 18:38:20
 * LastEditTime  : 2022-04-06 20:58:39
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

vector<int>ans;

// dfs
bool has_circle(vector<vector<int> >&edges, vector<bool>& vis, int u){
	
	for(auto& v : edges[u]){
		if(!vis[v]){
			vis[v] = true;
			if(has_circle(edges, vis, v)){
				return true;
			}
			vis[v] = false;
		}
		else{// find circle
			return true;
		}
	}
	ans.push_back(u);
	return false;
}

int main(){
	int n, m, v;
	vector<vector<int> >edges;
	vector<bool>vis;
	vector<bool>vis_circle;

	cin>>n>>m;
	edges = vector<vector<int> >(n, vector<int>());
	vis = vector<bool>(n, false);
	vis_circle = vector<bool>(n, 0);

	for(int i=0; i<n; i++){
		int count=0;
		cin>>count;
		getchar();
		for(int j=0; j<count; j++){
			cin>>v;
			getchar();
			edges[i].push_back(v);
		}
	}

	
	// activate(edges, vis, m);
	// bfs 一定可以启动
	// queue<int>Q;
	// Q.push(m);
	// vis[m] = true;
	// while(!Q.empty()){
	// 	int u = Q.front();
	// 	Q.pop();

	// 	for(auto& a:edges[u]){
	// 		if(!vis[a]){
	// 			vis[a] = true;
	// 			Q.push(a);
	// 		}
	// 	}
		
	// }
		vis_circle[m] = true;
	if(has_circle(edges, vis_circle, m)){// dfs
		cout<<-1;
	}
	else{// ok
		bool flag=false;
		sort(ans.begin(), ans.end());
		for(auto& a: ans){
			if(a == m){
				continue;
			}

			if(flag){
				cout<<','<<a;
			}
			else{
				cout<<a;
				flag=true;
			}
		}

		if(!flag){
			cout<<"null";
		}
	}


	return 0;
}
