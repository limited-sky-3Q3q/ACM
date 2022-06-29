/************************************************
 * Auther        : SR
 * Date          : 2022-04-25 15:09:13
 * LastEditTime  : 2022-06-29 13:56:28
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
#include<functional>


using namespace std;

template<class T>
class share_ptr{
    private:
        T* _ptr;
        int* _count;
    public:
        share_ptr(T* ptr = nullptr) : _ptr(ptr), _count(new int(1)){cout<<"I in 1 !\n";}
        share_ptr(const share_ptr &s){
            cout<<"I in 2 !\n";

            _ptr = s._ptr;
            _count = s._count;
            (*_count)++;
        }
        share_ptr& operator=(const share_ptr &s){
            if(--(*(_count)) == 0){
                delete _ptr;
                _ptr = nullptr;
                delete _count;
                _count = nullptr;
            }

            _ptr = s._ptr;
            _count = s._count;
            (*_count)++;

            return *this;
        }

        T* operator->(){
            return _ptr;
        }
        T& operator*(){
            return *_ptr;
        }

        ~share_ptr(){
            cout<<"I quit!\n";
            if(--(*(_count)) == 0){
                cout<<"I die!\n";
                delete _ptr;
                _ptr = nullptr;
                delete _count;
                _count = nullptr;
            }
        }
};

struct tttt{
    virtual int fun(){
        cout<<"!!!!!!\n";
        return 8848;
    }
};

int main()
{
	// share_ptr<int>test1(new int(996)), test2 = test1, test3;
    
    // cout<<*test1<<' '<<*test2<<' '<<(*(test3 = test1));

    tttt A;
    cout<<A.fun();

    return 0;
}