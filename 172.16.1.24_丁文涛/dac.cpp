#include<bits/stdc++.h>
#define up(l,r,i) for(register int i=l;i<=r;i++)
#define dn(r,l,i) for(register int i=r;i>=l;i--)
using namespace std;
const int MAXN =1e3 +3;
string reads(){
	char c; string _s;
	while((c=getchar())> 'z'||c< 'a')
	if(c==EOF) return "#";  		   _s+=c;
	while((c=getchar())>='a'&&c<='z')  _s+=c;
	return _s;
}
bool check(string s1,string s2){
	int cnt=0;
	dn(s1.length(),1,i) if(s1[i-1]!=s2[i-1]) cnt++;
	return cnt==1;
}
vector <int> P[MAXN];
string s,t,S[MAXN];
bool mmp[MAXN];
int cnt;
int main(){
	freopen("dac.in","r",stdin);
	freopen("dac.out","w",stdout);
	
	s=reads(),t=reads(),S[++cnt]=s,S[++cnt]=t;
	while((S[++cnt]=reads())!="#"); cnt--;
	up(1,cnt,i){
		up(i+1,cnt,j) if(check(S[i],S[j]))
		P[i].push_back(j),P[j].push_back(i);
	}
	queue <pair<int,int> > q; q.push(make_pair(1,0));
	mmp[1]=true;
	while(!q.empty()){
		int u=q.front().first,t=q.front().second; q.pop();
		for(int i=1;i<=P[u].size();i++)
			if(!mmp[P[u][i-1]]){
				mmp[P[u][i-1]]=true,q.push(make_pair(P[u][i-1],t+1));
				if(P[u][i-1]==2){
					printf("%d\n",t);
					return 0;
				}
			}
	}
	return 0;
}
/*
hi uw
we he ee ww
*/
