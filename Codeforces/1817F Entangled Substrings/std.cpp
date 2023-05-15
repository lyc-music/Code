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
#define N 200005
using namespace std;
namespace SAM
{
	int tr[N][27];
	int L[N],Len[N],R[N];
	int pre[N];
	int nxt[N];
	bool vis[N];
	int lst=0;
	int siz[N];
	int cnt=0;
	poly G[N];
	int ans;
	int LEN;
	void insert(int v)
	{
		int now=++cnt;
		siz[now]=1;
		Len[now]=Len[lst]+1;
		R[now]=++LEN;
		while (1)
		{
			if (!tr[lst][v])
			{
				tr[lst][v]=now;
				if (lst==0) 
				{
					break;
				}
			} else
			{
				int p=tr[lst][v];
				if (Len[p]==Len[lst]+1)
				{
					pre[now]=p;
					break;
				}
				int np=++cnt;
				R[np]=R[p];
				pre[np]=pre[p];
				for (int i=0;i<26;i++) tr[np][i]=tr[p][i];
				Len[np]=Len[lst]+1;
				pre[p]=np;
				while (tr[lst][v]==p)
				{
					tr[lst][v]=np;
					if (lst==0) break;
					lst=pre[lst];
				}
				pre[now]=np;
				break;
			}
			lst=pre[lst];
		}
		lst=now;
	}
	void dfs(int k)
	{
		for (auto u:G[k])
		{
			dfs(u);
			siz[k]+=siz[u];
		}
	}
	void calc()
	{
		int res=0;
		for (int i=0;i<=cnt;i++) 
		{
			if (i)
				G[pre[i]].push_back(i);
		}
		dfs(0);
	}
}
using namespace SAM;
int s[N];
inline void add(int &x,int y)
{
	x+=y;
}
void BellaKira()
{
	string st;
	cin>>st;
	// for (int i=1;i<=200000;i++) st+='a';
	for (auto u:st) insert(u-'a');
	calc();
	for (int i=1;i<=cnt;i++)
		L[i]=R[i]-Len[i]+1;
	for (int i=1;i<=cnt;i++)
		for (int j=0;j<26;j++)
			if (siz[i]==siz[tr[i][j]])
			{
				nxt[i]=tr[i][j];
				vis[tr[i][j]]=1;
			}
	for (int i=1;i<=cnt;i++)
		if (!vis[i])
		{
			poly g;
			int now=i;
			while (now)
			{
				g.push_back(now);
				now=nxt[now];
			}
			int mn=st.size()+1,mx=0;
			for (auto u:g)
			{
				int l=R[u]-Len[u]+1;
				int r=R[u]-Len[pre[u]];
				mn=min(mn,l-1);
				mx=max(mx,r);
			}
			for (int j=mn;j<=mx;j++)
				s[j]=0;
			for (auto u:g)
			{
				if (R[u]+1<=mx&&R[u]+1>=mn)
					add(s[R[u]+1],Len[u]-Len[pre[u]]);
			}
			for (int j=mn+1;j<=mx;j++)
				add(s[j],s[j-1]);
			for (int j=mn+1;j<=mx;j++)
				add(s[j],s[j-1]);
			for (auto u:g)
			{
				int l=R[u]-Len[u]+1;
				int r=R[u]-Len[pre[u]];
				add(ans,s[r]);
				add(ans,-s[l-1]);
			}
		}
	cout<<ans<<'\n';


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