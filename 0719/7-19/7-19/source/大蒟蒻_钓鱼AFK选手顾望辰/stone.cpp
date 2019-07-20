#include<cstdio>
int T,n;
double p,q,f[1010],g[1010],a,b,a_,b_;
int main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lf%lf",&n,&p,&q);
		if(n>1000) n=1000;
		f[0]=0.0;
		g[0]=1.0;
		for(int i=1;i<=n;++i)
		{
			if(f[i-1]>g[i-1])
			{
				a=1-p;
				b=1-q;
			}
			else
			{
				a=p;
				b=q;
			}
			a_=1-a;
			b_=1-b;
			f[i]=(a*g[i-1]+a_*b*f[i-1])/(1-a_*b_);
			g[i]=(b*f[i-1]+a*b_*g[i-1])/(1-a_*b_);
		}
		printf("%.6lf\n",f[n]);
	}
	return 0;
}
