#include<bits/stdc++.h>
using namespace std;
const int MAXA=100100;
int calc[MAXA];
int a[MAXA],f[MAXA];
inline void init()
{
	    for (int i=2;i<=MAXA;i++)
        if (!a[i])
        {
            for (int j=i;j<=MAXA;j+=i)
                a[j]=1;
            calc[++calc[0]]=i;
        }
}
int main()
{
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	init();
    int t,n;
    scanf("%d",&t);
    while (t--)
    {
        int flag;
        memset(f,0,sizeof(f));
        scanf("%d",&n);
        n++;
        do
        {
            flag=false;
            for (int i=1;i<=calc[0];i++)
                if (n%calc[i]==0)
                {
                    flag=true;f[calc[i]]++;
                    n/=calc[i];break;
                }
        }while(flag);
        int ans=1;
        for (int i=1;i<=calc[0];i++)
            if (f[calc[i]])
                ans*=(f[calc[i]]+1);
        if (n!=1)   ans*=2;
        printf("%d\n",ans);
    }
    return 0;
}
