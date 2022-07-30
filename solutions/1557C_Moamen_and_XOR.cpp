// Problem: Moamen and XOR
// URL: https://codeforces.com/problemset/problem/1557/C
// Rating: 1700
// Tags: bitmasks, combinatorics, dp, math, matrices
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
const int M = 32;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAX = 100100;

int n, k;
LL a, b, a1, b1;

LL quick_pow(LL x,LL n,LL m){
    LL res = 1;
    while(n > 0) {
        if(n & 1) res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

void solve() {
    scanf("%d%d", &n, &k);
    if (k == 0) printf("1\n");
    else {
        LL num1 = quick_pow(2, n - 1, mod);
        LL num2 = quick_pow(2, n, mod);
        LL ans;
        if (n % 2){
            ans = num1;
            ans ++; ans %= mod;
            ans = quick_pow(ans, k, mod);
        }
        else {
            a = 1, b = 0;
            repn(i, 1, k) {
                a1 = a * (num1 - 1);
                a1 %= mod;
                b1 = (b * num2 % mod) + a;
                b1 %= mod;
                a = a1; b = b1;
            }
            ans = a + b; ans %= mod;
        }
        printf("%lld\n", ans);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}