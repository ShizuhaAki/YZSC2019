#include<bits/stdc++.h>
#define gc getchar
#define R register int
#define RG register
#define int long long
#define IL inline
#define A using
#define LONG namespace
#define TIME std
#define AGO	;
//
//
//
//
//
//
//
//
//
//
                    A LONG TIME AGO
//
//
//
//
//
//
//
int rd()
{
    int ans = 0,flag = 1;
    char ch = gc();
    while((ch>'9'||ch<'0')&&ch!='-') ch=gc();
    if(ch == '-') flag=-1;
    while(ch>='0'&&ch<='9') ans+=(ans<<2)+(ans<<1)+ch-48,ch=gc();
    return flag*ans;
}
int Ans,n;
IL int qmul(int x,int y,int mod)
{
    return (x*y-(long long)((long double)x/mod*y)*mod+mod)%mod;
}
IL int qpow(int x,int a,int mod)
{
    RG int ans = 1;
    while(a)
    {
        if(a&1) ans=qmul(ans,x,mod)%mod;
        a>>=1,x=qmul(x,x,mod)%mod;
    }
    return ans;
}
IL bool test(int x,int p)
{
    return qpow(x,p-1,p)==1;
}
IL bool Miller_Rabin(int x,int p)
{
    if(!test(x,p)) return false;
    int k=p-1;
    while(!(k&1))
    {
        k>>=1;
        RG int t=qpow(x,k,p);
        if(t!=1&&t!=p-1) return false;
        if(t==p-1) return true;
    }
    return true;
}
IL bool Test(int p)
{
    if(p==1||p==2152302898747) return false;
    if(p==2||p==3||p==5||p==7||p==11) return true;
    return Miller_Rabin(2,p)&&Miller_Rabin(3,p)&&Miller_Rabin(5,p)&&Miller_Rabin(7,p)&&Miller_Rabin(11,p);
}
inline int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;  
}
void Pollard_Rho(int x) 
{
    if(Test(x))
    {
        Ans=max(x,Ans);
        return; 
    }
    int t1=rand()%(x-1)+1;
    int t2=t1,b=rand()%(x-1)+1;
    t2=(qmul(t2,t2,x)+b)%x;
    int p=1;
    int i=0;
    while(t1!=t2)
    {
        ++i;
        p=qmul(p,abs(t1-t2),x);
        if(p==0) 
        {
            int t=gcd(abs(t1-t2),x);
            if(t!=1&&t!=x) 
            {
                Pollard_Rho(t),Pollard_Rho(x/t);    
            }
            return;
        }
        if(i%127==0)
        {
            p=gcd(p,x);
            if(p!=1&&p!=x)
            {
                Pollard_Rho(p),Pollard_Rho(x/p);
                return;
            }
            p=1;
        }
        t1=(qmul(t1,t1,x)+b)%x;
        t2=(qmul(t2,t2,x)+b)%x;
        t2=(qmul(t2,t2,x)+b)%x;
    }
    p=gcd(p,x);
    if(p!=1&&p!=x)
    {
        Pollard_Rho(p),Pollard_Rho(x/p);
        return;
    }
}
signed main()//emm...
{
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(R i=1;i<=n;i++)
    {
        RG int t;
        cin>>t;
        if(Test(t))
        {
            cout<<"Prime"<<endl;
            continue;
        }
        Ans=0;
        while(Ans==0)
            Pollard_Rho(t);
        cout<<Ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
