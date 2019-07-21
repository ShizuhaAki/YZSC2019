/********************************************
—Ó∂”NB 
********************************************/ 
//stO —Ó∆” Orz
#include<bits/stdc++.h>
using namespace std;
int n,s,c,Degree,T,Data,Edge,Dp[110][1010][1010];
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
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	Read(T);
	while(T--){
		Degree=0;
		memset(Dp,0,sizeof(Dp));
		Dp[0][0][0]=1;
		Read(n);
		Read(s);
		Degree=(n-1)*2;
		for(int i=0;i<n;i++){
			for(int j=0;j<Degree;j++){
				for(int k=0;k<s;k++){
					if(Dp[i][j][k]){
						for(int l=1;l<=Degree-j;l++){
							Edge=(l*(l-1))>>1;
							if(k+Edge>s){
								break;
							}
							Dp[i+1][j+l][k+Edge]=1;
						}
					}
				}
			}
		}
		if(Dp[n][Degree][s]){
			puts("Possible");
		}
		else{
			puts("Impossible");	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
