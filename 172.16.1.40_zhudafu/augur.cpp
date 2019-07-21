//我挣扎过了，但是......
//然并卵
//晚上慢慢调吧.......
/********************************************
杨队NB 
********************************************/ 
//stO 杨朴 Orz
#include<bits/stdc++.h>
#define Mod 998244353;
using namespace std;
struct Node {
    long long Left,Right,Sum,Add;
} Tree[400010][3];
int x,n,nq,a,b,c,d,X,Cz[1000010],Order,Cycle,Cnt,Data,m,Pd,L,R,Start[1000010][5];
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
void Build(long long l,long long r,long long Root,int X) {
    Tree[Root][X].Left=l;
    Tree[Root][X].Right=r;
    Tree[Root][X].Add=0;
    if(l==r)
        Tree[Root][X].Sum=Start[l][X];
    else {
        long long Mid=(l+r)>>1;
        Build(l,Mid,Root<<1,X);
        Build(Mid+1,r,Root<<1|1,X);
        Tree[Root][X].Sum=(Tree[Root<<1][X].Sum+Tree[Root<<1|1][X].Sum)%Mod;
    }
}
void Pushdown(long long Root,int X) {
    if(Tree[Root][X].Add) {
        Tree[Root<<1][X].Add+=Tree[Root][X].Add;
        Tree[Root<<1][X].Add%=Mod;
        Tree[Root<<1|1][x].Add+=Tree[Root][X].Add;
        Tree[Root<<1|1][x].Add%=Mod
        Tree[Root<<1][X].Sum+=(Tree[Root<<1][X].Right-Tree[Root<<1][X].Left+1)*Tree[Root][X].Add;
        Tree[Root<<1][X].Sum%=Mod;
        Tree[Root<<1|1][x].Sum+=(Tree[Root<<1|1][x].Right-Tree[Root<<1|1][x].Left+1)*Tree[Root][X].Add;
        Tree[Root<<1|1][x].Sum%=Mod;
        Tree[Root][X].Add=0;
    }
}
void Pushup(long long Root,int X) {
    Tree[Root][X].Sum=Tree[Root<<1][X].Sum+Tree[Root<<1|1][x].Sum;
    Tree[Root][X].Sum%=Mod;
}
void Update(long long nl,long long nr,long long Root,long long Data,int X) {
    if(nl>Tree[Root][X].Right||nr<Tree[Root][X].Left)
        return;
    if(nl<=Tree[Root][X].Left&&nr>=Tree[Root][X].Right) {
        Tree[Root][X].Add+=Data;
        Tree[Root][X].Add%=Mod;
        Tree[Root][X].Sum+=(Tree[Root][X].Right-Tree[Root][X].Left+1)*Data;
        Tree[Root][X].Sum%=Mod;
        return;
    }
    Pushdown(Root,X);
    long long Mid=(Tree[Root][X].Left+Tree[Root][X].Right)>>1;
    if(nl<=Mid)
        Update(nl,nr,Root<<1,Data,X);
    if(nr>=Mid+1)
        Update(nl,nr,Root<<1|1,Data,X);
    Pushup(Root,X);
}
long long q(long long nl,long long nr,long long Root,int X) {
    int ans;
    if(nl>Tree[Root][X].Right||nr<Tree[Root][X].Left)
        return 0;
    if(nl<=Tree[Root][X].Left&&nr>=Tree[Root][X].Right)
        return Tree[Root][X].Sum;
    int Mid=(Tree[Root][X].Left+Tree[Root][X].Right)>>1;
    Pushdown(Root,X);
    return (q(nl,nr,Root<<1,X)+q(nl,nr,Root<<1|1,X))%Mod;
}
int main() {
	Read(n);
	freopen("augur.in","r",stdin);
	freopen("augur.out","w",stdout);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2;j++){
			Read(Start[i][j]);
		}
	}  
	Build(1,n,1,0);
	Build(1,n,1,1);
	Build(1,n,1,2);
	Read(m);
	while(m--){
		Read(Order);
		if(Order==1){
			Pd=0;
			Cnt=0;
			Read(L);
			Read(R);
			c=getchar();
			c=getchar();
			while(isdigit(c)){
				if(c!='0'){
					Pd=1;
				}
				Cz[++Cnt]=c-'0';
				c=getchar();
			}
			Read(Cycle);
			if(Pd){
				for(int i=L;i<=R;i++){	
					Update(i,i,1,(q(i,i,1,1)-q(i,i,1,2))*Cycle*Cnt,0);
				}
			}
			else{
				for(int i=1;i<=Cycle;i++){
					for(int j=1;j<=Cnt;i++){
						for(int k=L;k<=R;k++){
							if(Cz[j]==0){
								Update(k,k,1,(q(k,k,1,1)-q(k,k,1,2)),0);
							}
							if(Cz[j]==1){
								Update(k,k,1,(q(k,k,1,2)-q(k,k,1,0)),1);
							}
							if(Cz[j]==2){
								Update(k,k,1,(q(k,k,1,0)-q(k,k,1,1)),2);
							}
						}
					}
				}
			}
		}
		if(Order==2){
			Read(L);
			Read(R);
			Read(X);
			Read(Data);
				
		}
		if(Order==3){
			Read(L);
			Read(R);
			Read(X);
			Write(q(L,R,1,X));
			puts("");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

