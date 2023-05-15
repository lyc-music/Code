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
int n,l,r,vis[N];
poly G[N];
int ans,tot;
void dfs(int x)
{
	tot++;
	vis[x]=1;
	for (auto u:G[x])
		if (!vis[u]) dfs(u);
}
void BellaKira()
{
	cin>>n;
	cin>>l>>r;
	for (int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			tot=0;
			dfs(i);
			if (tot<l+r) ans^=(tot/l);
		}
	if (ans==0) cout<<"Bob\n";
	else cout<<"Alice\n";
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