// Problem: Ice and Fire
// URL: https://codeforces.com/problemset/problem/1774/C
// Rating: 1300
// Tags: constructive algorithms, dp, greedy
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
const int M = 110000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    int m1, m2;
    if (s[0] == '1') {
        m1 = 2;
        m2 = 2;
    }
    else {
        m1 = 1;
        m2 = 1;
    }
    cout << 1 << " ";
    rep(i, 1, n - 1) {
        int t = s[i] - '0';
        int cur = i + 2;
        int ans;
        if (t == 1) {
            ans = cur - m1;
            m1 ++;
            m2 = cur;
        }
        else {
            ans = m2;
            m1 = 1;
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    IO;
    int t;
    cin >> t;
    repn(i, 1, t) solve();
    return 0;
}



// maintenance note (5): add complexity note to this file — 2026-08-30
