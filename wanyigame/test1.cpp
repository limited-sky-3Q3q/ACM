/************************************************
 * Auther        : SR
 * Date          : 2022-04-17 14:49:00
 * LastEditTime  : 2022-04-17 15:24:56
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



struct Team{
    int point=0;
    int goals_for=0;
    int goals_against=0;
};

map<string, Team>teams;

bool cmp(string& A, string& B){
    if(teams[A].point != teams[B].point){
        return teams[A].point > teams[B].point;
    }
    else if(teams[A].goals_for - teams[A].goals_against 
            != 
            teams[B].goals_for - teams[B].goals_against){
        return  teams[A].goals_for - teams[A].goals_against
                >
                teams[B].goals_for - teams[B].goals_against;
    }
    else if(teams[A].goals_for != teams[B].goals_for){
        return teams[A].goals_for > teams[B].goals_for;
    }
    
    return A < B;
}

int main(){
	int T;
    cin>>T;
    while(T--){
        teams.clear();
        teams = map<string, Team>();
        for(int i=0; i<6; i++){
            string name;
            cin>>name;
            cin >>teams[name].point
                >>teams[name].goals_for
                >>teams[name].goals_against;
        }

        for(int i=0; i<3; i++){
            string name1, name2;
            cin>>name1>>name2;
            int goals_gor_name1, goals_gor_name2;
            cin>>goals_gor_name1>>goals_gor_name2;

            if(goals_gor_name1 > goals_gor_name2){
                teams[name1].point += 3;
            }
            else if(goals_gor_name1 == goals_gor_name2){
                teams[name1].point += 1;
                teams[name2].point += 1;
            }
            else{
                teams[name2].point += 3;
            }
            teams[name1].goals_for += goals_gor_name1;
            teams[name2].goals_for += goals_gor_name2;
            teams[name1].goals_against += goals_gor_name2;
            teams[name2].goals_against += goals_gor_name1;
        }

        vector<string>teams_name;
        for(auto &team : teams){
            teams_name.emplace_back(team.first);
        }

        sort(teams_name.begin(), teams_name.end(), cmp);

        for(int i=0; i<6; i++){
            string name = teams_name[i];
            cout<<name<<' '
                <<teams[name].point<<' '
                <<teams[name].goals_for<<' '
                <<teams[name].goals_against
                <<endl;
        }
        cout<<"END\n";
    }
	return 0;
}
