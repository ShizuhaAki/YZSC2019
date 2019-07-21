#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll a[]={2,3,5,7,11,13,17,19,23,29};
 
ll t,n,maxx;
 
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
 
ll cheng(ll u,ll v,ll mod)
{
	ll res=(long double)u/mod*v+1e-8;
	res=u*v-mod*res;
	return res<0 ? res+mod:res; 
}
 
ll mi(ll u,ll v,ll mod)
{
	ll res=1;u%=mod;
	for(;v;v>>=1,u=cheng(u,u,mod)) if(v&1) res=cheng(res,u,mod);
	return res;
}
 
ll gcd(ll u,ll v)
{
	return v ? gcd(v,u%v):u;
}
 
bool chec(ll u,ll mod,ll k,ll v)
{
	ll now=mi(u,k,mod),las=now;
	for(int i=1;i<=v;i++)
	{
		now=cheng(now,now,mod);
		if(now==1 && las!=1 && las!=mod-1) return 0;
		las=now;
	}
	return now==1 ? 1:0;
}
 
bool mr(ll u)
{
	if(u<=1) return 0;
	ll res=u-1,now=0;
	while(!(res&1)) res>>=1,now++;
	for(int i=0;i<9;i++)
	{
		if(u==a[i]) return 1;
		if(!chec(a[i],u,res,now)) return 0;
	}
	return 1;
}
 
ll chan(ll u,ll v)
{
	ll k=2,x=rand()%u,y=x,p=1;
	for(ll i=1;p==1;i++)
	{
		x=(cheng(x,x,u)+v)%u;
		p=y>x ? y-x:x-y;p=gcd(p,u);
		if(i==k) y=x,k+=k;
	}
	return p;
}
 
void solve(ll u)
{
	if(u==1) return;
	if(mr(u))
	{
		maxx=max(maxx,u);return;
	}
	ll now=u;
	while(now==u) now=chan(u,rand()%(u-1));
	solve(now);solve(u/now);
}
 
int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	srand(20190720);t=read();
	while(t--)
	{
		n=read();maxx=0;solve(n);
		if(n==maxx) puts("Prime");
		else printf("%lld\n",maxx);
	}
	return 0;
}
