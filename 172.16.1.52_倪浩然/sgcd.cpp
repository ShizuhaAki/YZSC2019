#include<bits/stdc++.h>

using namespace std;
const int MAXN = 500000 + 10;
const int INF = 0x3f3f3f3f;
int inc[MAXN], p[MAXN], r[MAXN], m, k, n, a[MAXN];
inline void factor(int x){
	m = 0;
	for(int i = 2; i * i <= x; ++ i){
		if((x % i) == 0){
			p[++ m] = i; r[m] = 1;
			x /= i;
			while((x % i) == 0){
				r[m] ++; x /= i;
			}
		}
	}
	if(x != 1){
		p[++ m] = x; r[m] = 1;
	}
}

inline void push_tag(int step, int now){
	if(step == m + 1){
		inc[now]++; return;
	}
	int j = now;
	for(int i = 1; i <= r[step]; ++ i){
		j *= p[step];
		push_tag(step + 1, j);
	}
	push_tag(step + 1, now);
}
int maxx = 0;
inline void init(void){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]); maxx = max(a[i], maxx);
		factor(a[i]); push_tag(1, 1);
	}
}

inline void work(void){
	for(int i = maxx; i >= 1; -- i){
		if(inc[i] >= k){
			cout << i; return;
		}
	}
}

int main(){
	freopen("sgcd.in", "r", stdin);
	freopen("sgcd.out", "w", stdout);
	init();
	work();
	return 0;
}
