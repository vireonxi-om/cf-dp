// Problem: Hamiltonian Wall
// URL: https://codeforces.com/problemset/problem/1766/C
// Rating: 1300
// Tags: dp, implementation
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
const int M = 5100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;


int a[2][N];
int n;
int vis[2][N];
bool check(int i, int j) {
    if (j < 1 || j > n) return false;
    if (!a[i][j]) return false;
    return true;
}
bool check_vis(){ 
    repn(i, 0, 1) {
        repn(j, 1, n) {
            if (a[i][j] && vis[i][j] == 0) return false;
        }
    }
    return true;
}

void solve() {
    string s;
    cin >> n;
    rep(j, 0, 2){
        cin >> s;
        repn(i, 1, n){
            if (s[i - 1] == 'W') a[j][i] = 0;
            else a[j][i] = 1;
        } 
    }
    repn(j, 0, 1) {
        repn(i, 1, n) vis[j][i] = 0;
    }
    bool ans = false;
    PII st = mp(-1, -1);
    repn(i, 1, n) {
        repn(j, 0, 1) {
            if (a[j][i]){
                st = mp(j, i); break;
            } 
        }
        if (st.fi >= 0) break;
    }
    //cout << "s\n";
    while (1) {
        //cout << "r\n";
        repn(j, 0, 1) {
            repn(i, 1, n) vis[j][i] = 0;
        }
        PII now = st;
        while(1) {
            //cout << now.fi << " " << now.se << "\n";
            vis[now.fi][now.se] = 1;
            if (a[1 - now.fi][now.se] && vis[1 - now.fi][now.se] == 0) now = mp(1 - now.fi, now.se);
            else {
                if (check(now.fi, now.se + 1)) now = mp(now.fi, now.se + 1);
                else break;
            }
        }
        if (check_vis()) ans = true;
        if (st.fi == 0 && a[1][st.se]) st = mp(1, st.se);
        else break;
    }
    if (ans) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    IO;
    int t;
    cin >> t;
    repn(i, 1, t) solve();
    return 0;
}



