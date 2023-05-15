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
int dep[N],dfn[N],DFN;
int st[N][20];
poly G[N];
int ffa[N];
pa tr[N<<2];
int n,a[N];
int q;
void dfs(int k,int fa)
{
	ffa[k]=fa;
	dep[k]=dep[fa]+1;
	dfn[k]=++DFN;
	st[DFN][0]=k;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
	}
}
inline int chkmn(int x,int y)
{
	return (dep[x]<dep[y])?x:y;
}
inline int lca(int x,int y)
{
	if (dfn[x]>dfn[y]) swap(x,y);
	if (x==y) return x;
	x=dfn[x]+1,y=dfn[y];
	int t=__lg(y-x+1);
	return ffa[chkmn(st[x][t],st[y-(1<<t)+1][t])];
} 
inline int dis(int x,int y)
{
	return dep[x]+dep[y]-dep[lca(x,y)]*2+a[x]+a[y];
}
pa merge(pa x,pa y)
{
	pa ooo[6]={x,y,mp(x.fi,y.fi),mp(x.fi,y.se),mp(x.se,y.fi),mp(x.se,y.se)};
	// for (int i=0;i<6;i++)
	// 	cout<<ooo[i].fi<<","<<ooo[i].se<<'\n';
	// cout<<'\n';
	int mx=dis(ooo[0].fi,ooo[0].se);
	for (int i=1;i<6;i++)
	{
		int now=dis(ooo[i].fi,ooo[i].se);
		if(now>mx) ooo[0]=ooo[i],mx=now;
	}
	return ooo[0];
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		tr[k].fi=l,tr[k].se=l;
		// cout<<k<<" "<<tr[k].fi<<" "<<tr[k].se<<'\n';
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=merge(tr[k<<1],tr[k<<1|1]);
	// cout<<k<<" "<<l<<","<<r<<" "<<tr[k].fi<<" "<<tr[k].se<<'\n';
}
void update(int k,int l,int r,int L)
{
	if (l==r) return;
	int mid=l+(r-l)/2;
	if (L<=mid) update(k<<1,l,mid,L);
	else update(k<<1|1,mid+1,r,L);
	tr[k]=merge(tr[k<<1],tr[k<<1|1]);
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	for (int j=1;j<=20;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=chkmn(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	build(1,1,n);
	cin>>q;
	while (q--)
	{
		int x,y;
		cin>>x>>y;
		a[x]=y;
		update(1,1,n,x);
		cout<<max({(dis(tr[1].fi,tr[1].se)+1)/2,a[tr[1].fi],a[tr[1].se]})<<'\n';
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