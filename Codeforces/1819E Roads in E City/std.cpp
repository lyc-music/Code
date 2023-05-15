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
#define N 10005 
using namespace std;
int n,m;
int ffa[N];
pa E[N];
int vis[N];
int dep[N];
poly G[N];
mt19937_64 rnd(time(0));
int qry(int x)
{
    cout<<"? "<<x<<endl;
    int res;
    cin>>res;
    return res;
}
void dfs(int k,int fa)
{
    // cout<<k<<"....."<<dep[k]<<" "<<fa<<endl;
    ffa[k]=fa;
    for (auto u:G[k])
        if (u!=fa)
        {
            dep[E[u].fi^E[u].se^k]=dep[k]+1;
            dfs(E[u].fi^E[u].se^k,u);
        }
}
void BellaKira()
{
    const int B=30;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
        cin>>E[i].fi>>E[i].se;
    for (int i=1;i<=m;i++)
    {
        cout<<"- "<<i<<endl;
        vis[i]=1;
        for (int j=1;j<=B;j++)
        {
            if (rnd()%2) vis[i]&=qry(E[i].se);
            else vis[i]&=qry(E[i].fi);
        }
        if (!vis[i])
            cout<<"+ "<<i<<endl;
    }
    int tott=0;
    for (int i=1;i<=m;i++)
        if (!vis[i]) G[E[i].fi].push_back(i),G[E[i].se].push_back(i),tott++;
    assert(tott==n-1);
    dep[1]=1;
    dfs(1,0);
    for (int i=1;i<=m;i++) 
        if (vis[i])
        {
            if (dep[E[i].fi]<dep[E[i].se]) swap(E[i].fi,E[i].se);
            // cout<<"?"<<E[i].fi<<" "<<E[i].se<<" "<<ffa[E[i].se]<<endl;
            cout<<"- "<<ffa[E[i].fi]<<endl;
            cout<<"+ "<<i<<endl;
            for (int j=1;j<=B;j++)
            {
                if (rnd()%2) vis[i]&=qry(E[i].se);
                else vis[i]&=qry(E[i].fi);
            }
            cout<<"+ "<<ffa[E[i].fi]<<endl;
            cout<<"- "<<i<<endl;
        } else vis[i]=1;
    cout<<"! ";
    for (int i=1;i<=m;i++)
        cout<<" "<<vis[i];
        cout<<endl;
    int tt;
    cin>>tt;
    if (!tt) exit(0);
    for (int i=1;i<=n;i++) poly().swap(G[i]);

}
signed main()
{
	// IOS;
	// cin.tie(0);
	int T=1;
    cin>>T;
	while (T--)
	{
		BellaKira();
	}
}