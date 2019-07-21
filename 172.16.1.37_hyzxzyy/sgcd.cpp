#include<bits/stdc++.h>
#define REP(i,a,b) for(register int i(a);i<=b;i++)
#define PER(i,a,b) for(register int i(a);i>=b;i--)
using namespace std;
const int N=5e5+9;
const int M=5e4+9;
int n,k,mx;
int a[N];
short np[N];int tot,p[M];
int cnt[M],pp[N<<4],top,num[N<<4],siz;
short ext[N<<4];
template<class T>inline void read(T&x){
	T res=0;char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
	x=res;
}
template<class T>inline void write(T x){
	if(!x){puts("0");return ;}
	char buf[15];int top=0;
	while(x)buf[++top]=x%10,x/=10;
	while(top)putchar(buf[top--]+'0');
	puts("");
}
inline void getprime(){
	np[1]=1;
	REP(i,2,N){
		if(!np[i])p[++tot]=i;
		REP(j,1,tot){
			if(p[j]*i>N)break;
			np[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}
}
inline void cutdown(int s){REP(i,1,tot)if(s%p[i]==0)while(s%p[i]==0)cnt[i]++,s/=p[i];}
void dfs(int step,int sigema){
	if(step==top+1&&sigema<=mx){if(!ext[sigema])num[++siz]=sigema,ext[sigema]=1;return;}
	if(step==top+1||sigema>mx)return ;
	dfs(step+1,sigema*pp[step]);dfs(step+1,sigema);
}
int main(){
	freopen("sgcd.in","r",stdin);
	freopen("sgcd.out","w",stdout);
	getprime();
	read(n);read(k);
	REP(i,1,n)read(a[i]),mx=max(a[i],mx);
	REP(i,1,n)cutdown(a[i]);
	REP(i,1,tot)if(cnt[i])while(cnt[i])pp[++top]=p[i],cnt[i]--;
	dfs(1,1);	
	sort(num+1,num+siz+1);
	PER(i,siz,1){int cst=0;REP(j,1,n)if(a[j]%num[i]==0)cst++;
	if(cst>=k){cout<<num[i];return 0;}}
	fclose(stdin);fclose(stdout);
}
