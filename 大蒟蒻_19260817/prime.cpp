#include<cstdio>
#include<cstdlib>
#define DWT_AK_IOI true
#pragma GCC optimize(3)
using namespace std;
int tester[20]={2,3,5,7,11,13,17,19,61,2333,4567,24251,19260817};
long long n,ans;
long long gcd(long long a,long long b){return b? gcd(b,a%b):a;}
long long qmul(long long x,long long y,long long DWT)
{
	long long ret=x*y-(long long)((1.0L*x*y)/(1.0L*DWT)+1)*DWT;
	while(ret<0) ret+=DWT;
	return ret;
}
long long qpow(long long x,long long y,long long DWT)
{
	long long ret=1;
	while(y)
	{
		if(y&1ll) ret=qmul(ret,x,DWT);
		x=qmul(x,x,DWT);
		y>>=1ll;
	}
	return ret;
}
bool check(long long x,int p)
{
	if(!(x%p)||!qpow(p%x,x-1ll,x)) return false;
	long long k=x-1,t;
	while(!(k&1ll))
	{
		k>>=1;
		t=qpow(p%x,k,x);
		if(t!=1&&t!=x-1) return false;
		if(t==x-1) return true;
	}
	return true;
}
bool isPrime(long long x)
{
	if(x<2) return false;
	for(int i=0;i<13;i++)
	{
		if(x==tester[i]) return true;
		if(!check(x,tester[i])) return false;
	}
	return true;
}
long long DWT_AK_EVERYTHING(long long x,int y)
{
	long long t=0,k=1,rd=rand()%(x-1)+1,v=rd,s=1,d;
	while(DWT_AK_IOI)
	{
		v=(qmul(v,v,x)+y)%x;
		s=qmul(s,abs(v-rd),x);
		t++;
		if(v==rd||s==0) return x;
		if(k==t)
		{
			d=gcd(s,x);
			if(d!=1) return d;
			rd=v;
			k<<=1;
		}
	}
	return DWT_AK_IOI;
}
void dfs(long long x,int t)
{
	if(x==1||x<=ans) return;
	if(isPrime(x))
	{
		if(x>ans) ans=x;
		return ;
	}
	long long y=DWT_AK_EVERYTHING(x,t);
	while(x==y) y=DWT_AK_EVERYTHING(x,t--);
	while(x%y==0) x/=y;
	dfs(x,t);
	dfs(y,t);
}
void GetMax(long long x)
{
	dfs(x,19260817);
	return ;
}
int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	srand(19260817);
	int CAS=0;
	scanf("%d",&CAS);
	while(CAS--)
	{
		ans=0;
		scanf("%lld",&n);
		GetMax(n);
		if(ans==n) printf("Prime\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
