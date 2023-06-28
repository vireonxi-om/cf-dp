// Problem: Backspace
// URL: https://codeforces.com/problemset/problem/1553/D
// Rating: 1500
// Tags: dp, greedy, strings, two pointers
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

const int N = 110000;
const int M = 650;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;

int n, m, a[5];
char s[N], t[N];

void solve() {
    scanf("%s%s", s + 1, t + 1);
    n = strlen(s + 1); m = strlen(t + 1);
    bool can = false;
    int st = 0, now = 1;
    if (m % 2 == n % 2) st = 1;
    repn(i, 1, n) {
        if (i % 2 == st && s[i] == t[now]) {
            now ++; st = 1 - st;
        }
        if (now > m) {
            can = true;
            break;
        }
    }
    if (can) printf("yes\n");
    else printf("no\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}

