// Problem: Mocha and Red and Blue
// URL: https://codeforces.com/problemset/problem/1559/B
// Rating: 900
// Tags: dp, greedy
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
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int MAXN = 1001000;

int n;
char a[110];

void solve() {
    scanf("%d%s", &n, a + 1);
    int id = 0;
    char l;
    repn(i, 1, n) {
        if (!id) {
            if (a[i] == '?') continue;
            else{
                id = i;
                l = a[i];
            }
        }
        else if (a[i] != '?') l = a[i];
        else {
            if (l == 'R') a[i] = 'B';
            else a[i] = 'R';
            l = a[i];
        }
    }
    if (id == 0) {
        repn(i, 1, n){
            if (i == 1) a[i] = 'R';
            else if (a[i - 1] == 'R') a[i] = 'B';
            else a[i] = 'R';
        }
    }
    else {
        pern(i, 1, id - 1) {
            if (a[i + 1] == 'R') a[i] = 'B';
            else a[i] = 'R';
        }
    }
    printf("%s\n", a + 1);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t --) solve();
    return 0;
}

