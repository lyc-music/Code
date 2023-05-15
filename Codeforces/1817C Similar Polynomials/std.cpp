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
#define N 2500005
using namespace std;
int fac[N],inv[N];
int n;
int a[N],b[N];
int quickPower(int x,int y)
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
inline int C(int x,int y)
{
	if (x<y||y<0)return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
poly work(int *a)
{
	poly res;
	for (int i=n-1;i<=n;i++)
	{
		int now=0;
		for (int j=0;j<=i;j++)
		{
			int o=C(i,j);
			if ((i-j)&1) o=(mod-o)%mod;
			now=(now+o*a[j]%mod)%mod;
		}
		res.push_back(now);
	}
	return res;
}
void BellaKira()
{
	cin>>n;
	for (int i=0;i<=n;i++)
		cin>>a[i];
	for (int i=0;i<=n;i++)
		cin>>b[i];
	poly A=work(a),B=work(b);
	// for (auto u:A) cout<<u<<",";
	// cout<<'\n';
	// for (auto u:B) cout<<u<<",";
	// cout<<'\n';
	int o=(B[0]-A[0]+mod)%mod;
	cout<<o*quickPower(A[1],mod-2)%mod<<'\n';
}
signed main()
{
	fac[0]=1;
	for (int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	inv[N-1]=quickPower(fac[N-1],mod-2);
	for (int i=N-1;i>=1;i--)
		inv[i-1]=inv[i]*i%mod;
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}