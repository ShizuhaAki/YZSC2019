#include<bits/stdc++.h>
using namespace std;
int n,m;
double Dp[1010][1010];
template <typename T>
int Read(T &x) {
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
int main() {
	freopen("pattern.in","r",stdin);
	freopen("pattern.out","w",stdout);
	Read(n);
	Read(m);
	Dp[0][0]=1;
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=i; j++) {
			Dp[i][j]=Dp[i-1][j]*((double)j/n)+Dp[i-1][j-1]*((double)(n-j+1)/n);
		}
	}
	printf("%.4lf",Dp[m][n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

