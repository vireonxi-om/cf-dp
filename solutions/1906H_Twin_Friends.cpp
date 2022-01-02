// Problem: Twin Friends
// URL: https://codeforces.com/problemset/problem/1906/H
// Rating: 2200
// Tags: combinatorics, dp
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 210000;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, m;
string s, t;
int ca[27], cb[27];
LL dp[27][N];
LL pow_mod(LL a, LL e) {
	LL res = 1;
	for (; e; a = a * a % mod, e >>= 1) if (e & 1) res = res * a % mod;
	return res;
}
LL f[N], inv[N], ff[N];
LL C(int n, int m) {
	if (n < m) return 0;
	LL res = (f[n] * inv[m]) % mod;
	res = (res * inv[n - m]) % mod;
	return res;
}
const int B = 26;
int main() {
	IO;
	f[0] = 1;
	rep(i, 1, N) f[i] = (f[i - 1] * i) % mod;
	ff[1] = ff[0] = inv[1] = inv[0] = 1;  
	rep(i, 2, N) {
    	inv[i] = (LL)(mod - mod / i) * inv[mod % i] % mod;
    	ff[i] = inv[i];
	}
	rep(i, 2, N) inv[i] = (inv[i - 1] * inv[i]) % mod;
	rep(i, 0, N) dp[0][i] = 1;
	cin >> n >> m;
	cin >> s;
	cin >> t;
	rep(i, 0, n) ca[s[i] - 'A']++;
	rep(i, 0, m) cb[t[i] - 'A']++;
	repn(i, 1, B) {
		rep(j, 0, N) {
			int mk = j + cb[i - 1] - ca[i - 1];
			if (mk >= 0) dp[i][j] = dp[i - 1][mk] * C(ca[i - 1], j) % mod;
		}
		rep(j, 1, N) dp[i][j] = (dp[i][j - 1] + dp[i][j]) % mod;
	}
	LL ans = dp[B][0] * f[n] % mod;
	rep(i, 0, B) ans = ans * inv[ca[i]] % mod;
	cout << ans << "\n";
	return 0;
}