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
#define N 1000005
using namespace std;
int n,m,a[N],lst[N],fac[N],inv[N],dp[N];
inline int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1,j=1;i<=n;i++)
	{
		while (j<=n&&a[i]-a[j]>m)
		{
			j++;
		}
		lst[i]=j;
	}
	dp[n]=1;
	for (int i=n;i>=1;i--)
	{
		dp[i-1]=(dp[i-1]+dp[i]*(n-i)%mod)%mod;
		int tot=i-lst[i];
		if (tot==0)
			dp[i-1]=(dp[i-1]+dp[i])%mod;
		else
			dp[lst[i]-1]=(dp[lst[i]-1]+dp[i]*fac[n-i+tot-1]%mod*inv[n-i-1]%mod)%mod;
	}
	cout<<dp[0]<<'\n';
}
signed main()
{
	fac[0]=1;
	for (int i=1;i<N;i++)
		fac[i]=fac[i-1]*i%mod;
	inv[N-1]=quickPower(fac[N-1],mod-2);
	for (int i=N-1;i>=1;i--)
		inv[i-1]=inv[i]*i%mod;
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}