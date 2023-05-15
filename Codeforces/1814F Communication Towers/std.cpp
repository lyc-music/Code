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
#define N 400005
using namespace std;
int fa[N];
poly G[N<<2];
int siz[N],val[N];
pa sta[N];
int tp;
int n,m;
pa E[N];
int l[N],r[N];
int gf(int x)
{
    if (x==fa[x]) return x;
    return gf(fa[x]);
}
int qrydis(int x)
{
    if (x==fa[x]) return val[x];
    return val[x]+qrydis(fa[x]);
}
void update(int k,int l,int r,int L,int R,int x)
{
    if (L<=l&&r<=R)
    {
        G[k].push_back(x);
        return;
    }
    int mid=l+(r-l)/2;
    if (L<=mid) update(k<<1,l,mid,L,R,x);
    if (R>mid) update(k<<1|1,mid+1,r,L,R,x);
}
void ins(int x,int y)
{
    int yy=y;
    x=gf(x),y=gf(y);
    if (x==y) return;
    if (siz[x]>siz[y]) swap(x,y);
    val[x]-=val[y];
    fa[x]=y;
    sta[++tp]=mp(x,y);
    siz[y]+=siz[x];
}
void work(int k,int l,int r)
{
    int lsttp=tp;
    for (auto u:G[k])
        ins(E[u].fi,E[u].se);
    if (l==r)
    {
        val[gf(1)]++;
        // if (gf(99)==gf(1)) cout<<"!!!!!!"<<l<<endl;
        // assert(gf(99)!=gf(1));
    } else
    {
        int mid=l+(r-l)/2;
        work(k<<1,l,mid);
        work(k<<1|1,mid+1,r);
    }
    while (tp!=lsttp)
    {
        int x=sta[tp].fi,y=sta[tp].se;
        tp--;
        siz[y]-=siz[x];
        val[x]=qrydis(x);
        fa[x]=x;
    }
}
void BellaKira()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>l[i]>>r[i];
    for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1,val[i]=0;
    for (int i=1;i<=m;i++)
    {
        cin>>E[i].fi>>E[i].se;
        if (max(l[E[i].fi],l[E[i].se])<=min(r[E[i].fi],r[E[i].se]))
            update(1,1,200000,max(l[E[i].fi],l[E[i].se]),min(r[E[i].fi],r[E[i].se]),i);
    }
    // cout<<"!!!"<<endl;
    work(1,1,200000);
    for (int i=1;i<=n;i++)
        if (qrydis(i)>0) cout<<i<<" ";
    cout<<'\n';
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