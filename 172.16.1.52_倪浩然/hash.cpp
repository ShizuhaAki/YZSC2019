#include<bits/stdc++.h>

using namespace std;
#define zero(x) (memset(x, 0, sizeof(x)))
const int MAXH = 11000;
inline void init(void){
}
int T, h, p[MAXH], r[MAXH], m;
void search(int x){
	zero(r); zero(p); m = 0;
	for(int i = 2; i * i <= x; ++ i){
		if((x % i) == 0){
			p[++ m] = i; r[m] = 1;
			x /= i;
			while((x % i) == 0){
				x /= i; r[m] ++;
			}
		}
	}
	if(x != 1)
		p[++ m] = x, r[m] = 1;
}
inline long long find_ans(void){
	long long ret = 1;
	for(int i = 1; i <= m; ++ i)
		ret *= (r[i] + 1);
	return ret;
}
inline void work(void){
	cin >> T;
	while(T--){
		cin >> h; 
		search(h + 1);
		cout << find_ans()<< endl;
	}
}

int main(){
	freopen("hash.in", "r", stdin);
	freopen("hash.out", "w", stdout);
	init();
	work();
	return 0;
}
