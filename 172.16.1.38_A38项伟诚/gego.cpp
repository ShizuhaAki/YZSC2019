# include<bits/stdc++.h>
using namespace std;

int n,m;
long long s;

long long pow_mod(long long a,long long b,long long c)
{
	if (b==0) return 1;
	int d=pow_mod(a*a%c,b/2,c);
	if (b%2==1) d=d*a%c;
	return d;
    
}

int main()
{
	freopen("gego.in","r",stdin);
	freopen("gego.out","w",stdout);
	
    cin>>n>>m;
    
    if (n==1)
	{
		cout<<m%998244353;
		return 0;
	}
    else if ((m==2)&&(n&2==0))
	{
		cout<<2%998244353;
		return 0;
	} 
    else if ((m==2)&&(n&2==1))
	{
		cout<<0%998244353;
		return 0;
	}
	
	s=pow_mod(m-1,n,998244353);
	if (n%2==0) s=s+m-1;
	else s=s-m+1;
	
    cout<<s%998244353;
    
	return 0;
}

