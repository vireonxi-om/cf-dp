// Problem: Count BFS Graph
// URL: https://codeforces.com/problemset/problem/1906/J
// Rating: 2100
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

const int N = 5100;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, a[N];
// 0 - nostart; 1 - continue
LL dp[N][N][2], pw[N];
void upd(LL &x, LL v) {
	x = (x + v) % mod;
}
int main() {
	IO;
	pw[0] = 1;
	rep(i, 1, N) pw[i] = pw[i - 1] * 2 % mod;
	cin >> n;
	repn(i, 1, n) cin >> a[i];
	dp[1][1][0] = 1;
	repn(i, 1, n) {
		repn(j, i, n) {
			upd(dp[i + 1][j][0], dp[i][j][0] * pw[j - i] % mod);
			if (j < n) upd(dp[i][j + 1][1], dp[i][j][0] * pw[j - i] % mod);
			if (j < n && a[j + 1] > a[j]) upd(dp[i][j + 1][1], dp[i][j][1]);
			upd(dp[i + 1][j][0], dp[i][j][1]);
		}
	}
	cout << dp[n + 1][n][0] << "\n";
	return 0;
}