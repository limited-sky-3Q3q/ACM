#include <iostream>
//#include <stdio.h>
using namespace std;

int gcd(int a,int b)
{
    if(b == 0)return a;
    else return gcd(b,a % b);
}

int main()
{
    int n;
    char a[100];
    while(cin>>n)//不能用getchar()
    {
        int b[4]={0,0,0,0};
        cin>>a;
        for(int i = 0;i < n;i++)
        {
            switch(a[i])
            {
                case 'a':
                ++(b[0]);break;
                case 'v':
                ++(b[1]);break;
                case 'i':
                ++(b[2]);break;
                case 'n':
                ++(b[3]);break;
            }
        }
        
        int up = b[0]*b[1]*b[2]*b[3];
        if(up==0)printf("0/1\n");
		else 
		{
			int k=n*n*n*n;
			int g=gcd(k,up);
			printf("%d/%d\n",up/g,k/g);
		}
       
        
    }
    return 0;
}

/*
//F by 五点共圆
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
int gcd(int x,int y)
{
	if(y==0)return x;
	return gcd(y,x%y);
}

int main() 
{
	int n;
	string ch;
	while(cin>>n)
	{
		cin>>ch;
		int a[4]={0,0,0,0};
		for(register int i=0;i<ch.size();i++)
		{
			if(ch[i]=='a'){a[0]++;continue;}
			if(ch[i]=='v'){a[1]++;continue;}
			if(ch[i]=='i'){a[2]++;continue;}
			if(ch[i]=='n'){a[3]++;continue;}
		}
		//cout<<a[0]<<a[1]<<a[2]<<a[3]<<endl;
		int result=a[0]*a[1]*a[2]*a[3];
		if(result==0)cout<<"0/1"<<endl;
		else 
		{
			int k=n*n*n*n;
			int g=gcd(k,result);
			cout<<result/g<<"/"<<k/g<<endl;
		}
	}
}*/