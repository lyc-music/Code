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
#define N 100005
using namespace std;
int n,m,op[N],c[N];
poly G[N];
int vis[N];
int ans[N];
mt19937_64 rnd(time(0));
void BellaKira()
{
	int lstm=-1;
	// cin>>n>>m;
	n=1,m=100000;
	if ((n>2000||m>2000)&&n*m>100000) lstm=m,m=100;
	for (int i=1;i<=m;i++)
	{
		int l,r;
		// cin>>op[i]>>l>>r>>c[i];
		op[i]=rnd()%2+1,l=rnd()%n+1,r=rnd()%n+1,c[i]=rnd()%n+1;
		if (i*2<=m) op[i]=1;
		else op[i]=2;
		if (l>r) swap(l,r);
		G[l].push_back(i);
		G[r+1].push_back(i);
	}
	int finl=0;
	for (int i=1;i<=n;i++)
	{
		for (auto u:G[i]) vis[u]^=1;
		int x=0;
		int tot=0;
		vector<pair<pa,int>>sta;
		for (int j=1;j<=m;j++)
		{
			sta.push_back(mp(mp(-inf,inf),1));
			if (vis[j]&&op[j]==1)
			{
				vector<pair<pa,int>>nxt;
				while (sta.size()&&sta.back().fi.fi<c[j])
				{
					sta.back().fi.fi=max(sta.back().fi.fi,c[j]);
					if (sta.back().fi.fi>=sta.back().fi.se)
					{
						tot+=sta.back().se;
						x=c[j];
						sta.pop_back();
					} else 
					{
						nxt.push_back(sta.back());
						sta.pop_back();
					}
				}
				while (nxt.size()) 
				{
					if (sta.size()&&nxt.back().fi==sta.back().fi) sta.back().se+=nxt.back().se;
					else
						sta.push_back(nxt.back());
					nxt.pop_back();
				}
				x=max(x,c[j]);
			} else
			if (vis[j]&&op[j]==2)
			{
				vector<pair<pa,int>>nxt;
				while (sta.size()&&sta.back().fi.se>c[j])
				{
					sta.back().fi.se=min(sta.back().fi.se,c[j]);
					if (sta.back().fi.fi>=sta.back().fi.se)
					{
						tot+=sta.back().se;
						x=c[j];
						sta.pop_back();
					} else 
					{
						nxt.push_back(sta.back());
						sta.pop_back();
					}
				}
				while (nxt.size()) 
				{
					if (sta.size()&&nxt.back().fi==sta.back().fi) sta.back().se+=nxt.back().se;
					else
						sta.push_back(nxt.back());
					nxt.pop_back();
				}
				x=min(x,c[j]);
			}
			// cout<<"???"<<tot<<'\n'
			ans[j]+=tot*x;
			// cout<<i<<","<<j<<" "<<tot<<" "<<x<<'\n';
		}
		finl=x;
	}
	for (int i=1;i<=m;i++)	cout<<ans[i]<<' ';
}
signed main()
{
	// freopen("sample2.in","r",stdin);
	freopen("1.out","w",stdout);
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}