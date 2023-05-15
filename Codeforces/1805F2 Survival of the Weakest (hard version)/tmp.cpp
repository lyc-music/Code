// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
struct mint
{
    unsigned v;
    mint(unsigned v_ = 0) : v(v_) {}
    mint operator-() const { return v ? MOD - v : *this; }
    mint &operator+=(const mint &X) { return (v += X.v) >= MOD ? v -= MOD : v, *this; }
    mint &operator-=(const mint &X) { return (v += MOD - X.v) >= MOD ? v -= MOD : v, *this; }
    mint &operator*=(const mint &X) { return v = 1llu * v * X.v % MOD, *this; }
    mint &operator/=(const mint &X) { return *this *= X.inv(); }
    mint pow(long long B) const
    {
        B %= MOD - 1;
        if (B < 0)
            B += MOD - 1;
        mint res = 1, A = *this;
        while (B)
        {
            if (B & 1)
                res *= A;
            B >>= 1;
            A *= A;
        }
        return res;
    }
    mint inv() const { return pow(MOD - 2); }
    friend mint operator+(const mint &A, const mint &B) { return mint(A) += B; }
    friend mint operator-(const mint &A, const mint &B) { return mint(A) -= B; }
    friend mint operator*(const mint &A, const mint &B) { return mint(A) *= B; }
    friend mint operator/(const mint &A, const mint &B) { return mint(A) /= B; }
    friend std::istream &operator>>(std::istream &A, mint &B) { return A >> B.v; }
    friend std::ostream &operator<<(std::ostream &A, const mint &B) { return A << B.v; }
    friend bool operator==(const mint &A, const mint &B) { return A.v == B.v; }
    explicit operator bool() const { return v; }
};
int n;
std::vector<int> a;
mint solve(int tim)
{
    if (tim == 0)
        return a.front();
    mint res;
    {
        std::vector<int> b, g(a.size(), 0);
        res += a.front() * mint(2).pow(tim);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
        for (std::size_t i = 1; i != a.size(); ++i)
            a[i] -= a[0];
        a[0] = 0;
        for (std::size_t i = 1; i != a.size(); ++i)
            que.push({a[i] + a[0], i});
        while (int(b.size()) < std::min(60, tim))
        {
            std::pair<int, int> now = que.top();
            que.pop();
            b.push_back(now.first);
            if (++g[now.second] != now.second)
                que.push({a[now.second] + a[g[now.second]], now.second});
        }
        a = b;
    }
    return res + solve(tim - 1);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());
    a.resize(std::min(n, 60));
    std::cout << solve(n - 1) << std::endl;
    return 0;
}