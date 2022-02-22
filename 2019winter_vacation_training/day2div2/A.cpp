//A bySR
#include <iostream>
#include <vector>
using namespace std;

struct person
{
    int power;
    unsigned long long win_times;
};
void swap(person* a,person* b)
{
    person* c;
    c = a; a = b; b = c;
    return;
}


int main()
{
    person a[502]={{0,0}};
    int n, r=1, l=0,s;
    unsigned long long k;
    //scanf("%d%ull",&n,&k); ???会溢出？
    cin>>n>>k;
    for(int i=0;i<n;i++)scanf("%d",&a[i].power);

    for(int i = 1;i <= n-1;i++)
    {
        if(a[l].power > a[r].power)
        {
            a[l].win_times++;
            r++;
        }
        else
        {
            a[r].win_times++;
            l = r + 1;
            swap(l,r);
        }
        if(a[l].win_times == k)
        {
            cout<<a[l].power;
            return 0;
        }
    }
    printf("%d",a[l].power);
    return 0;
}