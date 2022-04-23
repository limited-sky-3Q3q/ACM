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


int main(){
	char ch;
	map<string, double>count;
	string months[12] = {"January","February","March",
						"April","May","June",
						"July","August","September",
						"October","November","December"};
	int x;

	for(int month_i=1; month_i<=12; month_i++){
		string month_str = "";
		if((ch=getchar())!='\n'){
			month_str.push_back(ch);
		}
		while((ch=getchar())!=':'){
			month_str.push_back(ch);
		}
		cin>>x;

		count[month_str] = 0;
		for(int i=0; i<x; i++){
			string cost_name = "";
			double cost = 0;
			while((ch=getchar())!=':'){
				cost_name.push_back(ch);
			}
			cin>>cost;
			count[month_str] += cost;
		}
	}
	
	
	for(int i=0; i<12; i++){
		cout<<months[i];
		if(count[months[i]] >= 0.00){
			printf(":+%.2f\n", count[months[i]]);
		}
		else{
			printf(":%.2f\n", count[months[i]]);
		}
	}

	int max_month = 11, min_month = 11;
	for(int i=11; i>=0; i--){
		if(count[months[max_month]] <= count[months[i]]){
			max_month = i;
		}
		if(count[months[min_month]] >= count[months[i]]){
			min_month = i;
		}
	}

	cout<<months[min_month]<<' '<<months[max_month];
	return 0;
}

