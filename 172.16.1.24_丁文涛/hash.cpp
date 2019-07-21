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
const int MAXN =1e6+3,MAXM=72400+3;
int h,i,cnt,cnt_,p[MAXM],ans,t;
bool vis[MAXN];
void init(){
	vis[1]=true;
	up(2,MAXN-1,i){
		if(!vis[i]){
			p[++cnt]=i;
			for(int j=2;i*j<MAXN;j++)
			vis[i*j]=true;
		}
	}
}
int main(){
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	init();
	dn(qread(),1,T){
		h=qread(),h++,ans=1,cnt_=0,t=ceil(sqrt(h));
		for(int i=1;p[i]<=t;i++){
			while(h%p[i]==0) cnt_++,h/=p[i];
			ans*=cnt_+1,cnt_=0;
		}
		if(h!=1) ans*=2;
		printf("%d\n",ans);
	}
	return 0;
}
