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
// #define int ll
// #define N 
using namespace std;
void BellaKira()
{
	int n,m;
	cin>>n>>m;
	if (m==n/2)
	{
		cout<<"DL\n";
	} else
	if (m<n/2)
	{
		cout<<"RDR";
		for (int i=1;i<=n/2-m;i++)
			cout<<"URDR";
		cout<<"L\n";
	} else
	{
		cout<<"LDL";
		int tot=2;
		for (int i=1;i<m-n/2;i++)
			cout<<"ULDL",tot+=1;
		cout<<"R";
		for (int i=1;i<=n/2;i++)
			cout<<"URDR";
		cout<<"L";
		cout<<"DR";
		cout<<"URDL";
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