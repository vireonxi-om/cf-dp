// Problem: Holiday Wall Ornaments
// URL: https://codeforces.com/problemset/problem/1575/H
// Rating: 2200
// Tags: dp, strings
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

const int N = 510;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

char s[N], t[N];
int dp[2][N][N], nxt[N][2], n, m, fail[N];
void update(int &x, int y) {
	if (y == -1) return;
	if (x == -1) x = y;
	else x = min(x, y);
}
int main()
{
	IO;
	scanf("%d %d", &n, &m);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	repn(i, 1, m) {
		string tmp = "";
		rep(j, 1, i) tmp += t[j];
		string ntmp = tmp + '0';
		nxt[i][0] = 1;
		rep(j, 0, ntmp.size()) {
			int flag = 0, pos;
			rep(k, j, ntmp.size()) {
				if (k - j + 1 >= m) {
					flag = 1;
					break;
				}
				if (t[k - j + 1] != ntmp[k]) flag = 1;
				pos = k - j + 1;
			}
			if (!flag) {
				nxt[i][0] = pos + 1;
				break;
			}
		}
		ntmp = tmp + '1';
		nxt[i][1] = 1;
		rep(j, 0, ntmp.size()) {
			int flag = 0, pos;
			rep(k, j, ntmp.size()) {
				if (k - j + 1 >= m) {
					flag = 1;
					break;
				}
				if (t[k - j + 1] != ntmp[k]) flag = 1;
				pos = k - j + 1;
			}
			if (!flag) {
				nxt[i][1] = pos + 1;
				break;
			}
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0][1] = 0;
	int p = 0;
	repn(i, 1, n) {
		memset(dp[p ^ 1], -1, sizeof(dp[p ^ 1]));
		repn(j, 0, n - m + 1) {
			repn(k, 1, m) {
				if (dp[p][j][k] == -1) continue;
				// 0
				if (t[k] == '0') {
					int cost = dp[p][j][k] + (s[i] != '0');
					if (k == m) update(dp[p ^ 1][j + 1][nxt[k][0]], cost);
					else update(dp[p ^ 1][j][k + 1], cost);
				}
				else {
					int cost = dp[p][j][k] + (s[i] != '0');
					update(dp[p ^ 1][j][nxt[k][0]], cost);
				}
				
				// 1
				if (t[k] == '1') {
					int cost = dp[p][j][k] + (s[i] != '1');
					if (k == m) update(dp[p ^ 1][j + 1][nxt[k][1]], cost);
					else update(dp[p ^ 1][j][k + 1], cost);
				}
				else {
					int cost = dp[p][j][k] + (s[i] != '1');
					update(dp[p ^ 1][j][nxt[k][1]], cost);
				}
			}
		}
		p ^= 1;
	}
	repn(i, 0, n - m + 1) {
		int ans = -1;
		repn(j, 1, m) update(ans, dp[p][i][j]);
		cout << ans;
		if (i != n - m + 1) cout << " ";
		else cout << "\n";
	}
	return 0;
}