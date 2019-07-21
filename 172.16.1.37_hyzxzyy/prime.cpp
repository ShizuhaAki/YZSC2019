#include<bits/stdc++.h>
#define REP(i,a,b) for(register int i(a);i<=b;i++)
#define PER(i,a,b) for(register int i(a);i>=b;i--)
using namespace std;
const int M=6e7+5e6;
const int MP=4000000;
long long N;
short np[M];int prm[MP],tot;
int T;
inline void getprime(){
	np[1]=1;
	REP(i,2,M){
		if(!np[i])prm[++tot]=i;
		REP(j,1,tot){
			if(prm[j]*i>M)break;
			np[prm[j]*i]=1;
			if(!(i%prm[j]))break;
		}
	}
}
int main(){
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	getprime();
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&N);
		int flag=0;
		PER(i,tot,1)
			if(!(N%prm[i]))
				{printf("%d\n",prm[i]);flag=1;break;}
		if(!flag)puts("Prime");
	}
	fclose(stdin);fclose(stdout);
}
