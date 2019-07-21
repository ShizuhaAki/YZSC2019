#pragma GCC optimize("Ofast")
#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
#include<iostream>
using namespace std;
const int MAXN = 500001;
int n, k, a[MAXN], maxa;
map<int, int>m;

int main() {
	freopen("sgcd.in", "r", stdin);
	freopen("sgcd.out", "w", stdout);
	int n, k, r;
	scanf("%d %d", &n, &k);
	for(register int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		r = sqrt(a[i]);
		for(register int j = 1; j <= r; ++j) {
			if(a[i] % j == 0) {
				++m[j];
				++m[a[i] / j];
			}
		}
		if(r * r == a[i]) --m[r];
	}
	
	for(register map<int, int>::reverse_iterator i = m.rbegin(); i != m.rend(); ++i) {
		if((*i).second >= k) {
			printf("%d", (*i).first);
			return 0;
		}
	}

	return 0;
}
