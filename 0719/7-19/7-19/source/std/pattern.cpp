//http://hzwer.com/3694.html 
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
double f[1005][1005];
int main()
{
    freopen("pattern.in","r",stdin);
    freopen("pattern.out","w",stdout);
    scanf("%d%d",&n,&m);
    f[0][0]=1;
    for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			f[i][j]=f[i-1][j]*((double)j/n)+f[i-1][j-1]*((double)(n-j+1)/n);
		}
    printf("%.4lf",f[m][n]);
    return 0;
}
