#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int n, m;
inline void init(void){
	cin >> n >> m;
}
ll fast_pow(int base, int t){
	ll ret = 1;
	for(; t; t >>= 1){
		if((t & 1) == 1)
			ret = (ret * base) % MOD;
		base = (base * base) % MOD;
	}
	return ret;
}
ll ans;
inline void work(void){
	if(n == 1)
		cout << m % MOD;
	else if(n == 2)
		cout << ((m % MOD) * ((m - 1) % MOD)) % MOD;
	else if(n == 3)
		cout << ((m % MOD) * ((m - 1) % MOD) * ((m - 2) % MOD)) % MOD;
	else{
		ll p = fast_pow(-1, n);
		ans = (fast_pow(m - 1, n) % MOD) + ((p * (m - 1) + MOD) % MOD);
		ans  = (ans + MOD) % MOD;
		cout << ans;
	}
	
	
}

int main(){
	freopen("geog.in", "r", stdin);
	freopen("geog.out", "w", stdout);
	init();
	work();
	return 0;
}

