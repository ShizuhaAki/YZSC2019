#include<bits/stdc++.h>
using namespace std;
inline long long Qmul(const long long& x,const long long& y,const long long& X) {
	register long long k=(long long)((1.0L*x*y)/(1.0L*X)),t=x*y-k*X;
	t-=X;
	while(t<0) t+=X;
	return t;
}
class MillerRabin {
	private:
		const int P[12]= {2,3,5,7,11,13,17,19,61,2333,4567,24251};
		inline long long Qpow(register long long x,register long long y,const long long& X) {
			register long long t=1;
			while(y) y&1&&(t=Qmul(t,x,X)),x=Qmul(x,x,X),y>>=1;
			return t;
		}
		inline bool Check(const long long& x,const int& p) {
			if(!(x%p)||Qpow(p%x,x-1,x)^1) return false;
			register long long k=x-1,t;
			while(!(k&1)) {
				if((t=Qpow(p%x,k>>=1,x))^1&&t^(x-1)) return false;
				if(!(t^(x-1))) return true;
			}
			return true;
		}
	public:
		bool IsPrime(const long long& x) {
			if(x<2) return false;
			for(register int i=0; i^12; ++i) {
				if(!(x^P[i])) return true;
				if(!Check(x,P[i])) return false;
			}
			return true;
		}
};
class PollardRho {
	private:
#define Rand(x) (1LL*rand()*rand()*rand()*rand()%(x)+1)
		long long ans;
		MillerRabin MR;
		inline long long gcd(const long long& x,const long long& y) {
			return y?gcd(y,x%y):x;
		}
		inline long long Work(const long long& x,const int& y) {
			register int t=0,k=1;
			register long long v0=Rand(x-1),v=v0,d,s=1;
			while(true) {
				if(v=(Qmul(v,v,x)+y)%x,s=Qmul(s,((v-v0)<0?-(v0-v):(v-v0)),x),!(v^v0)||!s) return x;
				if(++t==k) {
					if((d=gcd(s,x))^1) return d;
					v0=v,k<<=1;
				}
			}
		}
		inline void Resolve(register long long x,register int t) {
			if(!(x^1)||x<=ans) return;
			if(MR.IsPrime(x)) return (void)(ans<(x)&&(ans=(x)));
			register long long y=x;
			while((y=Work(x,t--))==x);
			while(!(x%y)) x/=y;
			Resolve(x,t),Resolve(y,t);
		}
	public:
		inline PollardRho() {
			srand(20050521);
		}
		inline long long GetMax(const long long& x) {
			return ans=0,Resolve(x,302627441),ans;
		}
} P;
int main() {
	freopen("prime.in", "r", stdin);
	freopen("prime.out", "w", stdout);
	register int Ttot;
	register long long n,res;
	scanf("%d",&Ttot);
	while(Ttot--) scanf("%lld",&n),(res=P.GetMax(n))^n?printf("%lld\n",res):puts("Prime");
	return 0;
}
