// Problem: Strong Password
// URL: https://codeforces.com/problemset/problem/1845/C
// Rating: 1400
// Tags: binary search, dp, greedy, strings
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k << 1
#define RC k << 1 | 1
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
typedef pair<int, LL> pii;
template<typename T> void down(T &x, T y) { if (x > y) x = y; }

const int N = 310000;
const int M = 610000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-9;
const double pi = acos(-1.0);


int a[N], dp[11], nxt[N][10], m;
string s, sl, sr;

int fm(int id, int l, int r) {
	int res = -1;
	repn(j, l, r) {
		res = max(res, nxt[id][j]);
	}
	return res;
}

void solve() {
	cin >> s;
	cin >> m >> sl >> sr;
	int n = s.length();
	repn(i, 1, n) a[i] = s[i - 1] - '0';
	repn(i, 0, 9) {
		nxt[n][i] = n + 1; nxt[n + 1][i] = n + 1;
	}
	per(i, 0, n) {
		repn(j, 0, 9) {
			nxt[i][j] = nxt[i + 1][j];
		}
		nxt[i][a[i + 1]] = i + 1;
	}
	repn(i, 1, m) dp[i] = 0;
	repn(i, 1, m) {
		int l = sl[i - 1] - '0', r = sr[i - 1] - '0';
		dp[i] = max(dp[i], fm(dp[i - 1], l, r));
	}
	bool can = false;
	if (dp[m] == n + 1) can = true;
	 
	/*
	repn(i, 1, m) repn(j, 0, 2) dp[i][j] = 0;
	repn(i, 1, m) {
		int l = sl[i - 1] - '0', r = sr[i - 1] - '0';
		dp[i][0] = max(dp[i][0], nxt[dp[i - 1][0]][l]);
		dp[i][2] = max(dp[i][2], nxt[dp[i - 1][2]][r]);
		if (i == 1) {
			dp[i][1] = max(dp[i][1], fm(dp[i - 1][1], l + 1, r - 1));
		}
		if (i > 1) {
			dp[i][1] = max(dp[i][1], fm(dp[i - 1][1], 0, 9));
			dp[i][1] = max(dp[i][1], fm(dp[i - 1][0], l + 1, r));
			dp[i][1] = max(dp[i][1], fm(dp[i - 1][2], l, r - 1));
		}
	}
	bool can = false;
	repn(j, 0, 2) {
		if (dp[m][j] == n + 1) can = true;
	}
	*/
	if (can) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	IO;
	int T;
	cin >> T;
	repn(i, 1, T) solve();
	return 0;
}
