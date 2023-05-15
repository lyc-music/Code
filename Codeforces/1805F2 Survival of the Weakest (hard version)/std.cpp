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
#define mod 1000000007
#define int ll
#define N 200005
using namespace std;
int n,a[N],b[N],ps[N];
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
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	while (1)
	{
		if (n==1) break;
		int m=min(n,60ll);
		int cnt=0;
		priority_queue<pa>q;
		for (int i=2;i<=m;i++)
			a[i]-=a[1];
		ans=(ans+a[1]%mod*quickPower(2,n-1)%mod)%mod;
		a[1]=0;
		for (int i=2;i<=m;i++)
		{
			ps[i]=1,q.push(mp(-a[i]-a[ps[i]],i));
		}
		while (!q.empty()&&cnt<min(n-1,60ll))
		{
			pa u=q.top();
			q.pop();
			u.fi=-u.fi;
			b[++cnt]=u.fi;
			ps[u.se]++;
			if (ps[u.se]<u.se) q.push(mp(-a[u.se]-a[ps[u.se]],u.se));
		}
		for (int i=1;i<=min(n-1,60ll);i++)
			a[i]=b[i];
			
		n--;
	}
	cout<<(ans+a[1])%mod<<'\n';
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