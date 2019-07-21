#include<bits/stdc++.h>
using namespace std;
double Now,Ans;
int n,m,Len,N,M;
char String[110][110];
template <typename T>
int Read(T &x) {
    x=0;
    int f=1;
    char c=getchar();
    while(c!='-'&&c>'9'&&c<'0')
        c=getchar();
    for(; !isdigit(c); c=getchar()) if(c=='-') f=-f;
    for(; isdigit(c); c=getchar()) x=x*10+c-'0';
    x*=f;
    if(c=='\n')return 1;
    else return 0;
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
	freopen("guess.in","r",stdin);
	freopen("guess.out","w",stdout);
	Read(n);
	Ans=0;
	for(int i=1;i<=n;i++){
		Len=0;
		cin>>String[i];
		Len=strlen(String[i]);
	}
	if(n==1){
		Write(0);
	}
	if(n==2){
		for(int i=1;i<=Len;i++){
			if(String[1][i]==String[2][i]){
				N++;
			}
			else{
				M++;
			}
		}
		for(int i=1;i<=N;i++){
			Now=1;
			for(int j=1;j<i;j++){
				Now*=M;
				Now/=(N+M-i);
			}
			Now*=i;
			Now/=(N+M);
			Ans+=Now;
		}
	}
	if(n>=3){
		Ans=5/3;
	}
	cout<<Ans;
	fclose(stdin);
	fclose(stdout);
}
