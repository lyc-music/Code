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
#define N 2000005
using namespace std;
int n,a[N],b[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		while (a[i]<a[i-1]) a[i]+=100000;
	}
	for (int i=1;i<=n;i++) b[i]=i;
	cout<<2*n+1<<'\n';
	int s=0;
	for (int i=n;i>=1;i--)
	{
		cout<<2<<" "<<i+s<<'\n';
		cout<<1<<" "<<a[i]-a[i-1]<<'\n';
		s+=a[i]-a[i-1];
	}
	cout<<2<<" "<<100000<<'\n';
}
signed main()
{
	// freopen("sample2.in","r",stdin);
	// freopen("1.out","w",stdout);
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}