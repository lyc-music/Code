#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 500005
using namespace std;
int fac[N],inv[N],pw[N];
int n,m,d;
inline int quickPower(int x,int y)
{
    int res=1;
    while (y)
    {
        if (y&1) res=res*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return res;
}
inline int C(int x,int y)
{
    if (x<y||y<0) return 0;
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void BellaKira()
{
    cin>>n>>m>>d;
    d++;
    int ans=0;
    for (int i=0;i<=m;i++)
    {
        int t=i*d+(2*d-1)*(m-i);
        if (t<=n)
        {
            int coef=1;
            if ((m-i)%2==1) coef=mod-1;
            ans=(ans+C(m,i)*C(n-t+m,m)%mod*pw[i]%mod*coef%mod)%mod;
        }
    }
    cout<<ans<<'\n';
}
signed main()
{
    pw[0]=1;
    for (int i=1;i<N;i++) pw[i]=pw[i-1]*2%mod;
    fac[0]=1;
    for (int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    inv[N-1]=quickPower(fac[N-1],mod-2);
    for (int i=N-1;i>=1;i--) inv[i-1]=inv[i]*i%mod;
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}