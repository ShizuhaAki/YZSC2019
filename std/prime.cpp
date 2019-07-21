#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#define ll long long 
#define inf 1000000000
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
int n;
ll x,mx;
vector<ll> q;
ll mul(ll a,ll b,ll p)
{
    ll tmp=(a*b-(ll)((long double)a/p*b+1e-8)*p);
    return tmp<0?tmp+p:tmp;
}
ll pow(ll a,ll b,ll p)
{
    ll ans=1;a%=p;
    for(ll i=b;i;i>>=1,a=mul(a,a,p))
        if(i&1)ans=mul(ans,a,p);
    return ans;
}
bool check(ll a,ll n,ll r,ll s)
{
    ll ans=pow(a,r,n),p=ans;
    for(int i=1;i<=s;i++)
    {
        ans=mul(ans,ans,n);
        if(ans==1&&p!=1&&p!=n-1)return 1;
        p=ans;
    }
    if(ans!=1)return 1;
    return 0;
}
bool MR(ll n)
{
    if(n<=1)return 0;
    if(n==2)return 1;
    if(n%2==0)return 0;
    ll r=n-1,s=0;
    while(r%2==0)r/=2,s++;
    for(int i=0;i<10;i++)
        if(check(rand()%(n-1)+1,n,r,s))
            return 0;
    return 1;
}
ll rho(ll n,ll c)
{
    ll k=2,x=rand()%n,y=x,p=1;
    for(ll i=1;p==1;i++)
    {
        x=(mul(x,x,n)+c)%n;
        p=y>x?y-x:x-y;
        p=gcd(n,p);
        if(i==k)y=x,k+=k;
    }
    return p;
}
void solve(ll n)
{//cout<<n<<endl;
    if(n==1)return;
    if(MR(n)){mx=max(n,mx);return;}
    ll t=n;//puts("1");
    while(t==n)t=rho(n,rand()%(n-1)+1);
    //puts("2");
    solve(t);
    solve(n/t);
}
int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout); 
    n=read();//cout<<n<<endl;
    while(n--)
    {
        x=read();//cout<<x<<endl;
        mx=0;
        solve(x);
        if(mx==x)puts("Prime");
        else printf("%I64d\n",mx);
    }
    return 0;
}
