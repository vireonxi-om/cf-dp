// Problem: Particles
// URL: https://codeforces.com/problemset/problem/1844/C
// Rating: 1300
// Tags: dp, greedy, implementation, math
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
template<typename T> void down(T &x, T y) { if (x > y) x = y; }

const int N = 110000;
const int M = 610000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-15;
const double pi = acos(-1.0);

int n;
void solve() {
	cin >> n;
	LL num, a1 = 0, a2 = 0, num1 = -1e9, num2 = -1e9;
	repn(i, 1, n) {
		cin >> num;
		if (num > 0) {
			if (i % 2) a1 += num;
			else a2 += num;
		}
		else {
			if (i % 2) num1 = max(num1, num);
			else num2 = max(num2, num);
		}
	}
	if (a1 == 0 && a2 == 0) {
		cout << max(num1, num2) << "\n";
	}
	else cout << max(a1, a2) << "\n";
}

int main() {
	IO;
	int T;
	cin >> T;
	repn(i, 1, T) solve();
	return 0;
	
}