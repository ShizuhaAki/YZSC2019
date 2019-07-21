#include <bits/stdc++.h>
#define maxN 50005

using namespace std;

typedef long long ll;

ll read (){
	ll ret=0;char c=getchar();
	while (c>'9'||c<'0')c=getchar();
	while (c<='9'&&c>='0')ret=ret*10+c-'0',c=getchar();
	return ret;
}

ll T,a,b,c,d,prime[maxN],cnt,p[maxN],r[maxN],tot,ans;
bool isprime[maxN],book[maxN];

void eratos () {
	ll n = 44730;
	for (ll i=2; i<=n; i++) {
		isprime[i]=1;
	}
//  cout<<'!';
	isprime[0]=isprime[1]=0;
	for (ll i=2; i<=n; i++) {
		if (isprime[i]) {
			prime[++cnt]=i;
			for (ll j=i*i; j<=n; j+=i) {
				isprime[j]=0;
			}
		}
	}
}

void div (ll x) {
//  cout<<'!';

	for (ll i=1; i<=cnt&&x>1; i++) {
		if (x%prime[i]==0) {
			p[++tot]=prime[i];
			while (x%prime[i]==0) {
				x/=prime[i];
				r[tot]++;
//				sum[tot][r[tot]]=sum[tot][r[tot]-1]*prime[i];
			}
		}
	}
	if (x!=1){
		p[++tot]=x;
		r[tot]++;
//		sum[tot][r[tot]]=sum[tot][r[tot]-1]*x;
	}
}

ll calc (){
	ll ret=1;
	for (int i=1;i<=tot;i++){
		ret*=r[i]+1;
	}
	return ret;
}

int main (){
	freopen ("hash.in","r",stdin);
	freopen ("hash.out","w",stdout);
	T=read();
	eratos();
	while (T--){
		ll h= read();
		memset(r,0,sizeof(r));
		ans=0;
		tot=0;
		div (h+1);
		cout<<calc()<<endl;
	}
	return 0;
}

