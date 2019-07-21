#include<bits/stdc++.h>
using namespace std;

int T,h;
int f(int x)
{
	int cnt=0;
	for(int i=1;i*i<x;i++)
	{
		if(x%i==0)
		{
			cnt++;
		//	cout<<i<<" "<<x/i<<endl;
		}
	}
	cnt*=2;
	int k=(int)sqrt(x);
	if(k*k==x) cnt++;
	return cnt;
}
int main()
{
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&h);
		h++;
		printf("%d\n",f(h));
	}
}
