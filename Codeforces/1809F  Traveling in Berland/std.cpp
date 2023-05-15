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
int n,m,s[N],a[N],b[N],pre[N],suf[N],nxt[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i],a[i+n]=a[i];
	for (int i=1;i<=n;i++)
		cin>>b[i],b[i+n]=b[i];
	for (int i=1;i<=2*n;i++)
	{
		s[i]=s[i-1]+a[i-1];
	}
	poly g;
	g.push_back(0);
	for (int i=1;i<=2*n;i++)
		if (b[i]==1) g.push_back(i);
	g.push_back(2*n+1);
	for (int i=1;i<g.size();i++)
	{
		pre[i]=pre[i-1];
		pre[i]+=(s[g[i]]-s[g[i-1]])+max(0ll,s[g[i]]-s[g[i-1]]-m);
	}
	for (int i=1;i<=n;i++)
	{
		int l=lower_bound(g.begin(),g.end(),i)-g.begin();
		int r=upper_bound(g.begin(),g.end(),i+n)-g.begin()-1;
		if (l>r)
		{
			cout<<b[i]*(s[i+n]-s[i])<<' ';
			continue;
		}
		int ans=0;
		// cout<<g[l]<<" "<<g[r]<<'\n';
		ans+=(s[g[l]]-s[i])*b[i];
		// cout<<(s[g[l]]-s[i])*b[i]<<"!!!"<<" "<<(s[i+n]-s[g[r]])+max(s[i+n]-s[g[r]]-m,0ll)<<endl;
		ans+=pre[r]-pre[l];
		ans+=(s[i+n]-s[g[r]])+max(s[i+n]-s[g[r]]-m,0ll);
		cout<<ans<<" ";
	}	
	cout<<'\n';
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