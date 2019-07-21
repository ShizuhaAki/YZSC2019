# include <bits/stdc++.h>
using namespace std;

int n,m;
double f[1001][1001];

int main()
{
    freopen("pattern.in","r",stdin);
    freopen("pattern.out","w",stdout);
    
	cin>>n>>m;
    
    if (m<n)
    {
    	cout<<"0.0000";
    	return 0;
	}
	
    f[1][1]=1;
    for (int i=2;i<=m;i++)
    {
    	for (int j=1;j<=n;j++)
    	{
    		f[i][j]=f[i-1][j]*j/n+f[i-1][j-1]*(n-j+1)/n;
		}
	}
    
	cout<<fixed<<setprecision(4)<<f[m][n];
    
	return 0;
}

