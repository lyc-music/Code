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
// #define int ll
#define N 1000105
using namespace std;
int now[N],mx[N];
int a[N];
int n,ans;
inline ll quickPower(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void chk(int x)
{
	for (int i=0;i<=50+n;i++) now[i]=0;
	for (int i=1;i<x;i++)
		for(int j=0;j<30;j++)
			now[n-i+j]-=((a[i]>>j)&1);
	for (int i=n;i>x+1;i--)
		for(int j=0;j<30;j++)
			now[i+j-1]+=((a[i]>>j)&1);

	for (int i=x;i<=x;i++)
		for(int j=0;j<30;j++)
			now[n-i+1+j]-=((a[i]>>j)&1);
	for (int i=x+1;i>=x+1;i--)
		for(int j=0;j<30;j++)
			now[i+j]+=((a[i]>>j)&1);
	// cout<<"!!"<<x<<endl;
	// for (int i=n+5;i>=0;i--)
	// 	cout<<now[i];
	// cout<<endl;
	for (int i=0;i<=50+n;i++) 
		now[i+1]+=now[i]/2,now[i]%=2;
	bool bl=0;
	for (int i=50+n;i>=0;i--)
	{
		if (now[i]>0) break;
		if (now[i]<0) 
		{
			bl=1;
			break;
		}
	}
	// cout<<"!!"<<x<<endl;
	// for (int i=n+10;i>=0;i--)
	// 	cout<<now[i];
	// cout<<endl;
	if (bl)
	{
		for (int i=0;i<=50+n;i++) now[i]=-now[i];
	}
	for (int i=0;i<=50+n;i++) 
		if (now[i]<0)
		{
			now[i+1]+=(now[i]-1)/2;
			now[i]-=((now[i]-1)/2)*2;
		}
	for (int i=50+n;i>=0;i--)
		if (now[i]>mx[i])
		{
			for (int j=0;j<=50+n;j++)
				mx[j]=now[j];
			return;
		}
		else
		if (now[i]<mx[i])
		{
			return;
		}
}
mt19937_64 rnd(time(0));
void BellaKira()
{
	ans=0;
	cin>>n;
	for (int i=0;i<=50+n;i++) mx[i]=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1,j=31;i<n&&j>0;i++)
		if (a[i]!=a[i+1]) chk(i),j--;
	for (int i=n-1,j=31;i>=1&&j>0;i--)
		if (a[i]!=a[i+1]) chk(i),j--;
	ll x=quickPower(quickPower(2,mod-2),n);
	for (int i=0;i<=50+n;i++)
	{
		if (mx[i]) ans=(ans+x)%mod;
		x=(x+x>=mod)?x+x-mod:x+x;
	}
	cout<<ans<<'\n';
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