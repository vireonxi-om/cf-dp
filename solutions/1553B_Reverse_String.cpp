// Problem: Reverse String
// URL: https://codeforces.com/problemset/problem/1553/B
// Rating: 1300
// Tags: brute force, dp, hashing, implementation, strings
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

string s, t;
int n, m;

bool check(int i){
    int l=min(i, m-i-1);
    bool can=true;
    repn(j, 1, l) {
        if(t[i-j] == t[i+j]) continue;
        can=false; break;
    }
    return can;
}

bool check1(int i){
    bool yes=false;
    rep(j, 0, n){
        if(j+i>=n) break;
        bool can=true;
        repn(k, 0, i) if(s[k+j]!=t[k]) can=false;
        if(can) yes=true;
    }
    return yes;
}

bool check2(int i){
    bool yes=false;
    rep(j, 0, n){
        if(j+m-i-1>=n) break;
        bool can=true;
        repn(k, 0, m-i-1) if(s[k+j]!=t[m-1-k]) can=false;
        if(can) yes=true;
    }
    return yes;
}


void solve() {
    cin >> s >> t;
    n = s.size(), m= t. size();
    bool can=false;
    rep(i, 0, m){
        if(check(i)) {
            if(i+1 >= m-i) {
                if(check1(i)) can=true;
            }
            else{
                if(check2(i)) can=true;
            }
        }
    }
    if(can) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}

