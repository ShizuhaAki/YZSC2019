//h=xy+x+y  =>  h+1=(x+1)(y+1)
#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cmath>
using namespace std;

inline int solve(int x) {
	int res = 0, r = sqrt(x);
	for(register int i = 1; i <= r; ++i) {
		res += (x % i == 0);
	}
	res *= 2;
	return r * r == x ? res - 1 : res;
}

int main() {
	freopen("hash.in", "r", stdin);
	freopen("hash.out", "w", stdout);
	int T, h;
	scanf("%d", &T);
	for(;T--;) {
		scanf("%d", &h);
		printf("%d\n", solve(h + 1));
	}
	return 0;
}
