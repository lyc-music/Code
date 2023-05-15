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
#define N 205
using namespace std;
int n,m,s[N],p[N],dp[N][N][N];
poly ans[N];
void BellaKira()
{
	cin>>n>>m;
	poly g;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		g.push_back(x);
	}
	for (int j=1;j<=m;j++)
		cin>>s[j],p[j]=j;
	sort(p+1,p+m+1,[&](int x,int y)
	{
		return s[x]<s[y];
	});
	for (int i=1;i<=m;i++)
	{
		int u=p[i];
		if (i==m)
		{
			int sm=0;
			for (auto v:g)
				sm=(sm+v)%s[u];
			g.push_back(s[u]-sm);
			cout<<s[u]-sm<<'\n';
		}
		for (int j=0;j<=g.size();j++)
			for (int k=0;k<=s[u];k++)
				for (int x=0;x<s[u];x++)
					dp[j][k][x]=0;
		dp[0][0][0]=1;
		for (int j=1;j<=g.size();j++)
			for(int k=0;k<j;k++)
				for (int x=0;x<s[u];x++)
					if(dp[j-1][k][x])
					{
						dp[j][k+1][(x+g[j-1])%s[u]]=1;
						dp[j][k][x]=1;
					}
		// cout<<"???"<<u<<" "<<dp[g.size()][s[u]][0]<<endl;
		poly nxt;
		for (int j=g.size(),x=s[u],y=0;j>=1;j--)
		{
			// cout<<"!!"<<j<<" "<<x<<" "<<y<<" "<<dp[j][x][y]<<" "<<(y-g[j-1]+s[u])%s[u]<<'\n';
			if (x>0&&dp[j-1][x-1][(y-g[j-1]%s[u]+s[u])%s[u]])
			{
				x--;
				y=(y-g[j-1]+s[u])%s[u];
				y=(y%s[u]+s[u])%s[u];
				ans[u].push_back(g[j-1]);
			} else
			{
				nxt.push_back(g[j-1]);
			}
		}
		nxt.swap(g);
	}
	for (int i=1;i<=m;i++)
	{
		for (auto u:ans[i]) cout<<u<<" ";
		cout<<'\n';
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