#include <iostream>

using namespace std;

int a[100000]={0};

bool judge(int);

bool judge2(int , int );

int main()
{
    int counter=0,counter2=0;
    
    bool flag = false;
    string c;

    while(getline(cin,c))
    {
        if(flag){
            cout<<"\n"; flag = false;}
        if(c == "Ctrl+Z")
        {
            flag = true;
            if(judge(counter))cout<<"Right";
            else cout<<"Wrong";
            for(int i = 0;i < counter;i++)
            {
                a[i] = 0;
            }
            counter = 0;
        }
        else
        {
            for(int i = 0;i<c.size();i++)
            {
                switch(c[i])
                {
                    case '(': ++a[counter++];break;
                    case ')': --a[counter++];break;
                    case '{': ++++a[counter++];break;
                    case '}': ----a[counter++];break;
                }
            }
        }
        
    }

    

    return 0;
}

bool judge(int n)
{
    int d = 0;
    for(int i=0;i < n;i++)
    {
        d +=a[i];
        if(d<0)return false;
    }
    if(d)return false;
    
    int l = 0;d = a[l];int counter = a[0];

    for(int i = 1; i < n; i++)//找到闭合区间
    {
        if(a[i] == a[0] || a[i] == -a[0])
        {
            counter += a[i];
        }
        if(!counter)
        {
            if((i - l) % 2 == 0)return false;

            if(judge2(l+1,i-1)){}
            else return false;
            l = i;
        }
    }
    return true;
}

bool judge2(int l,int r)
{
    if(l + 1 == r)return true;

    int d = a[l];int counter = a[l];

    for(int i = l; i <= r; i++)
    {
        if(a[i] == a[0] || a[i] == -a[0])
        {
            counter += a[i];
        }

        if(!counter)
        {
            if((r - l) % 2 == 0)return false;

            return judge2(l+1,r-1);
        }
    }
    
}