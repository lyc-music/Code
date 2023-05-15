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
int dp[N],ans[N],smx[N];
poly G[N];
int vis[N];
int W[N];
int ansx[N],ansy[N];
int num[N],numsmx[N];
pa E[N];
int n,q;
void dfs(int k,int fa)
{
	vis[k]=1;
	int mx=0,smx=0;
	int U=k,V=k;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		if (dp[u]+1>mx)
		{
			smx=mx;
			V=U;
			mx=dp[u]+1;
			U=num[u];
		}else 
		{
			smx=max(smx,dp[u]+1);
			if (dp[u]+1==smx) V=num[u];
		}
	}
	num[k]=U,numsmx[k]=V;
	dp[k]=mx;
	::smx[k]=smx;
	if (mx+smx>ans[k])
	{
		ans[k]=mx+smx;
		ansx[k]=U;
		ansy[k]=V;
	}
}
void dfs1(int k,int fa,int g,int nb)
{
	if (dp[k]+g>ans[k])
	{
		ans[k]=dp[k]+g;
		ansx[k]=num[k];
		ansy[k]=nb;
	}
	if (g>dp[k])
	{
		numsmx[k]=num[k];
		smx[k]=dp[k];

		dp[k]=g;
		num[k]=nb;
	} else
	if (g>smx[k])
	{
		numsmx[k]=nb;
		smx[k]=g;
	}
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs1(u,k,(dp[u]+1==dp[k])?smx[k]+1:dp[k]+1
		,(dp[u]+1==dp[k])?numsmx[k]:num[k]);
	}
}
mt19937_64 rnd(time(0));
void BellaKira()
{
	cin>>n;
    cout<<n<<'\n';
    for (int i=2;i<=n;i++)
    {
        cout<<rnd()%(i-1)+1<<" "<<i<<" "<<rnd()%10+1<<'\n';
    }
    cout<<n<<'\n';
    for (int i=1;i<=n;i++) cout<<i<<'\n';
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	// cin>>T;
    cout<<1<<'\n';
	while (T--)
	{
		BellaKira();
	}
}