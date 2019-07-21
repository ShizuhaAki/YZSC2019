#include<bits/stdc++.h>
#define REP(i,a,b) for(register int i(a);i<=b;i++)
using namespace std;
int T,h,ans;
//50847534 max
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
int main(){
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	read(T);
	while(T--){
		read(h);
		h++;ans=0;
		for(register int i=1;i*i<=h;i++)if(h%i==0)ans+=(i*i==h)?1:2;
		write(ans);
	}
	fclose(stdin);fclose(stdout);
}
