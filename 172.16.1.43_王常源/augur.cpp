#include<bits/stdc++.h>
using namespace std;
const int MAXA=25500,MOD=998244353;
struct node{int A,B,C;}fz[MAXA];
struct tree{int left,right;long long data;}mytree[4][MAXA<<2];
int n,m;
inline void getRead()
{
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		fz[i].A=a;
		fz[i].B=b;
		fz[i].C=c;
	}	
}

inline void build(int treeNum,int now,int l,int r)
{
	mytree[treeNum][now].left=l;mytree[treeNum][now].right=r;
	if(mytree[treeNum][now].left==mytree[treeNum][now].right)
	{
		if(treeNum==1) mytree[treeNum][now].data=fz[l].A;
		if(treeNum==2) mytree[treeNum][now].data=fz[l].B;
		if(treeNum==3) mytree[treeNum][now].data=fz[l].C;
		return;
	}
	int mid=(l+r)>>1;build(treeNum,now<<1,l,mid);build(treeNum,now<<1|1,mid+1,r);
	mytree[treeNum][now].data=mytree[treeNum][now<<1].data+mytree[treeNum][now<<1|1].data;
}

inline long long query(int treeNum,int now,int l,int r)
{
	if(mytree[treeNum][now].left==l&&mytree[treeNum][now].right==r)
		return mytree[treeNum][now].data;
	int mid=(mytree[treeNum][now].left+mytree[treeNum][now].right)>>1;
	if(r<=mid) return query(treeNum,now<<1,l,r);
	if(l>mid) return query(treeNum,now<<1|1,l,r);
	if(l<=mid&&r>mid) return query(treeNum,now<<1,l,mid)+query(treeNum,now<<1|1,mid+1,r);
}

inline void update(int treeNum,int now,int dot,int newNum)
{
	if(treeNum==1) fz[dot].A=newNum;
	if(treeNum==2) fz[dot].B=newNum;
	if(treeNum==3) fz[dot].C=newNum;
	int mid=(mytree[treeNum][now].right+mytree[treeNum][now].left)>>1;
	if(mytree[treeNum][now].right==mytree[treeNum][now].left&&mytree[treeNum][now].right==dot)
		{mytree[treeNum][now].data=newNum;return;}
	if(dot<=mid) update(treeNum,now<<1,dot,newNum);
	if(dot>mid) update(treeNum,now<<1|1,dot,newNum);
	mytree[treeNum][now].data=mytree[treeNum][now<<1].data+mytree[treeNum][now<<1|1].data;
}

int main()
{
	freopen("augur.in","r",stdin);
	freopen("augur.out","w",stdout);
	getRead();
	build(1,1,1,n);
	build(2,1,1,n);
	build(3,1,1,n);
	scanf("%d",&m);
	for(register int i=1;i<=m;i++)
	{
		int sign,L,R;long long k,x;
		scanf("%d%d%d",&sign,&L,&R);
		if(sign==3)
		{
			scanf("%d",&k);k+=1;
			long long ans=query(k,1,L,R)%MOD;
			printf("%lld\n",ans);
		}
		if(sign==2)
		{
			scanf("%d%d",&k,&x);k+=1;
			for(register int i=L;i<=R;i++)
				update(k,1,i,x);
		}
		if(sign==1)
		{
			string S;int len,times;
			cin>>S;cin>>times;len=S.size();
			for(register int i=1;i<=times;i++)
			{
				for(register int i=0;i<len;i++)
				{
					char temp=S[i];
					if(temp=='0')
					{
						for(register int i=L;i<=R;i++)
						{
							int a=fz[i].A+fz[i].B-fz[i].C;
							update(1,1,i,a);
						}
					}
					if(temp=='1')
					{
						for(register int i=L;i<=R;i++)
						{
							int a=fz[i].B+fz[i].C-fz[i].A;
							update(2,1,i,a);
						}
					}
					if(temp=='2')
					{
						for(register int i=L;i<=R;i++)
						{
							int a=fz[i].C+fz[i].A-fz[i].B;
							update(3,1,i,a);
						}
					}
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
