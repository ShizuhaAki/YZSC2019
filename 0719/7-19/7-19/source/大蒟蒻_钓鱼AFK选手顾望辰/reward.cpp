#include<cstdio>
#include<iostream>
using namespace std;
int m,n,p[20],d[20],pow2[20],x;
double f[110][70000];
int main()
{
	freopen("reward.in","r",stdin);
	freopen("reward.out","w",stdout);
	pow2[1]=1;
	for(int i=2;i<17;i++) pow2[i]=pow2[i-1]<<1;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i],&x);
		while(x)
		{
			d[i]+=pow2[x];
			scanf("%d",&x);
		}
	}
	for(int i=m;i;i--)
	{
		for(int j=0;j<pow2[n+1];j++)
		{
			for(int k=1;k<=n;k++)
			{
				if((j&d[k])==d[k]) f[i][j]+=max(f[i+1][j],f[i+1][j|pow2[k]]+p[k]);
				else f[i][j]+=f[i+1][j];
			}
			f[i][j]/=(1.0*n);
		}
	}
	printf("%.6lf\n",f[1][0]);
	return 0;
}
