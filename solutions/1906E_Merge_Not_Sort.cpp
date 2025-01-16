// Problem: Merge Not Sort
// URL: https://codeforces.com/problemset/problem/1906/E
// Rating: 1900
// Tags: constructive algorithms, dp
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

const int N = 2100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, cnt, f[N][N], a[N];
vector<int> g[N];
int len[N], s[N], t[N];
int main() {
	IO;
	cin >> n;
	repn(i, 1, n + n) cin >> a[i];
	int l = 1, r;
	while (l <= n + n) {
		r = l;
		while (r + 1 <= n + n && a[r + 1] < a[l]) r++;
		cnt++;
		len[cnt] = r - l + 1;
		repn(i, l, r) g[cnt].pb(a[i]);
		reverse(all(g[cnt]));
		l = r + 1;
	}
	memset(f, -1, sizeof(f));
	f[0][0] = 0;
	rep(i, 0, cnt) {
		repn(j, 0, n) if (f[i][j] != -1) f[i + 1][j] = j;
		int l = len[i + 1];
		repn(j, l, n) {
			if (f[i][j - l] != -1) f[i + 1][j] = j - l;
		}
	}
	if (f[cnt][n] == -1) {
		cout << "-1\n";
	}
	else {
		int st = n, ns = 0, nt = 0;
		pern(i, 1, cnt) {
			if (f[i][st] == st) {
				for (auto x: g[i]) t[++nt] = x;
			}
			else {
				for (auto x: g[i]) s[++ns] = x;
			}
			st = f[i][st];
		}
		reverse(s + 1, s + ns + 1);
		reverse(t + 1, t + nt + 1);
		repn(i, 1, n) cout << s[i] << " \n"[i == n];
		repn(i, 1, n) cout << t[i] << " \n"[i == n];
	}
	return 0;
}