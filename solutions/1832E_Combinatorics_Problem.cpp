// Problem: Combinatorics Problem
// URL: https://codeforces.com/problemset/problem/1832/E
// Rating: 2200
// Tags: brute force, combinatorics, dp
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
typedef long double LD;
 
const int N = 11000000;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;
 
 
int n, k;
LL a[N], x, y, m, b[6][N], ans;
LL f[N], ff[N], inv[N];

LL C(int n, int m) {
	if (n < m) return 0;
	LL res = (f[n] * inv[m]) % mod;
	res = (res * inv[n - m]) % mod;
	return res;
}

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
	cin >> n >> a[1] >> x >> y >> m >> k;
	repn(i, 2, n) {
		a[i] = a[i - 1] * x + y;
		a[i] %= m;
	}
	repn(i, 1, n) b[0][i] = (a[i] + b[0][i - 1]) % mod;
	repn(j, 1, k) {
		repn(i, 1, n) {
			b[j][i] = b[j - 1][i - 1] + b[j][i - 1];
			b[j][i] += C(1, j) * a[i];
			b[j][i] %= mod;
		}
	}
	repn(i, 1, n) {
		ans ^= i * b[k][i];
	}
	cout << ans << "\n";
	return 0;
}

