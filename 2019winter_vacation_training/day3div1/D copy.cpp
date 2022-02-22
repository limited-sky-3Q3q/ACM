#include <iostream>
#include <cmath>
using namespace std;
    
unsigned long long lowest_and_highest[100000][2];
int main()
{
    int X,Y,a,b;
    int N;
    for(int i = 0;i<100000;i++)
    {
        lowest_and_highest[i][0] = 1000000;//0表示最低点
        lowest_and_highest[i][1] = 0;
    }
    cin>>X>>Y>>N;

    for(int i=0;i<N;i++)
    {
        scanf("%u%u", &a , &b);
        if(b < lowest_and_highest[a][0])b = lowest_and_highest[a][0];
        if(b > lowest_and_highest[a][1])b = lowest_and_highest[a][1];
    }

    unsigned long long average = 0;
    int counter = 0;
    for(int i = 0;i < X;i++)
    {
        if(lowest_and_highest[i][1] >= lowest_and_highest[i][0])
        {average += lowest_and_highest[i][1] + lowest_and_highest[i][0]; counter++;}
    }
    average /= counter*2;
    
    int lower,upper;
    if(int(average)+100<0)lower = 0;
    else lower = int(average)-100;
    if(int(average)+100>Y)lower = Y;
    else lower = int(average)+100;
    unsigned long long  shortest = -1;
    unsigned long long d = 0;
    for(int i = lower;i < upper; i++)
    {
        d = 0;
        for(int j = lower;j < upper;j++)
        {
            for(int k = 0;k < X; k++)
            {
                if(lowest_and_highest[k][0]>lowest_and_highest[k][1])continue;
                if(i <= lowest_and_highest[k][0])
                {
                    d += lowest_and_highest[k][1] - i;
                }
                else
                if(i >= lowest_and_highest[k][1])
                {
                    d += i - lowest_and_highest[k][0];
                }
                else d += lowest_and_highest[k][1] - lowest_and_highest[k][0];    
            }
            if(d < shortest)d = shortest;
        }
    }
    cout<< d*2 + X - 1;

    return 0;
}