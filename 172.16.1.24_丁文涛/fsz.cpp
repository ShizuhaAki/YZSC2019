#include<bits/stdc++.h>
#define up(l,r,i) for(register int i=l;i<=r;i++)
#define dn(r,l,i) for(register int i=r;i>=l;i--)
#define cng(x) ((x-1)/3+1)
using namespace std;
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
const int MAXN =200 +3,MAXM =3000 +3;
int iron[MAXN],n,m,p,k;
bool vis[MAXN][(1<<13)+3];
int tot,head[MAXN],nxt[MAXM*2],ver[MAXM*2],val[MAXM*2],mos[MAXM*2];
void add(int u,int v,int w,int ms){
	ver[++tot]=v,val[tot]=w,nxt[tot]=head[u],mos[tot]=ms,head[u]=tot;
}
int main(){
	freopen("fsz.in","r",stdin);
	freopen("fsz.out","w",stdout);
	
	n=qread(),m=qread(),p=qread(),k=qread();
	up(1,k,i){
		int w,q,r;
		w=qread(),q=qread();
		up(1,q,j) r=qread(),iron[w]|=1<<r-1;
	}
	up(1,m,i){
		int v,w,t,s,u,tmp=0;
		v=qread(),w=qread(),t=qread(),s=qread();
		up(1,s,j) u=qread(),tmp|=1<<u-1;
		add(v,w,t,tmp),add(w,v,t,tmp);
	}
	priority_queue <pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;
	pq.push(make_pair(0,make_pair(1,iron[1])));
	while(!pq.empty()){
		int t=pq.top().first,u=pq.top().second.first,s=pq.top().second.second; pq.pop();
		if(vis[u][s]) continue; vis[u][s]=true;
		if(u==n) {
			printf("%d\n",t);
			return 0;
		}
		for(int i=head[u];i;i=nxt[i]){
			if((mos[i]|s)>s) continue;
			int v=ver[i],ns=s|iron[v];
			if(!vis[v][ns]){
				pq.push(make_pair(t+val[i],make_pair(v,ns)));
			}
		}
	}
	puts("-1");
	return 0;
}
/*
6 7 4 2
2 1 2
3 2 1 3
1 2 2 0
2 3 9 0
1 4 2 1 2
2 5 3 0
4 5 5 2 2 3
4 6 18 0
5 6 3 2 1 2

3 2 1 1
2 1 1
1 2 1 0
2 3 1 1 1
*/
