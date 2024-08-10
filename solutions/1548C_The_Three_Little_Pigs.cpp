// Problem: The Three Little Pigs
// URL: https://codeforces.com/problemset/problem/1548/C
// Rating: 2500
// Tags: combinatorics, dp, fft, math
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

const int N = 3100000;
const int M = 32;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;

int n, q;
LL c[N], b[10], ans[N];
LL f[N], inv[N], ff[N];


LL quick_pow(LL x,LL n,LL m){
    LL res = 1;
    while(n > 0) {
        if(n & 1) res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

int main(){
    f[0] = 1;
    for (int i = 1; i < N; i ++)
        f[i] = (f[i-1] * i) % mod;
    ff[1] = ff[0] = inv[1] = inv[0] = 1;
    for (int i = 2; i < N; i ++) {
        inv[i] = (LL)(mod - mod / i) * inv[mod % i] % mod;
        ff[i] = inv[i];
    }
    for (int i = 2; i < N; i ++)
        inv[i] = (inv[i - 1] * inv[i]) % mod;

    scanf("%d%d", &n, &q);
    repn(i, 0, 3 * n + 3) {
        c[i] = (f[3 * n + 3] * inv[i]) % mod;
        c[i] *= inv[3 * n + 3 - i];
        c[i] %= mod;
    }
    b[3] = 1; b[2] = 3;
    b[1] = 3; b[0] = 1;
    repn(i, 0, 3) c[i] = (c[i] - b[i] + mod) % mod;
    b[0] = 0;
    pern(i, 3, 3 * n + 3) {
        LL coef = c[i];
        ans[i - 3] = coef;
        repn(j, 0, 3) {
            c[i - j] = (c[i - j] - (b[3 - j] * coef % mod) + mod) % mod;
        }
    }
    int x;
    while (q --) {
        scanf("%d", &x);
        printf("%lld\n", ans[x]);
    }
    return 0;
}
