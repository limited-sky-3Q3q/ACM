#include <iostream>
#include <cmath>
using namespace std;

unsigned long long xy[100000][100000]={0};
int main()
{

    int X,Y;
    int N;
    unsigned long long x[100000]={0},y[100000]={0};
    cin>>X>>Y>>N;
    for(int i=0;i<N;i++)scanf("%u%u",&x[i],&y[i]);
    unsigned long long average = 0;
    for(int i=0;i<N;i++)average += y[i];
    average /= 100000;

    unsigned long long d=0,shortest = 1e20;
    
    int lowest,highest;

    if(int(average)-100 <= 0) lowest = 0;
    else lowest = int(average)-100;
    if(int(average)+100 >= Y) highest = Y;
    else highest = int(average) + 100;

    int haha;

    for(int i = lowest;i < highest;i++)
    {
        d = 0;
        for(int j = 0;j < N;j++)d += 2*abs(i - int(y[j]));
        if(d < shortest){shortest = d;haha = i;}
    }
    cout<<haha<<" "<<shortest+X-1;

    return 0;
}