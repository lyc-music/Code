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
#define N 500005
using namespace std;
void BellaKira()
{
    int n;
    cin>>n;
    unordered_map<int,int>Mp;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        Mp[x]++;
    }
    int ans=0;
    for (auto [x,y]:Mp)
    {
        ans+=y*(y-1)*(y-2);
        for (int j=1;j*j*j<=x;j++)
        {
            if (x%j!=0) continue;
            if (j>1)
            {
                if (x%j==0&&(x/j)%j==0)
                {
                    if (Mp.count(x/j)&&Mp.count(x/j/j))
                    ans=(ans+y*Mp[x/j]*Mp[x/j/j]);
                }
                //     if (Mp.count(x/j)&&Mp.count(x/j/j))
                // cout<<"calc0 "<<x/j/j<<" "<<x/j<<" "<<x<<" "<<endl;
                if (j*j*j==x) continue;
            }
            int k=(sqrt(x/j));
            if (k>1&&j*k*k==x)
            {   
                if (Mp.count(x/k)&&Mp.count(x/k/k))
                    ans=(ans+y*Mp[x/k]*Mp[x/k/k]);
                // if (Mp.count(x/k)&&Mp.count(x/k/k))
                // cout<<"calc1 "<<x/k/k<<" "<<x/k<<" "<<x<<" "<<endl;
            }
        }
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