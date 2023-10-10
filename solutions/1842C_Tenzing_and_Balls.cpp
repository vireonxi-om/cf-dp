// Problem: Tenzing and Balls
// URL: https://codeforces.com/problemset/problem/1842/C
// Rating: 1500
// Tags: dp
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC ch[k][0] 
#define RC ch[k][1]
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
const int M = 610000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n, c[N], m[N];
int dp[N];

void solve() {
	cin >> n;
	repn(i, 1, n){
		m[i] = -1; dp[i] = i;
		cin >> c[i]; 
	}
	repn(i, 1, n) {
		dp[i] = min(dp[i], dp[i - 1] + 1);
		if (m[c[i]] != -1) dp[i] = min(dp[i], m[c[i]]);
		if (m[c[i]] == -1) m[c[i]] = dp[i - 1];
		else m[c[i]] = min(m[c[i]], dp[i - 1]);
	}
	cout << n - dp[n] << "\n";
}

int main()
{
	IO;
	int T;
	cin >> T;
	repn(i, 1, T) solve(); 
	return 0;
}
