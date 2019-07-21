#include <bits/stdc++.h>
#define maxN 65605

using namespace std;

typedef long long ll;

ll read (){
	ll ret=0;char c=getchar();
	while (c>'9'||c<'0')c=getchar();
	while (c<='9'&&c>='0')ret=ret*10+c-'0',c=getchar();
	return ret;
}

ll n,ans,prime[maxN],cnt;
bool isprime[maxN],book[maxN];

void eratos () {
	ll n = 65537;
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

bool div (ll x){
	bool ret=1;
	ans=0;
	for (int i=1;prime[i]*prime[i]<=x;i++){
		while (x%prime[i]==0){
			ret=0;
			x/=prime[i];
			ans=max(ans,prime[i]);
//			if (isp(x))ans=max(ans,x);
		}
	}
	if (ret==1)return ret;
	if (x!=1)ans=max(ans,x);
	return ret;
}

bool baoli (ll x){
	ll anss=0;
	bool ret=1;
	for (ll i=2;i*i<=x;i++){
//		cout<<'!';
//		if (i==4649)cout<<'!';
		if (x%i==0)anss=max(anss,i),ret=0;
		while (x%i==0){
			x/=i;
		}
	}
	if (ret==1){
		cout<<"Prime"<<endl;
		return ret;
	}
	if (x!=1)anss=max(anss,x);
	cout<<anss<<endl;
}

int main (){
	freopen ("prime.in","r",stdin);
	freopen ("prime.out","w",stdout);
	n=read();
	eratos ();
	for (ll i=1;i<=n;i++){
		ll x=read();
		if (x>2147483648){
			baoli(x);
			continue;
		}
		if (!div(x)){
			cout<<ans<<endl;
			continue;
		}
		else {
			cout<<"Prime"<<endl;
			continue;
		}
	}
	return 0;
}

