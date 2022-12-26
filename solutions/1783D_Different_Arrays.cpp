// Problem: Different Arrays
// URL: https://codeforces.com/problemset/problem/1783/D
// Rating: 2000
// Tags: brute force, dp, implementation
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = (int)9e4;
const int M = 11000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, a[400];
long long dp[2 * N + 1], nxt[2 * N + 1];

int main() {
	IO;
	cin >> n;
	repn(i, 1, n) cin >> a[i];
	dp[a[2] + N] = 1;
	rep(i, 2, n) {
		repn(j, - N, N) {
			if (! dp[j + N]) continue;
			nxt[a[i + 1] + j + N] += dp[j + N];
			if (j != 0) nxt[a[i + 1] - j + N] += dp[j + N];
			nxt[a[i + 1] + j + N] %= mod;
			nxt[a[i + 1] - j + N] %= mod;
		}
		repn(j, 0, 2 * N) {
		    dp[j] = nxt[j]; nxt[j] = 0;
		}
		//repn(j, N, N + 10) cout << dp[j] << " ";
		//cout << "\n";
	}
	long long ans = 0;
	repn(j, 0, 2 * N) ans = (ans + dp[j]) % mod;
	cout << ans << "\n";
	return 0;
}



