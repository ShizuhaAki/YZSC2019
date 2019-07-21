#include<bits/stdc++.h>
using namespace std;
int n,k,qwq[5000001],x;

int main()
{
	freopen("sgcd.in","r",stdin);
	freopen("sgcd.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		for(long long j=1;j<=sqrt(x);j++)
		{
			if(x%j==0)
			{
				qwq[j]++;
				qwq[x/j]++;
				if(x==j*j)
				{
					qwq[j]--;
					break;
				}
			}
		}
	}
	for(int i=4;i>0;i--)
	{
		if(qwq[i]>=k)
		{
			cout<<i;
			return 0;
		}
//	cout<<qwq[i]<<' '
	}
	return 0;
}
