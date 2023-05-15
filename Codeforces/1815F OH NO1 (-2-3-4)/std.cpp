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
int n,m,a[N];
int f[N][3];
int ans[N][3];
int vis[N];
poly G[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<3;j++)
		{
			cin>>f[i][j],a[f[i][j]]+=3;
			G[f[i][j]].push_back(i);
		}
	}
	priority_queue<pa>q;
	for (int i=1;i<=n;i++)
		vis[i]=0;
	for (int i=1;i<=n;i++)
		q.push(mp(-a[i],i));
	while (!q.empty())
	{
		int val=-q.top().fi;
		int u=q.top().se;
		q.pop();
		if(a[u]!=val) continue;
		for (auto id:G[u])
		{
			int t=0;
			for (int j=0;j<3;j++)
				t+=vis[f[id][j]];
			for (int j=0;j<3;j++)
				if (f[id][j]!=u&&!vis[f[id][j]]) a[f[id][j]]++,q.push(mp(-a[f[id][j]],f[id][j]));
			if (t==0)
			{
			} else
			if (t==1)
			{
				int x=-1,y=-1;
				for (int j=0;j<3;j++)
					if (f[id][j]==u) y=j;
					else if (vis[f[id][j]]) x=j;
				if (x==0&&y==1) ans[id][0]=1,ans[id][1]=3,ans[id][2]=2;
				if (x==1&&y==0) ans[id][0]=1,ans[id][2]=3,ans[id][1]=2;
				if (x==0&&y==2) ans[id][2]=1,ans[id][1]=3,ans[id][0]=2;
				if (x==2&&y==0) ans[id][2]=1,ans[id][0]=3,ans[id][1]=2;
				if (x==1&&y==2) ans[id][1]=1,ans[id][2]=3,ans[id][0]=2;
				if (x==2&&y==1) ans[id][1]=1,ans[id][0]=3,ans[id][2]=2;
			}
		}
		vis[u]=1;
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<3;j++)
		{
			cout<<ans[i][j]<<" ";
			a[f[i][j]]-=3;
		}
		cout<<'\n';
	}	
	cout<<'\n';
	for (int i=1;i<=n;i++)
		poly().swap(G[i]);
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}