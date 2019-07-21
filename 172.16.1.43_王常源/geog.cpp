#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long fpow(int a,int b)
{
	long long ans=1,base=a;
	while(b!=0)
	{
		if(b&1!=0)
		ans=ans*base%MOD;
		base=base*base%MOD;
		b>>=1;
	}
	return ans;
}
inline bool judge(long long a)
{
	if(a%2==0) return 1;
	if(a%2==1) return 0;
}
int main()
{
	freopen("geog.in","r",stdin);
	freopen("geog.out","w",stdout);
	long long ans,n,m;bool jud;
	cin>>n>>m;
	jud=judge(n);
	if(jud==0)
	{
		ans=fpow(m-1,n)+1-m;
		ans%=MOD;
	}
	if(jud==1)
	{
		ans=fpow(m-1,n)+m-1;
		ans%=MOD;
	}
	if(n==1) ans=m;
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
