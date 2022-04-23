/************************************************
 * Auther        : SR
 * Date          : 2022-04-06 18:38:13
 * LastEditTime  : 2022-04-06 19:50:02
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


struct title_and_word{// 标题和正文出现频率
    title_and_word(): title_count(0), word_count(0), 
                    appear_time_title(500000001), appear_time_word(500000001){}
    int title_count, word_count, appear_time_title, appear_time_word;
};

int topN, m;
map<string, title_and_word>frequency;
string title, word;
vector<vector<string> >titles, words;


bool cmp(string A, string B){
    int A_count = frequency[A].title_count*3 + frequency[A].word_count;
    int B_count = frequency[B].title_count*3 + frequency[B].word_count;
    if(A_count != B_count){// condition 1
        return A_count > B_count;
    }

    if(frequency[A].title_count != frequency[B].title_count){
        // condition 2
        return frequency[A].title_count > frequency[B].title_count;
    }

    if(frequency[A].appear_time_title != 500000001 || frequency[B].appear_time_title != 500000001){// 至少一个出现在标题
        // condition 3
        return frequency[A].appear_time_title < frequency[B].appear_time_title;
    }

    // condition 3
    return frequency[A].appear_time_word <  frequency[A].appear_time_word;
}


int main(){
	

    cin>>topN>>m;

    for(int i=0; i<2*m; i++){
        if(i%2){// word
            words.push_back(vector<string>());

            while(cin>>word){
                words.back().push_back(word);
                if(getchar()=='\n'){
                    break;
                }
            }
        }
        else{// title
            titles.push_back(vector<string>());

            while(cin>>title){
                titles.back().push_back(title);
                if(getchar()=='\n'){
                    break;
                }
            }
        }

    }

    int appear_time_title=0, appear_time_word=0;
    for(int i=0; i<m; i++){
        for(auto& w : titles[i]){

            frequency[w].title_count++;

            if(frequency[w].appear_time_title == 500000001){// first appear
                frequency[w].appear_time_title = appear_time_title;
                appear_time_title++;
            }
        }
        for(auto& w : words[i]){

            frequency[w].word_count++;

            if(frequency[w].appear_time_word == 500000001){// first appear
                frequency[w].appear_time_word = appear_time_word;
                appear_time_word++;
            }
        }
    }


    vector<string>all_word;
    for(auto& w : frequency){
        all_word.push_back(w.first);
    }

    sort(all_word.begin(), all_word.end(), cmp);

    for(int i=0; i<topN; i++){
        cout<<all_word[i]<<' ';
    }
	return 0;
}
