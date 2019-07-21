#include<bits/stdc++.h>

using namespace std;
const int MAXN = 25000 + 10;
#define int long long
int a[MAXN], b[MAXN], c[MAXN], n, m;
inline void init(void){
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++ i){
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
	}
	scanf("%lld", &m);
}
string s;
int op, l, r, k, x, t;
inline void Operation1(void){
	for(int i = l; i <= r; ++ i){
		for(int j = 1; j <= t; ++ j){
			for(int k = 0; k < s.size(); ++ k){
				if(s[k] == '0')
					a[i] += b[i] - c[i];
				if(s[k] == '1')
					b[i] += c[i] - a[i];
				if(s[k] == '2')
					c[i] += a[i] - b[i];
			}
		}
	}
}

inline void Operation2(void){
	for(int i = l; i <= r; ++ i){
		if(k == 0)
			a[i] = x;
		if(k == 1)
			b[i] = x;
		if(k == 2)
			c[i] = x;
	}
}

inline int Query(void){
	int ret = 0;
	for(int i = l; i <= r; ++ i){
		if(k == 0)
			ret += a[i];
		if(k == 1)
			ret += b[i];
		if(k == 2)
			ret += c[i];
	}
	return ret;
}
inline void work(void){
	for(int i = 1; i <= m; ++ i){
		scanf("%lld", &op);scanf("%lld%lld", &l, &r);
		if(op == 1){
			cin >> s; scanf("%lld", &t);
			Operation1();
		}
		if(op == 2){
			scanf("%lld%lld", &k, &x);
			Operation2();
		}
		if(op == 3){
			scanf("%lld", &k);
			printf("%lld\n", Query());
		}
	}
}

signed main(){
	freopen("augur.in", "r", stdin);
	freopen("augur.out", "w", stdout);
	init();
	work();
}
