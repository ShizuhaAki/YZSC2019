#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define up(l,r,i) for(register int i=l;i<=r;++i)
#define dn(r,l,i) for(register int i=r;i>=l;--i)
using namespace std;
typedef long long   LL;
typedef long double LD;
const int INF =2147483647;
const int SIZE_=100000;
char bef[SIZE_+3],*p1=bef,*p2=bef;
inline char readc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZE_,stdin);
	return p1==p2?EOF:*p1++;
}
inline int qread(){
	int ret,w=1,c;
	while((c=readc())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=readc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
const int MAXN =5e5+3;
int h,j,cnt[MAXN],P[MAXN],n,k,mx;
int main(){
	freopen("sgcd.in","r",stdin);
	freopen("sgcd.out","w",stdout);
	n=qread(),k=qread();
	up(1,n,i){
		P[i]=qread();
		for(j=1;j*j<P[i];++j)
		if(!(P[i]%j)) cnt[j]++,cnt[P[i]/j]++;
		if(j*j==P[i]) cnt[j]++;
	}
	dn(MAXN-1,1,i){
		if(cnt[i]>=k){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}
