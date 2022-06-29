/************************************************
 * Auther        : SR
 * Date          : 2022-05-29 10:38:58
 * LastEditTime  : 2022-05-29 11:00:32
************************************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;


class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss;
        string s;
        ss << sentence;
        string ans;
        while(ss >> s){
            if(s[0] == '$'){
                bool flag = false;
                for(int i=1; i<s.length(); i++){
                    if(!isdigit(s[i])){
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    ans += ' ' + s;
                    continue;
                }

                double num = stoi(s.substr(1));
                num /= double(100 - discount) / 100.;
                string str = to_string(num);
                s = '$' + str.substr(0, str.find('.') + 3);
            }
            ans += ' ' + s;
            
        }
        cout<<ans;
    }
};

int main(){
    
    string a = to_string(3.45);
	cout<<a.substr(0, a.find(".") + 2 + 1);
	return 0;
}
