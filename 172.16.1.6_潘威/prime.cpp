#include<bits/stdc++.h>
using namespace std;

int cas;
void f(long long x)
{
	if(x<=1) {
		cout<<x<<endl;
		return ;
	}
	long long a=x;
	for(int i=2;i*i<=a;i++)
	{
		while(a%i==0) 
		{
			if(a==i)
			{
				cout<<a<<endl;
				return ;
			}
			a/=i;
		}
	}
	if(a==x) {
		cout<<"Prime\n";
		return ;
	} else {
		cout<<a<<endl;
	}
}
int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	cin>>cas;
	while(cas--)
	{
		long long x;
		cin>>x;
		f(x);
	}
	return 0;
} 
