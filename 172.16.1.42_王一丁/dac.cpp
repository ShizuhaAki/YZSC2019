#include<bits/stdc++.h>
using namespace std;
string s,t,a[1007];
int pp(string a1,string b1){
	int g=0;
	for(int i=0;i<a1.size();i++){
		if(a1[i]!=b1[i]) g++;
		if(g>=2) return 0;
	}
	return 1;
}
struct node{
    int v,u,next;
}e[2000007];
int dis[1007],vis[1007],tot=0,head[1007];
int n;
void add(int x,int y,int z){
    e[++tot].v=y;e[tot].u=z;e[tot].next=head[x];head[x]=tot;
}
void dijkstra(){
    for(int i=1;i<=n;i++) dis[i]=2147483647;
    memset(vis,0,sizeof(vis));
    dis[1]=0;
    for(int i=1;i<n;i++){
        int Min=2147483647,k=0; 
        for(int j=1;j<=n;j++)
            if(!vis[j]&&dis[j]<Min) Min=dis[j],k=j;
        vis[k]=1;
        for(int j=head[k];j;j=e[j].next){
            int y=e[j].v,z=e[j].u;
            if(z+dis[k]<dis[y]) dis[y]=z+dis[k];
        }
	}
}
int main()
{
	freopen("dac.in","r",stdin);
	freopen("dac.out","w",stdout);
	int cnt=0;
	cin>>a[++cnt]>>t;
	while(cin>>a[++cnt]);
	a[cnt]=t;
	n=cnt;
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			if(pp(a[i],a[j])) add(i,j,1),add(j,i,1);
		}
	}
	dijkstra();
	cout<<dis[cnt]-1<<endl;
	return 0;
}
