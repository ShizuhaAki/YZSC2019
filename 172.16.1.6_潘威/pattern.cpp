#include<bits/stdc++.h>
using namespace std;
double p[1001][1001];
int main()
{
	freopen("pattern.in","r",stdin);
	freopen("pattern.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==1)
	{
		cout<"1.0000";
		return 0;
	}
	if(n==2)
	{
		double ans=1<<n;
		ans=1.0-1.0/ans;
		printf("%.4lf",ans);
		return 0;
	}
	p[1][1]=1;
	double num=(double)n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j!=1) 
			{
				p[i][j]=1<<(j-1);
				p[i][j]=(double)1.0-1.0/p[i][j];
			}
			if(j<i||j==0)
			{
				p[i][j]=0;
				continue;
			}
			if(i!=1&&j!=1)
			p[i][j]=(double)p[i][j-1]*((double)i)/num;
			p[i][j]+=(double)p[i-1][j-1]*((double)(num-i+1))/num;
		//	cout<<"p["<<i<<"]["<<j<<"]="<<p[i][j]<<endl;
		}
	}
	printf("%.4lf",p[n][m]);
}
