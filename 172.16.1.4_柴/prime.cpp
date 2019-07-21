#include<bits/stdc++.h>
using namespace std;
long long c,a,x;
long long emm(long long n)
{
	long long t=0;
	for (long long i = 2; i<= sqrt(n); ++i)
		while (n % i == 0)
		{ 
			t=i;
			n /= i;
		}
	return max(t,n);
}
int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	cin>>c;
	for(int i=0;i<c;i++)
	{
		cin>>a;
		x=emm(a);
		if(x==a)
		cout<<"Prime"<<endl;
		else 
		cout<<x<<endl;
	}
	return 0;
}
