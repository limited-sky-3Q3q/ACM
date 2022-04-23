/************************************************
 * Auther        : SR
 * Date          : 2022-04-12 20:35:06
 * LastEditTime  : 2022-04-15 20:37:32
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


int main()
{
    // 局部变量声明
    char var = 'D';
	{
			int cnt = 0; // 定义变量
	}
    switch (var)
    {
		case 'A':
			cout << "Excellent." << endl
				<< cnt;
			break;
		case 'B':
		case 'C':
			++cnt;
			cout << "Good." << endl
				<< cnt;
			break;
		case 'D':
			cout << "Not bad." << endl
				<< cnt;
			break;
		case 'F':
			cout << "Bad." << endl
				<< cnt;
			break;
		default:
			cout << "Bad." << endl
				<< cnt;
    }

    return 0;
}