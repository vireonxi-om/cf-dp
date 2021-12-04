// Problem: Maximum And Queries (hard version)
// URL: https://codeforces.com/problemset/problem/1903/D2
// Rating: 2500
// Tags: bitmasks, divide and conquer, dp, greedy
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

const int N = 1100000;
const int M = (int)(1<<20);
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, q, a[N];
int cnt[M];
LL b[M][20];

int main() {
	IO;
	cin >> n >> q;
	LL sum = 0;
	repn(i, 1, n) {
		cin >> a[i];
		sum += a[i];
		cnt[a[i]] ++;
		rep(j, 0, 20) {
			if (!(a[i] & (1 << j))) {
				b[a[i]][j] += (a[i] % (1 << j));
			}
		}
	} 
	rep(i, 0, 20) rep(mask, 0, M) {
		if (!(mask & (1 << i))) {
			cnt[mask] += cnt[mask ^ (1 << i)];
			rep(j, 0, 20) b[mask][j] += b[mask ^ (1 << i)][j]; 
		}
	}
	LL num, tot = (1 << 20) * n;
	repn(j, 1, q) {
		cin >> num;
		if (num + sum >= n * (1LL << 20)) {
			cout << (num + sum) / n << "\n";
			continue;
		}
		int msk = 0;
		per(i, 0, 20) {
			int msk_nxt = msk ^ (1 << i);
			LL cst = (n - cnt[msk_nxt]) * (1LL << i) - b[msk][i];
			if (cst > num) continue;
			num -= cst;
			msk ^= (1 << i);
		}
		cout << msk << "\n";
	}
	return 0;
}