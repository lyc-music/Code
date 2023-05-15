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
#define N 200005
using namespace std;
int a[N];
poly G[N];
int n;
map<int,int>Mp[N];
int ans;
void dfs(int k,int fa)
{
	a[k]^=a[fa];
	int c=0;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		if (Mp[u].size()>Mp[c].size()) c=u;
	}
	if (!c)
	{
		Mp[k][a[k]]=1;
		return;
	}
	int mx=1;
	for (auto u:G[k])
	{
		if (u==c||u==fa) continue;
		for (auto [v,o]:Mp[u]) Mp[k][v]++;
	}
	for (auto [v,o]:Mp[k])
		mx=max(mx,o+(int)Mp[c].count(v));
	ans+=G[k].size()-(k!=1)-mx;
	// cout<<"?"<<k<<" "<<mx<<" "<<ans<<'\n';
	if (mx==1)
	{
		swap(Mp[k],Mp[c]);
		for (auto u:G[k])
		{
			if (u==c||u==fa) continue;
			for (auto v:Mp[u]) Mp[k][v.fi]=1;
		}
	}
	else
	{
		map<int,int>nxt;
		for (auto [v,o]:Mp[k])
			if (o+(int)Mp[c].count(v)==mx) nxt[v]=1;
		Mp[k]=nxt;
	}
	for (auto u:G[k])
	{
		if (u==fa) continue;
		map<int,int>().swap(Mp[u]);
	}
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	cout<<ans+(!Mp[1].count(0))<<'\n';
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