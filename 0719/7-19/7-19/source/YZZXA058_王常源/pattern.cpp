#include<bits/stdc++.h>
using namespace std;
const int MAXA=1010;
double p[MAXA][MAXA];
int n,m;
inline void solve()
{
	p[0][0]=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			double tmp1=p[i-1][j]*j/n;
			double tmp2=p[i-1][j-1]*(n-j+1)/n;
			p[i][j]=tmp1+tmp2;
		}
}

int main()
{
	freopen("pattern.in","r",stdin);
	freopen("pattern.out","w",stdout);
	scanf("%d%d",&n,&m);
	solve();
	printf("%.4lf",p[m][n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
