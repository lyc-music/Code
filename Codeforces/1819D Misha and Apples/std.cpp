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
int n,m,C[N],pre[N],sz[N],lst[N],s[N];
void BellaKira()
{
    map<int,int>Mp;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        C[i]=(C[i-1]+(x==0));
        sz[i]=x;
        lst[i]=0;
        while (x--)
        {
            int y;
            cin>>y;
            lst[i]=max(lst[i],Mp[y]);
            Mp[y]=i;
        }
        // cout<<"!!!"<<lst[i]<<endl;
    }
    pre[0]=1;
    s[0]=1;
    int l=0;
    int r=0;
    for (int i=1;i<=n;i++)
    {
        pre[i]=0;
        s[i]=s[i-1];
        while (l<=i&&l<lst[i-1]) l++;
        r=max(r,l);
        while (r<=i&&r<lst[i]) r++;
        // cout<<i<<","<<pre[i]<<" "<<l<<" "<<r<<" "<<lst[i]<<endl;
        while (r<=i&&C[i]-C[r]>0) r++;
        if (r>l&&s[r-1]-((l==0)?0:s[l-1])>0) pre[i]=1;
        s[i]=s[i-1]+pre[i];
        // cout<<i<<","<<pre[i]<<" "<<l<<" "<<r<<endl;
    }
    int ans=0;
    int mx=lst[n];
    int tot=0;
    for (int i=n;i>=1&&i>mx;i--)
    {
        tot+=sz[i];
        if (pre[i-1])
        {
            // cout<<"!!"<<i<<endl;
            ans=max(ans,(C[n]-C[i-1])>0?m:tot);
        }
        mx=max(mx,lst[i-1]);
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