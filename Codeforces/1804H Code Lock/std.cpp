#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf ((int)1e9)
#define mod 998244353
// #define int ll
#define N 16
using namespace std;
const int inv2=((mod+1)/2);
int n;
int f[N][1<<N];
int cnt[N][N];
int coef[1<<N];
struct node
{
	int x;
	int y;
	node(int a=inf,int b=0)
	{
		x=a,y=b;
	}
};
node dp[1<<N],ans;
inline void chkmn(node &x,node y)
{
	if (y.x<x.x) x=y;
	else if (y.x==x.x) x.y=x.y+y.y;
}
inline int calc(int k)
{
	int x=((1<<n)-1)^k;
	int res=0;
	for (int i=0;i<n;i++)	
		if ((k>>i)&1)
		{
			res+=f[i][x];
		}
	return res;
}
void BellaKira()
{
	cin>>n;
	int o;
	cin>>o;
	string st;
	cin>>st;
	node ans;
	for (int i=1;i<st.size();i++)
	{
		if (st[i]==st[i-1]) continue;
		cnt[st[i-1]-'a'][st[i]-'a']++;
		cnt[st[i]-'a'][st[i-1]-'a']++;
	}
	for (int i=0;i<n;i++)
		for (int j=1;j<(1<<n);j++)
			f[i][j]=f[i][j-(j&-j)]+cnt[i][__lg(j&-j)];
	for (int i=0;i<(1<<n);i++)
	{
		coef[i]=calc(i);
	}
	poly g;
	for (int st=0;st<(1<<n);st++)
		if (__builtin_popcount(st)==n/2&&(n%2==0&&st%2==1||n%2==1&&st%2==0))
		{
			dp[0]=node(0,1);
			for (int j=0;j<(1<<n);j++)
				if (dp[j].y)
				{
					int p=__builtin_popcount(st^j);
					if ((n%2)||(p==n/2))
						dp[j].x+=coef[j^st];
					if (p==n/2)
					{
						if (__builtin_popcount(j)>=n-1) 
						{
							chkmn(ans,dp[j]);
						}
						for (int k=1;k<n;k++)
						{
							if (!((j>>k)&1)&&!(((j^st)>>k)&1))
								chkmn(dp[j^(1<<k)],dp[j]);
						}
					} else
					{
						if (__builtin_popcount(j)>=n-1) 
						{
							chkmn(ans,dp[j]);
						}
						for (int k=1;k<n;k++)
							if (!((j>>k)&1)&&(((j^st)>>k)&1))
								chkmn(dp[j^(1<<k)],dp[j]);
					}
				}
			for (int j=0;j<(1<<n);j++)
				if (dp[j].y) dp[j]=node();
		}
	// cout<<"??"<<ans.x<<endl;
	cout<<(ans.x)/(1+n%2)+o<<'\n'<<ans.y<<'\n';		
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