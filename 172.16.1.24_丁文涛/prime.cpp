#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define up(l,r,i) for(register int i=l;i<=r;++i)
#define dn(r,l,i) for(register int i=r;i>=l;--i)
using namespace std;
typedef long long   LL;
typedef long double LD;
const int INF =2147483647;
inline LL qread(){
	LL ret,w=1,c;
	while((c=getchar())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=getchar())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
inline LL qkml(LL a,LL b,LL P){
	return ((LL)a*b-(LL)((LD)a/P*b)*P+P)%P;
}
inline LL qkpr(LL a,LL b,LL P){
	LL ret=1,t=a;
	while(b){
		if(b&1) ret=qkml(ret,t,P);
		t=qkml(t,t,P),b>>=1;
	}
	return ret;
}
inline LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
inline bool fmt(LL t,LL P){
	return qkpr(t,P-1,P)==1;
}
inline bool mlrb(LL t,LL P){
	if(!fmt(t,P)) return false;
	register LL k=P-1;
	while(!(k&1)){
		k>>=1;
		register int t_=qkpr(t,k,P);
		if(t_!=1&&t_!=P-1) return false;
		if(t_==P-1) return true;
	}
	return true;
}
inline bool chk(LL P){
	if(P==2||P==3||P==5||P==7||P==11) return true;
	return mlrb(2,P)&&mlrb(3,P)&&mlrb(5,P)&&mlrb(7,P);
}
LL ans,n;
inline LL nxt(LL t,LL seed,LL P){
	return (qkml(t,t,P)+seed)%P;
}
const int MAXN =1e6+3;
bool vis[MAXN];
LL tmp[MAXN];
inline void init(){
	vis[1]=true;
	up(2,MAXN-1,i){
		if(!vis[i]) for(int j=1;i*j<MAXN;j++){
			tmp[i*j]=max((LL)i,tmp[i*j]),vis[i*j]=true;
		}
	}
}
inline void plrh(LL t){
	if(t<MAXN&&(ans=max(ans,tmp[t]))) return;
	if(chk(t)&&(ans=max(ans,t))) return ;
	LL t1=rand()%(t-1)+1,seed=(19260817+rand()+t)%(t-1)+1,t2=nxt(t1,seed,t);
	srand(seed*rand());
	while(t1!=t2&&t!=1){
		LL _t=gcd(abs(t1-t2),t);
		if(_t!=1&&_t!=t){
			plrh(_t),plrh(t/_t);
			break;
		}
		t1=nxt(t1,seed,t);
		t2=nxt(t2,seed,t);
		t2=nxt(t2,seed,t);
	}
}
int main(){
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	
	init();
	dn(qread(),1,i){
		ans=0,n=qread();
		plrh(n);
		n==ans?puts("Prime"):printf("%lld\n",ans);
	}
	return 0;
}
