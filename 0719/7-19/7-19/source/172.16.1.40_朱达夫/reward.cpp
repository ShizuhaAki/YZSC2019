#include<bits/stdc++.h>
using namespace std;
int n,m,k,K,x;
double Dp[1010][100010];
int Pow[10010],Need[10010],Val[10010];
template <typename T>
inline int Read(T &x) {
	x=0;
	int f=1;
	char c=getchar();
	while(c!='-'&&c>'9'&&c<'0')
		c=getchar();
	for(; !isdigit(c); c=getchar())
		if(c=='-')
			f=-f;
	for(; isdigit(c); c=getchar())
		x=x*10+c-'0';
	x*=f;
	if(c=='\n')
		return 1;
	else
		return 0;
}
void Write(long long x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) {
		Write((x-x%10)/10);
	}
	putchar(x%10+'0');
}
int main(){
	freopen("reward.in","r",stdin);
	freopen("reward.out","w",stdout);
	Read(n);
	Read(K);
	for(int i=1;i<=n+1;i++){
		Pow[i]=1<<(i-1);
	}
	for(int i=1;i<=K;i++){
		Read(Val[i]);
		Read(x);
		while(x){
			Need[i]|=Pow[i];
			Read(x);
		}
	}
	for(int i=n;i;i--){
		for(int j=0;j<=(1<<K)-1;j++){
			for(int k=1;k<=K;k++){
				if((Need[k]&j)==Need[k]){
					Dp[i][j]+=max(Dp[i+1][j],double(Dp[i+1][j|Pow[k]]+Val[k]));
				}
				else{
					Dp[i][j]+=Dp[i+1][j];
				}
			}
			Dp[i][j]/=K;
		}
	}
	printf("%.6lf",Dp[1][0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
