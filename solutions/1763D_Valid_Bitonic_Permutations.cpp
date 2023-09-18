// Problem: Valid Bitonic Permutations
// URL: https://codeforces.com/problemset/problem/1763/D
// Rating: 2200
// Tags: combinatorics, dp, implementation, math, number theory
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

const int N = 210000;
const int M = 11000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, i, j, x, y;
LL c[110][110];


void solve() {
	cin >> n >> i >> j >> x >> y;
	LL ans = 0;
	if (x > y && i >= 2) {
		ans = c[x - y - 1][j - i - 1] * c[y - 1][n - j];
		ans %= mod;
		if (x != n) {
			LL now = 0;
			repn(t, 2, i - 1) {
				now += c[n - x - 1][i - t - 1];
				now %= mod;
			}
			ans *= now;
			ans %= mod;
		}
	}
	else if (x < y && j <= n - 1) {
		ans = c[y - x - 1][j - i - 1] * c[x - 1][i - 1];
		ans %= mod;
		if (y != n) {
			LL now = 0;
			repn(t, j + 1, n - 1) {
				now += c[n - y - 1][t - j - 1];
				now %= mod;
			}
			ans *= now;
			ans %= mod;
		}
	}
	//cout << "ans1 = " << ans << "\n";
	if (x != n && y != n) {
		repn(t, i + 1, j - 1) {
			if (x > y && n - j > y - 1) break;
			if (x < y && i - 1 > x - 1) break;
			int a = x, b = y;
			int l1 = t - i - 1, l2 = j - t - 1, t1 = i - 1, t2 = n - j;
			if (a < b) {
				swap(a, b);
				swap(l1, l2);
				swap(t1, t2);
			} 
			//cout << a << " "<< l1 << " " << t1 << "\n";
			//cout << b << " "<< l2 << " " << t2 << "\n";
			if (n - a - 1 < l1) continue;
			if (n - a - 1 > l1 + l2) continue;
			if (n - b - 2 < l1 + l2) continue;
			LL now = c[n - a - 1][l1] * c[a - b - 1][l2 + l1 - (n - a - 1)];
			now %= mod;
			//cout << now << "\n";
			now *= c[b - 1][t2];
			now %= mod;
			
			ans += now;
			ans %= mod;
		}
	}
	cout << ans << "\n";
}

int main() {
    IO;
    c[0][0] = 1; 
    repn(i, 1, 100) {
    	c[i][0] = 1;
    	repn(j, 1, i) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
    int t;
    cin >> t;
    repn(i, 1, t) solve();
    return 0;
}




