// Problem: Portal
// URL: https://codeforces.com/problemset/problem/1581/C
// Rating: 1700
// Tags: brute force, dp, greedy, implementation
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
const int M = 1100000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int maxn = 100010;

int n, m;
int a[410][410], sum[410][410], b[410][410], c[410][410];


void solve(){
    scanf("%d%d", &n, &m);
    repn(i, 1, n) {
        repn(j, 1, m) {
            scanf("%1d", &a[i][j]);
        }
    }
    repn(i, 1, n) {
        repn(j, 1, m) {
            b[i][j] = b[i][j - 1] + a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    repn(j, 1, m) {
        repn(i, 1, n) {
            c[i][j] = c[i - 1][j] + a[i][j];
        }
    }
    int ans = 16, now;
    repn(i, 1, n) {
        repn(j, 1, m) {
            repn(x, i + 4, n) {
                repn(y, j + 3, m) {
                    now = 0;
                    now += (y - j - 1) - (b[i][y - 1] - b[i][j]);
                    now += (x - i - 1) - (c[x - 1][j] - c[i][j]);
                    now += sum[x - 1][y - 1] - sum[i][y - 1] - sum[x - 1][j] + sum[i][j];
                    if (now > 16) break;
                    now += (y - j - 1) - (b[x][y - 1] - b[x][j]);
                    now += (x - i - 1) - (c[x - 1][y] - c[i][y]);
                    ans = min(ans, now);
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}



