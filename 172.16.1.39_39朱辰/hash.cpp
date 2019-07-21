#include<bits/stdc++.h>
#define ll unsigned long long 
using namespace std;
int t;
ll h;
ll  if_prime(ll a)
{
	ll sqr=floor(sqrt(a)),ans=0;
	for(ll i=1;i<=sqr;++i){
		if(a%i==0){
			ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>h;
		if(floor(sqrt(h+1))*floor(sqrt(h+1))!=h+1){
			cout<<(if_prime(h+1)*2)<<endl;
		}else{
			cout<<(if_prime(h+1)*2-1)<<endl;
		}
		
	}
	return 0;
}

