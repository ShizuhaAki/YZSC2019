#include<bits/stdc++.h>

using namespace std;
const int MAXN = 500000;
int random(int x){
	return (rand() * rand()) % x + 1;
}
inline void init(void){
	srand(time(0));
	int n = MAXN,  k = random(n);
	printf("%d %d\n", n, k);
	for(int i = 1; i <= n; ++ i){
		printf("%d ", random(MAXN));
	} 
}

inline void work(void){
	
}

int main(){
	freopen("sgcd.in", "w", stdout);
	init();
	work();
	return 0;
}
