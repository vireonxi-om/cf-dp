// Problem: Tiling Terrace
// URL: https://codeforces.com/problemset/problem/1252/J
// Rating: 2300
// Tags: brute force, dp
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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 110000;
const int M = 510000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-15;

int n, k, g1, g2, g3;
char s[N];
int dp[N][55][2];

int main() {
    scanf("%d%d%d%d%d", &n, &k, &g1, &g2, &g3);
    scanf("%s", s + 1);
    int cnt = 0;
    repn(i, 1, n) if (s[i] == '#') cnt ++;
    repn(i, 0, n) repn(t, 0, 50) {dp[i][t][0] = -1; dp[i][t][1] = -1;}
    dp[0][0][0] = 0;
    repn(i, 1, n) {
        repn(t, 0, 50) {
            dp[i][t][0] = max(dp[i][t][0], max(dp[i - 1][t][0], dp[i - 1][t][1]));
            if (s[i] == '.') {
                if (i >= 2 && s[i - 1] == '.') {
                    if (max(dp[i - 2][t][0], dp[i - 2][t][1]) > -1) {
                        dp[i][t][1] = max(dp[i][t][1], max(dp[i - 2][t][0], dp[i - 2][t][1]) + 1);
                    }
                }
                if (i >= 3 && t >= 1 && s[i - 1] == '#' && s[i - 2] == '.') {
                    if (max(dp[i - 3][t - 1][0], dp[i - 3][t - 1][1]) > -1) {
                        dp[i][t][1] = max(dp[i][t][1], max(dp[i - 3][t - 1][0], dp[i - 3][t - 1][1]));
                    }
                }
            }
        }
    }
    int ans = 0;
    repn(t, 0, 50){
        int t2 = max(dp[n][t][0], dp[n][t][1]);
        if (t2 == -1) continue;
        int now, t1;
        repn(i, 0, t2) {
            t1 = n - cnt - t * 2 - i * 2;
            t1 = min(k, t1);
            now = g3 * t + g2 * i + g1 * t1;
            //printf("%d %d %d %d\n", t1, i, t, now);
            ans = max(ans, now);
        }
    }
    printf("%d\n", ans);
    return 0;
}