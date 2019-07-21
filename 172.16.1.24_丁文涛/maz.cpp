#include<bits/stdc++.h>
#define up(l,r,i) for(register int i=l;i<=r;i++)
#define dn(r,l,i) for(register int i=r;i>=l;i--)
#define cng(x) ((x-1)/3+1)
using namespace std;
const int MAXN =500 +3;
int n,m,k,maz[MAXN][MAXN];
int qread(){
	int ret,w=1,c;
	while((c=getchar())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=getchar())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
char readc(){
	char c;
	while((c=getchar())==' '||c=='\n');
	return c;
}
bool vis[MAXN][MAXN];
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y){
	up(0,3,i){
		int nx=x+dir[i][0],ny=y+dir[i][1];
		if(maz[nx][ny]==true&&!vis[nx][ny]){
			vis[nx][ny]=true;
			dfs(nx,ny);
		}
	}
	if(k>0) maz[x][y]=-1,k--;
}
int main(){
	n=qread(),m=qread(),k=qread();
	up(1,n,i) up(1,m,j) maz[i][j]=(readc()=='#'?false:true);
	up(1,n,i) up(1,m,j) if(maz[i][j]){
		dfs(i,j); goto end;
	}
	end: up(1,n,i){
		up(1,m,j) putchar(maz[i][j]==true?'.':(maz[i][j]==-1?'X':'#'));
		puts("");
	}
	return 0;
}
