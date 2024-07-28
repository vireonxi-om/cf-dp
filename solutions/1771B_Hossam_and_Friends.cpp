// Problem: Hossam and Friends
// URL: https://codeforces.com/problemset/problem/1771/B
// Rating: 1400
// Tags: binary search, constructive algorithms, dp, two pointers
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
const int M = 11000000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, m, cnt[N];

void solve() {
    cin >> n >> m;
    repn(i, 1, n) cnt[i] = n;
    repn(i, 1, m) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        cnt[a] = min(cnt[a], b - 1);
    }
    long long sum = 0;
    per(i, 1, n) {
        cnt[i] = min(cnt[i], cnt[i + 1]);
        sum += (cnt[i] - i + 1);
    }
    sum += (cnt[n] - n + 1);
    cout << sum << "\n";
}

int main() {
    IO;
    int t;
    cin >> t;
    repn(i, 1, t) solve();
    return 0;
}



