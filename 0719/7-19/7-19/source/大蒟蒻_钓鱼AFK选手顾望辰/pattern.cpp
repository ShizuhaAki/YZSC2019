#include<cstdio>
int n,m;
double f[1010][1010];
int main()
{
	freopen("pattern.in","r",stdin);
	freopen("pattern.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[0][0]=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++) f[i][j]=f[i-1][j-1]*(1.0*(n-j+1.0))/(1.0*n)+f[i-1][j]*(1.0*j/n);
	printf("%.4lf\n",f[m][n]);
	return 0;
}
