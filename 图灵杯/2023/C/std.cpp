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
#define N 2005
using namespace std;
int n,x[N],y[N],cnt;
pa A[N*N];
int vis1[N];
int bb[N],vis[N];
inline int dis(int i,int j)
{
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
mt19937_64 rnd(time(0));
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		bb[i]=vis[i]=vis1[i]=0;
	for (int i=1;i<=n;i++)
	{
		// cin>>x[i]>>y[i];
		x[i]=1,y[i]=rnd()%1000000000;
	}
	sort(y+1,y+n+1);
	for (int i=2;i<=n;i++) 
		cout<<x[i]<<" "<<y[i]-y[i-1]<<endl;
	cnt=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j)
				A[++cnt]=mp(i,j);
	sort(A+1,A+cnt+1,[&](pa x,pa y)
	{
		return dis(x.fi,x.se)<dis(y.fi,y.se);
	});
	for (int i=1,j=1;i<=cnt;i++)
	{
		while (j<=cnt&&dis(A[j].fi,A[j].se)<dis(A[i].fi,A[i].se))
		{
			if (bb[j]==1) vis1[A[j].fi]=1;
			j++;
		}
		if (!vis1[A[i].se])
		{
			bb[i]=1;
		}
		if (i==cnt) 
		{
			while (j<=cnt)
			{
				if (bb[j]==1) vis1[A[j].fi]=1;
				j++;
			}
		}
		cout<<A[i].fi<<" "<<A[i].se<<" "<<bb[i]<<" "<<dis(A[i].fi,A[i].se)<<'\n';
	}
	for (int i=1;i<=n;i++)	cout<<vis1[i];
	cout<<endl;

}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	T=100;
	while (T--)
	{
		BellaKira();
	}
}