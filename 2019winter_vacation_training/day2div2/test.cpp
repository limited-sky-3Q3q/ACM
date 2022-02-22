#include<stdio.h>
#include<string.h>
long long a[100010];
int l[100010],r[100010];
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        l[1]=1,r[n]=n;
        for(int i=2;i<=n;i++)
        {
            int t=i;
            while(t>1&&a[t-1]>=a[i])
                t=l[t-1]; // 每一个a【i】对应一个l【i】和r【i】。  l[i]是求左边连续比他大的下标最小值
 
            l[i]=t;
        }
        for(int i=n-1;i>=1;i--)
        {
            int t=i;
            while(t<n&&a[t+1]>=a[i])
                t=r[t+1];  //r【i】 是求右边连续比他大的下标的最大值
            r[i]=t;   //记录 i矩形的最右端
        }


        
        long long maxx=0;
        for(int i=1;i<=n;i++)
        {
            long long sum=(r[i]-l[i]+1)*a[i];
            if(sum>maxx)      // 更新maxx的值
                maxx=sum;
        }
        printf("%lld\n",maxx);
    }
}
 