#include<bits/stdc++.h>
using namespace std;

const long long Mod=998244353;
long long n,m,sum=1;
int main () {
	cin>>n>>m;
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		sum=sum*(m-1);
		if(sum>Mod) {
			sum=sum%Mod;
		}
	}
	if(n%2==0) sum+=m-1;
	else sum-=m-1;
	cout<<sum%Mod;
	return 0;
}
