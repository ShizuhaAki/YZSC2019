# include <bits/stdc++.h>
using namespace std;

int a[101];
int n,k;
double f[101][100000],w[101];

int main()
{
	freopen("reward.in","r",stdin);
    freopen("reward.out","w",stdout);
    cin>>k>>n;
    for (int i=1;i<=n;i++)
    {
    	int x;
    	cin>>w[i]>>x;
    	while (x)
    	{
    	    a[i]|=(1<<x-1);
    		cin>>x;
		}
	}
	for (int i=k;i>=1;i--)
	{
		for (int j=(1<<n)-1;j>=0;j--)
		{
			for (int l=1;l<=n;l++)
			{
				if ((j&a[l])==a[l])
				{
					f[i][j]+=max(f[i+1][j],f[i+1][j|(1<<l-1)]+w[l]);
				}
				else f[i][j]+=f[i+1][j];
			}
			f[i][j]/=(double)n;
		}
	}
    cout<<fixed<<setprecision(6)<<f[1][0];
	return 0;
}

