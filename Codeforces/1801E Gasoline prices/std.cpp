#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define i128 __int128
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod ((ll)(1e18+9))
#define int ll
#define N 200005
using namespace std;
int dfn[N],rdfn[N],DFN;
i128 pw[N];
poly G[N];
int st[N][20];
int dep[N];
int fa[N];
int n,q;
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
struct node
{
	__int128 val;
	int len;
	node(__int128 a=0,int b=0)
	{
		val=a,len=b;
	}
};
node operator +(node x,node y)
{
	return (x.val*pw[y.len]%mod+y.val)%mod;
}
namespace BIT
{
	__int128 tr[N];
	void upd(int x,__int128 y){while (x<N){tr[x]+=y;x+=x&-x;}}
	__int128 qry(int x){__int128 res=0;while (x){res+=tr[x];x-=x&-x;}return res;}
}
void dfs(int k,int fa)
{
	dfn[k]=++DFN;
	rdfn[k]=DFN;
	dep[k]=dep[fa]+1;
	for (auto u:G[k])
	{
		dfs(u,k);
	}
}
void BellaKira()
{
	cin>>n;
	for (int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		G[x].push_back(i);
	}
	dfs(1,0);
	for (int j=1;j<20;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=cm(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for (int i=1;i<=n;i++)
	{
		BIT::upd(dfn[i],pw[dep[i]]*i%mod);
		BIT::upd(rdfn[i]+1,(mod-pw[dep[i]]*i%mod)%mod);
	}
	cin>>q;
	while (q--)
	{
		int a,b,x,y;
		cin>>a>>b>>x>>y;
		int l=1,r=dis(a,b);
}
signed main()
{
	pw[0]=1;
	for (int i=1;i<N;i++) pw[i]=pw[i-1]*998244353%mod;
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}