#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 10, mod = 998244353;
int n, ts;
string str[N];
string trans(string str) {
	int n = str.size();
	for(int d = 1; d < n; d ++) if(n % d == 0) {
		int flag = 1;
		for(int i = 0, j = d; j < n; i ++, j ++) {
			if(str[i] != str[j]) {
				flag = 0;
				break;
			}
		}
		if(flag) return string(str.begin(), str.begin() + d);
	}
	return str;
}
int low[N], vis[N];
int tot, pr[N];
int foo[N], last[N];
void init(int n) {
	for(int i = 2; i <= n; i ++) {
		if(!vis[i]) pr[++ tot] = i, low[i] = i;
		for(int j = 1; j <= tot && pr[j] * i <= n; j ++) {
			vis[pr[j] * i] = 1;
			low[pr[j] * i] = pr[j];
			if(i % pr[j] == 0) {
				break;
			}
		}
	}
}
int fpw(int a, int b) {
	int ans = 1;
	for(; b; b >>= 1, a = 1ll * a * a % mod) if(b & 1) ans = 1ll * ans * a % mod;
	return ans;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	init(1e6);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> str[i];
		str[i] = trans(str[i]);
	}
	int ans = 2, cnt = 1;
	for(int i = n; i >= 1; i --) {
		int cnt0 = count(str[i].begin(), str[i].end(), '0');
		if(cnt0 & 1) {
			str[i] = str[i] + str[i];
			cnt0 *= 2;
		}
		int o = 0, len = 0, tot = 0, sum = 0;
		for(char c : str[i]) {
			if(c == '0') {
				o ^= 1;
				sum ++;
				if(o) len ++;
				else tot ++;
			} else {
				if(o) len ++;
				else sum += 2, tot ++;
			}
		}
    cout<<len<<" "<<tot<<endl;
		int gcd = 1;
		if(len) {
			for(int x = len; x != 1; x /= low[x]) {
				int p = low[x];
				if(last[p] != ts) {
					last[p] = ts;
					foo[p] = 0;
				}
				if(foo[p]) {
					gcd = 1ll * gcd * p % mod;
					foo[p] --;
				}
			}
		} else {
			gcd = cnt;
			ts ++;
		}
		int inv = fpw(gcd, mod - 2);
		ans = (1ll * ans * len % mod * inv + 1ll * sum * cnt % mod * inv) % mod;
		cnt = 1ll * cnt * inv % mod;
		if(tot == 0) {
			cnt = 1;
			ts ++;
		} else {
			for(int x = tot; x != 1; x /= low[x]) {
				int p = low[x];
				if(last[p] != ts) {
					last[p] = ts;
					foo[p] = 0;
				}
				foo[p] ++;
				cnt = 1ll * cnt * p % mod;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}