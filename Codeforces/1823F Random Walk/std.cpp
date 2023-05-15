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
int n,s,t;
poly G[N];
int vis[N],ffa[N];
int A[N],B[N];
int ans[N];
inline int quickPower(int x,int y)
{
    int res=1;
    while (y)
    {
        if (y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
void dfs(int k,int fa)
{
    ffa[k]=fa;
    for (auto u:G[k])
    {
        if (u==fa) continue;
        dfs(u,k);
    }
}
int now;
void dfs1(int k,int fa)
{
    // if (!vis[k])
    ans[k]=now*G[k].size()%mod;
    // cout<<"!!!!!"<<k<<","<<ans[k]<<" "<<now<<endl;
    for (auto u:G[k])
    {
        if (u==fa||vis[u]) continue;
        dfs1(u,k);
    }
}
void BellaKira()
{
    cin>>n>>s>>t;
    for (int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(s,0);
    int x=t;
    int o=0;
    while (1)
    {
        vis[x]=1;
        ans[x]=o;
        o++;
        // cout<<x<<" "<<ans[x]<<endl;
        if (x==s) break;
        x=ffa[x];
    }
    for (int i=1;i<=n;i++)
        if (vis[i])
            now=ans[i],dfs1(i,0);
    ans[t]=1;
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<'\n';
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