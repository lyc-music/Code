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
int n,q;
vector<pair<int,pa>>G[N];
int a[N];
int lst[N],ans[N];
struct seg
{
	int tr[N<<2],tag[N<<2];
	void update(int k,int l,int r,int L,int R,int x)
	{
		if (L<=l&&r<=R)
		{
			tag[k]+=x;
			tr[k]+=x*(r-l+1);
			return;
		}
		int mid=l+(r-l)/2;
		if (L<=mid) update(k<<1,l,mid,L,R,x);
		if (R>mid) update(k<<1|1,mid+1,r,L,R,x);
		tr[k]=tr[k<<1]+tr[k<<1|1]+tag[k]*(r-l+1);
	}
	int query(int k,int l,int r,int L,int R)
	{
		if (L<=l&&r<=R) return tr[k];
		int mid=l+(r-l)/2,res=0;
		if (L<=mid) res+=query(k<<1,l,mid,L,R);
		if (R>mid) res+=query(k<<1|1,mid+1,r,L,R);
		res+=(min(R,r)-max(L,l)+1)*tag[k];
		return res;
	}
}tr1,tr2;
set<int>S;
void ers(int x,int now)
{
	auto it=S.lower_bound(x);
	auto Lst=it,Nxt=it;
	Lst--,Nxt++;
	int lst=(*Lst);
	int nxt=(*Nxt);
	tr2.update(1,1,n,(lst)+1,x,-x);
	tr1.update(1,1,n,(lst)+1,x,x*now);

	tr1.update(1,1,n,lst+1,x,-nxt*now);
	tr2.update(1,1,n,lst+1,x,nxt);
	S.erase(it);
}	
void ins(int x,int now)
{
	S.insert(x);
	auto it=S.lower_bound(x);
	auto Lst=it;
	Lst--;
	int lst=(*Lst);
	tr2.update(1,1,n,(lst)+1,x,x);
	tr1.update(1,1,n,(lst)+1,x,-x*now);
}
void BellaKira()
{
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=q;i++)
	{
		int l,r,x,y;
		cin>>x>>y>>l>>r;
		// if (l>r||x>y) continue;
		G[r].push_back(mp(i,mp(x,y)));
		G[l-1].push_back(mp(i,mp(x,y)));
	}
	S.insert(0);
	for (int i=1;i<=n;i++)
	{
		ins(i,i);
		if (lst[a[i]]) ers(lst[a[i]],i);
		lst[a[i]]=i;
		for (auto [id,u]:G[i])
		{
			auto [l,r]=u;
			ans[id]=-ans[id];
			ans[id]+=tr1.query(1,1,n,l,r)+tr2.query(1,1,n,l,r)*(i+1);
			// cout<<"???"<<id<<" "<<l<<" "<<r<<" "<<ans[id]<<" "<<tr1.query(1,1,n,l,r)<<" "<<tr2.query(1,1,n,l,r)<<endl;
		}
	}
	for (int i=1;i<=q;i++) cout<<ans[i]<<'\n';
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