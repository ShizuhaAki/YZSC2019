//ÄËÈÊÈü2 2019.7.18 dac.cpp
#include<bits/stdc++.h>
using namespace std;
const int MAXA=1010,MAXB=1000010;
const int INF=0x3f3f3f3f;
string begin,end,words[MAXA];
int u[MAXB],v[MAXB],tot=0;
int head[MAXA],nex[MAXB];
int n,beNum,enNum,len;
int dis[MAXA];bool vis[MAXA];
inline void openFile()
{
	freopen("dac.in","r",stdin);
	freopen("dac.out","w",stdout);
}
inline void closeFile()
{
	fclose(stdin);
	fclose(stdout);
}
inline void addedge(int x,int y)
{
	tot++;u[tot]=x;v[tot]=y;
	nex[tot]=head[x];head[x]=tot;
}
inline void getRead()
{
	cin>>begin>>end;
	n=1;words[n]=begin;
	n=2;words[n]=end;n++;
	while(cin>>words[n])
		n++;
	n--;
}
inline bool check(string a,string b)
{
	int diffNum=0;
	for(register int i=0;i<len;i++)
	{
		if(a[i]==b[i]) continue;
		if(a[i]!=b[i]) diffNum++;
		if(diffNum>1) return 0;
	}
	if(diffNum==1) return 1;
	else return 0;
}
inline int getMin()
{
	int flag=0;
	for(register int i=1;i<=n;i++)
		if(dis[i]<dis[flag]&&vis[i]==0)	flag=i;
	return flag;
}

inline void dijkstra()
{
	dis[1]=0;
	while(vis[2]==0)
	{
		int nowMin=getMin();vis[nowMin]=1;
		int now=head[nowMin];
		while(now!=0)
		{
			int temp=v[now];
			if(vis[temp]==0&&dis[temp]>dis[nowMin]+1)
				dis[temp]=dis[nowMin]+1;
			now=nex[now];
		}
	}
}
+
int main()
{
	openFile();
	getRead();
	len=begin.size();
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=i;j++)
		{
			if(i==j) continue;
			if(check(words[i],words[j]))
			{
				addedge(i,j);
				addedge(j,i);
//				cout<<i<<" "<<j<<endl;
			}
		}
	memset(dis,0x3f,sizeof(dis));
	dijkstra();
	cout<<dis[2]-1<<endl;
	closeFile();
//	
	return 0;
}
