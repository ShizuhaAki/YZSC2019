#include<bits/stdc++.h>
using namespace std;
long long t,a,x;

int main()
{
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		scanf("%lld",&a);
		a+=1;
		x=0;
		
			int flag=0;
			for(long long j=1;j<=sqrt(a);j++)
			{
				if(a%j==0)
				{
					x+=2;
					if(a==j*j)
					{
						x--;
						break;
					}
				}
			}
		
		cout<<x<<endl;
	}
	return 0;
}
