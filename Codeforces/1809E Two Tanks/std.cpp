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
int n,a,b,v[N];
int ans[1005][1005];
void BellaKira()
{
	cin>>n>>a>>b;
	for (int i=1;i<=n;i++)
		cin>>v[i];
	for (int sm=0;sm<=a+b;sm++)
	{
		int l=max(0ll,sm-b),r=min(sm,a);
		int L=l,R=r;
		for (int i=n;i>=1;i--)
		{
			L=max(L+v[i],l);
			R=min(R+v[i],r);
		}
		// R=max(R,L);
		int ansl=L,ansr=R;
		ansl=max(min(ansl,r),l);
		ansr=max(min(ansr,r),l);
		for (int i=1;i<=n;i++)
		{
			ansl=ansl-v[i],ansr=ansr-v[i];
			ansl=max(min(ansl,r),l);
			ansr=max(min(ansr,r),l);
		}
		for (int i=l;i<=r;i++)
			if (i<=L) ans[i][sm-i]=ansl;
			else if (i>=R) ans[i][sm-i]=ansr;
			else ans[i][sm-i]=ansl+i-L;
	}
	for (int i=0;i<=a;i++)
	{
		for (int j=0;j<=b;j++)
			cout<<ans[i][j]<<" ";
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
/*
c d +v
g=min(c,b-d,v)
c-=g,d+=g
*/