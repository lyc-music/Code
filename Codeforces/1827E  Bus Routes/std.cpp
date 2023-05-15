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
// #define int ll
#define N 500005
using namespace std;
int dep[N],dfn[N],DFN;
int st[N][20];
int idfn[N];
int Val[N];
pa E[N];
int V[N];
int fa[N];
poly G[N],P[N];
int n,m,yz[N];
inline int cm(int x,int y)
{
	if (dep[x]<dep[y]) return x;
	return y;
}
inline int lca(int x,int y)
{
	if (x==y) return x;
	if (dfn[x]>dfn[y]) swap(x,y);
	x=dfn[x]+1;
	y=dfn[y];
	int t=__lg(y-x+1);
	return fa[cm(st[x][t],st[y-(1<<t)+1][t])];
}
void dfs(int k,int fa)
{
	::fa[k]=fa;
	dep[k]=dep[fa]+1;
	dfn[k]=++DFN;
	idfn[DFN]=k;
	st[DFN][0]=k;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
	}
}
void dfs1(int k,int fa)
{
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs1(u,k);
		V[k]+=V[u];
	}
}
void BellaKira()
{
	mt19937_64 rnd(time(0));
	cin>>n>>m;
	// n=500000,m=500000;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		// y=i+1;
		// x=1;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
		if (G[i].size()==1) yz[i]=1;
		else yz[i]=0;
	for (int i=1;i<=n;i++)
		if (yz[i]) P[i].push_back(i);
	for (int i=1;i<=m;i++)
	{
		cin>>E[i].fi>>E[i].se;
		// E[i].fi=rnd()%n+1,E[i].se=rnd()%n+1;
		// E[i].fi=i;
		if (yz[E[i].fi])
		{
			P[E[i].fi].push_back(E[i].se);
		}
		if (yz[E[i].se])
		{
			P[E[i].se].push_back(E[i].fi);
		}
	}
	DFN=0;
	dfs(1,0);
	for (int j=1;j<20;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=cm(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	poly allyz;
	for (int i=1;i<=n;i++)
		if (yz[i])
		{
			sort(P[i].begin(),P[i].end(),[&](int x,int y)
			{
				return dfn[x]<dfn[y];
			});
			allyz.push_back(i);
		}
	int l=0,r=(int)allyz.size()-1;
	int pos=allyz.size();
	int lst=-1;
	for (int i=1;i<=n;i++) V[i]=0;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		for (int i=1;i<=n;i++) Val[i]=0;
		if (mid>lst)
		{
			for (int ii=lst+1;ii<=mid;ii++)
			{
				int i=allyz[ii];
				// cout<<"ins "<<i<<'\n';
				for (int j=0;j<P[i].size();j++)
				{
					V[P[i][j]]+=2;
					V[lca(P[i][j],P[i][(j+1)%P[i].size()])]-=2;
				}
				int nw=lca(P[i][0],P[i].back());
				V[nw]+=2;V[fa[nw]]-=2;
			}
		} else
		{
			for (int ii=lst;ii>mid;ii--)
			{
				int i=allyz[ii];
				// cout<<"del "<<i<<'\n';
				for (int j=0;j<P[i].size();j++)
				{
					V[P[i][j]]+=-2;
					V[lca(P[i][j],P[i][(j+1)%P[i].size()])]-=-2;
				}
				int nw=lca(P[i][0],P[i].back());
				V[nw]+=-2;V[fa[nw]]-=-2;
			}
		}
		lst=mid;
		for (int i=n;i>=1;i--)
			Val[idfn[i]]+=V[idfn[i]],Val[fa[idfn[i]]]+=Val[idfn[i]];
		bool bl=1;
		for (int i=1;i<=n;i++)
			if (Val[i]==2*(mid+1))
			{
				bl=0;
			}
		// cout<<"??"<<mid<<" "<<Val[2]<<" "<<V[2]<<" "<<V[4]<<" "<<2*(mid+1)<<" "<<allyz[mid]<<endl;
		if (bl)
		{
			pos=mid;
			r=mid-1;
		} else l=mid+1;
	}
	if (pos==allyz.size())
	{
		cout<<"YES\n";
	}
	else
	{
		int ansx=0,ansy=0;
		cout<<"NO\n";
		for (int i=1;i<=n;i++)
			V[i]=0;
		DFN=0;
		dfs(allyz[pos],0);
		for (int j=1;j<=20;j++)
			for (int i=1;i+(1<<j)-1<=n;i++)
				st[i][j]=cm(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		for (int i=1;i<=n;i++)
			if (yz[i])
			{
				sort(P[i].begin(),P[i].end(),[&](int x,int y)
				{
					return dfn[x]<dfn[y];
				});
			}
		for (int i=allyz[pos];i<=allyz[pos];i++)
		{
			for (int j=0;j<P[i].size();j++)
			{
				V[P[i][j]]+=2,
				V[lca(P[i][j],P[i][(j+1)%P[i].size()])]-=2;
			}
			V[lca(P[i][0],P[i].back())]+=2;
			V[fa[lca(P[i][0],P[i].back())]]-=2;
		}
		dfs1(allyz[pos],0);
		for (int ii=0;ii<pos;ii++)
		{
			int i=allyz[ii];
			int o=lca(P[i][0],P[i].back());
			if (V[o]==0)
			{
				ansx=allyz[ii],ansy=allyz[pos];
			}
		}
		cout<<ansx<<" "<<ansy<<'\n';
	}
	for (int i=1;i<=n;i++) poly().swap(P[i]),poly().swap(G[i]);
	
		

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