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
// #define N 
using namespace std;
const long long x=1836311903;
const long long y=1134903170;
long long floor_sum(long long n, long long a, long long b, long long c) //\sum_{i=1}^n\lfloor\frac{ai+c}{b}\rfloor
{
    if (c < 0)
        return floor_sum(n, a, b, c % b + b) - n + c / b * n;
    if (n == 0)
        return 0;
    if (a == 0)
        return c / b * n;
    if (c >= b)
        return floor_sum(n, a, b, c % b) + c / b * n;
    if (a >= b)
        return floor_sum(n, a % b, b, c) + a / b * n * (n + 1) / 2;
    return (a * n + c) / b * n - floor_sum((a * n + c) / b, b, a, -c);
}
void BellaKira()
{
	int n;
	cin>>n;
	int num=n*(x-y)/x+1;
	int ans=0;
	if ((n-num)%2==0) ans=num;
	else ans=-num;
	ans+=floor_sum((n-num+1)/2,2*y,x,(n+1)*(x-y));
	ans-=floor_sum((n-num)/2,2*y,x,(n+1)*(x-y)+y);
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