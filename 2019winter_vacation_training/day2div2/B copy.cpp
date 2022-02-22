#include <iostream>
#include <cstdio>

using namespace std;

int counter1=0,counter2=0;

int main()
{
    int a[100000]={0},b[100000]={0};    

    string c;

    while(cin>>c)//不用判断）和}的先后顺序。。。 最后一行答案也要换行
    {
        
        if(c == "Ctrl+Z")
        {

            bool judge1 =true;
            int d = 0;
            for(int i = 0;i < counter1;i++)
            {
                d += a[i];
                if(d < 0)judge1 = false;   
            }
            if(d > 0)judge1 = false;

            bool judge2 = true;
            d = 0;
            for(int i = 0;i < counter2;i++)
            {
                d += b[i];
                if(d < 0)judge2 = false;   
            }
            if(d > 0)judge2 = false;

            if(judge1 & judge2)cout<<"Right\n";
            else cout<<"Wrong\n";
            for(int i = 0;i < counter1;i++)
            {
                a[i] = 0;
            }
            counter1 = 0;
        }
        else
        {
            for(int i = 0;i<c.size();i++)
            {
                switch(c[i])
                {
                    case '(': ++a[counter1++];break;
                    case ')': --a[counter1++];break;
                    case '{': ++b[counter2++];break;
                    case '}': --b[counter2++];break;
                }
            }
        }
        
    }

    

    return 0;
}