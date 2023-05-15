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
int fa[N],F[N],n;
int siz[N];
poly G[N],E[N],E1[N];
int dfn[N],rdfn[N],DFN;
int dep[N];
int ans;
int m;
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
namespace BIT
{
	int tr[N];
	void upd(int x,int y){while (x<N){tr[x]+=y;x+=x&-x;}}
	int qry(int x){int res=0;while (x){res+=tr[x];x-=x&-x;}return res;}
}
void dfs(int k,int fa)
{
	dfn[k]=++DFN;
	for (auto u:E[k])
	{
		dfs(u,k);
	}
	rdfn[k]=DFN;
}
void dfs1(int k,int fa)
{
	F[k]=F[fa]+1;
	ans-=(BIT::qry(rdfn[k])-BIT::qry(dfn[k]-1))*2;
	// cout<<"???"<<k<<" "<<F[k]<<endl;
	BIT::upd(dfn[k],1);
	for (auto u:E1[k])
	{
		dfs1(u,k);
	}
	BIT::upd(dfn[k],-1);
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
		fa[i]=i,siz[i]=1;
	for (int i=1;i<=n;i++)
	{
		for (auto u:G[i])
			if (u<i)
			{
				if (gf(u)!=gf(i))
				{
					E[i].push_back(gf(u));
					siz[i]+=siz[gf(u)];
					fa[gf(u)]=gf(i);
				}
			}
		ans+=siz[i]-1;
		// cout<<"??"<<i<<" "<<siz[i]-1<<endl;
	}
	for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for (int i=n;i>=1;i--)
	{
		for (auto u:G[i])
			if (u>i)
			{
				if (gf(u)!=gf(i))
				{
					E1[i].push_back(gf(u));
					siz[i]+=siz[gf(u)];
					fa[gf(u)]=gf(i);
				}
			}
		ans+=siz[i]-1;
	}
	// cout<<"?"<<ans<<endl;
	dfs(n,0);
	dfs1(1,0);
	cout<<ans<<'\n';
	cin>>m;
	while (m--)
	{
		int x;
		cin>>x;
		ans+=n-F[x];
		++n;
		F[n]=F[x]+1;
		cout<<ans<<'\n';
	}
	
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}