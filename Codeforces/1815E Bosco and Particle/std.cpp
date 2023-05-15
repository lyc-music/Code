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
int n;
string s[N];
int a[N],b[N];
vector<pa> A[N],B[N];
int mx[N],mn[N];
inline int quickPower(int x,int y)
{
    int res=1;
    while (y){
        if (y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
string work(string x)
{
    for (int i=1;i<=x.size();i++)
        if (x.size()%i==0)
        {
            bool bl=1;
            for (int j=i;j<x.size();j++)
                bl&=(x[j]==x[j-i]);
            if (bl) return string(x.begin(),x.begin()+i);
        }
    return "";
}
vector<pa>fj(int x)
{
    vector<pa>res;
    while (x>1)
    {
        if (res.empty()||res.back().fi!=mn[x])
            res.push_back(mp(mn[x],1ll));
        else res.back().se++;
        x/=mn[x];
    }
    return res;
}
void BellaKira()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>s[i],s[i]=work(s[i]);
    for (int i=1;i<=n;i++)
    {
        int x=0;
        do
        {
            for (auto u:s[i])
            {
                x^=1;
                x^=(u-'0');
                if (x==0)
                {
                    a[i]++;
                } else b[i]++;
            }
        }while (x!=0);
        // cout<<a[i]<<" "<<b[i]<<endl;
        A[i]=fj(a[i]);
        B[i]=fj(b[i]);
    }
    int now=1;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int tag=1;
        for (auto [u,v]:A[i])
        {
            now=now*quickPower(quickPower(u,min(mx[u],v)),mod-2)%mod;
            if (v>mx[u])
                tag=tag*quickPower(u,v-mx[u])%mod;
            mx[u]=max(0ll,mx[u]-v);
        }
        ans=ans*tag%mod;
        ans=(ans+a[i]*now%mod)%mod;
        // cout<<"!!!"<<i<<" "<<endl;
        if (b[i]==0) 
        {
            now=0;
            break;
        }
        now=now*b[i]%mod;
        for (auto [u,v]:B[i])
            mx[u]+=v;
    }
    ans=(ans+now)%mod;
    ans=ans*2%mod;
    cout<<ans<<'\n';


}
signed main()
{
    for (int i=2;i<N;i++)
        if (!mn[i])
        {
            for(int j=i;j<N;j+=i)
                if (!mn[j]) mn[j]=i;
        }
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}