# include <bits/stdc++.h>
using namespace std;

int CAS;
long long a,s;

long long isprime(long long a)
{
	for (int i=2;i*i<=a;i++)
	{
		if (a%i==0) return isprime(a/i);
	}
	return a;
}

int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	
	cin>>CAS;
	for (int i=1;i<=CAS;i++)
	{
		cin>>a;
		if (a==2)
		{
			cout<<"prime"<<endl;
			continue;
		}
		
		s=isprime(a);
		if (s==a)
		{
			cout<<"prime"<<endl;
		}
		else
		{
			cout<<s<<endl;
		}
	}

	return 0;
}

