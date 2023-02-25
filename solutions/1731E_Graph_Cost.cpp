// Problem: Graph Cost
// URL: https://codeforces.com/problemset/problem/1731/E
// Rating: 2000
// Tags: dp, greedy, math, number theory
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

const int N = 1100000;
const int M = 110000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n;
long long m, dp[N]; 

void solve() {
	cin >> n >> m;
	long long ans = m;
	pern(i, 2, n) {
		long long t = n / i;
		dp[i] = t * (t - 1) / 2;
		repn(j, 2, t) dp[i] -= dp[i * j];
	}
	repn(i, 2, n) dp[i] /= (i - 1);
	pern(i, 2, n) {
		if (m >= i - 1 && dp[i]){
			long long num = m / (i - 1);
			num = min(num, dp[i]);
			ans += num;
			m -= num * (i - 1);
		} 
	}
	if (m == 0) cout << ans << "\n";
	else cout << "-1\n";
}



int main() {
    IO;
    int t;
    cin >> t;
    repn(i, 1, t) solve();
    return 0;
}




