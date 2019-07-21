#include<bits/stdc++.h>
using namespace std;
long long T,H;
long long largest(int n) {
	if (n<1) return -1;
	if (n==1) return 1;
	while (n>1) {
		for(int i=2; i<=n; i++) {
			if (n==i) return n;
			if(n%i==0) {
				n = n/i;
				break;
			}
		}
	}
}
int check(long long x) {
	int pd=0;
	for (int j=2; (long long)(j*j)<=x; j++) {
		if (x%j==0) {
			pd=1;
			break;
		}
	}
	if (pd) return false;
	else return true;
}
int main() {
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	scanf("%d",&T);
	for (int i=1; i<=T; i++) {
		scanf("%d",&H);
		if (check(H)) cout<<"Prime"<<endl;
		else cout<<largest(H)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
