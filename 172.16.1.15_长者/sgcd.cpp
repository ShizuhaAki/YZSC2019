#include<bits/stdc++.h>
#define MAX 10005
using namespace std;
int a[MAX],s[MAX];
int maxn,mm,n,k;
int sq,e;
int main()
{
	freopen("sgcd.in","r",stdin);
	freopen("sgcd.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
		scanf("%d",a+i);
    mm=0;
    for(int i=0;i<n;i++)
	{
        mm=max(a[i],mm);
        sq=(int)sqrt(a[i]*1.0);
        for(int j=1;j<=sq;j++)
		{
            if(a[i]%j==0)
			{
                s[j]++;
                e=a[i]/j;
                if(e!=j)
					s[a[i]/j]++;
            }
        }
    }
    maxn=0;
    for(int i=1;i<=mm;i++)
        if(s[i]>=k)
			maxn = i;
    printf("%d",maxn);
    return 0;
}
