#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
const int P=998244353;
const int SIZE_=10000;
char bef[SIZE_+3],*p1=bef,*p2=bef;
char getc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZE_,stdin);
	return p1==p2?EOF:*p1++;
}
int qread(){
	int c,ret,w=1;
	while((c=getc())> '9'||c< '0')
	w=(c=='-'?-1:1);
	ret=c-'0';
	while((c=getc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
const int MAXN =25000 +3,MAXM=3+3;
struct matrix{
	int m,p,data[MAXM][MAXM];
	matrix(int r,int c){
		m=r,p=c,memset(data,0,sizeof(data));
		if(r==3&&c==3) data[1][1]=data[2][2]=data[3][3]=1;
	}
	matrix(){}
	void operator *=(matrix x){
		int n=x.p; matrix ret(m,n);
		up(1,m,i) up(1,n,j){
			up(1,p,k) ret.data[i][j]=((LL)ret.data[i][j]+data[i][k]*x.data[k][j])%P;
		}
	}
	void operator +=(matrix x){
		up(1,m,i) up(1,p,j) data[i][j]+=x.data[i][j];
	}
};
struct Node{
	int l,r,_delta[3];
	struct matrix sum,delta;
	Node(){
		sum=matrix(1,3),delta=matrix(3,3);
	}
}data[MAXN*4];
#define lc(x) (t<<1)
#define rc(x) ((t<<1)|1)
void bld(int t,int l,int r){
	data[t].l=l,data[t].r=r;
	int mid=l+r>>1;
	if(l!=r) bld(lc(t),l,mid),bld(rc(t),mid+1,r);
}
void upd(int t){
	data[lc(t)].delta+=data[t].delta;
	data[lc(t)].sum*=data[t].delta;
	data[rc(t)].delta+=data[t].delta;
	data[lc(t)].sum*=data[t].delta;
	data[t].delta=matrix(3,3);
	if(data[t]._delta[0]!=P) {
		data[lc(t)]._delta[0]=data[t]._delta[0];
		data[rc(t)]._delta[0]=data[t]._delta[0];
	}
	if(data[t]._delta[1]!=P) {
		data[lc(t)]._delta[1]=data[t]._delta[1];
		data[rc(t)]._delta[1]=data[t]._delta[1];
	}
	if(data[t]._delta[2]!=P) {
		data[lc(t)]._delta[2]=data[t]._delta[2];
		data[rc(t)]._delta[2]=data[t]._delta[2];
	}
	data[t]._delta[0]=P;
	data[t]._delta[1]=P;
	data[t]._delta[2]=P;
}
void st(int t,int l,int r,int k,int x){
	if(l<=data[t].l&&r>=data[t].r){
		data[t].sum.data[1][k+1]=x;
		data[t]._delta[k]=x;
	} else{
		upd(t);
		int mid=data[t].l+data[t].r>>1;
		if(l<=mid) st(lc(t),l,r,k,x);
		if(r> mid) st(rc(t),l,r,k,x);
		data[t].sum=matrix(1,3);
		data[t].sum+=data[lc(t)].sum;
		data[t].sum+=data[rc(t)].sum;
	}
}
void cng(int t,int l,int r,matrix k){
	if(l<=data[t].l&&r>=data[t].r){
		upd(t);
		data[t].sum*=k;
	} else{
		upd(t);
		int mid=data[t].l+data[t].r>>1;
		if(l<=mid) cng(lc(t),l,r,k);
		if(r> mid) cng(rc(t),l,r,k);
		data[t].sum=matrix(1,3);
		data[t].sum+=data[lc(t)].sum;
		data[t].sum+=data[rc(t)].sum;
	}
}
matrix qry(int t,int l,int r){
	if(l<=data[t].l&&r>=data[t].r){
		return data[t].sum;
	}
	matrix ret(1,3);
	int mid=data[t].l+data[t].r>>1;
	if(l<=mid) ret+=qry(lc(t),l,r);
	if(r> mid) ret+=qry(rc(t),l,r);
	return ret;
}
matrix OP[3];
int n,m;
int main(){
	freopen("augur.in","r",stdin);
	freopen("augur.out","w",stdout);
	
	OP[0]=matrix(3,3);
	OP[0].data[1][2]=1,OP[0].data[1][3]=-1;
	OP[1]=matrix(3,3);
	OP[1].data[2][1]=-1,OP[1].data[2][3]=1;
	OP[2]=matrix(3,3);
	OP[2].data[3][1]=1,OP[2].data[3][2]=-1;
	n=qread(),bld(1,1,n);
	up(1,n,i){
		int A=qread(),B=qread(),C=qread();
		st(1,i,i,0,A),st(1,i,i,1,B),st(1,i,i,2,C);
	}
	m=qread();
	up(1,m,i){
		int T,L,R,K,X,C,op;
		matrix t,_t;
		T=qread(),L=qread(),R=qread();
		switch(T){
			case 1:
				while((op=getc())==' ');
				t*=OP[op-'0'];
				while((op=getc())!=' ')
				t*=OP[op-'0'];
				_t=t,C=qread();
				up(1,C-1,j) t*=_t;
				cng(1,L,R,t);
				break;
			case 2:
				K=qread(),X=qread();
				st(1,L,R,K,X);
				break;
			case 3:
				K=qread();
				printf("%d\n",qry(1,L,R).data[1][K]);
		}
	}
	return 0;
}
