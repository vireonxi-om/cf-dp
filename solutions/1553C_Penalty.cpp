// Problem: Penalty
// URL: https://codeforces.com/problemset/problem/1553/C
// Rating: 1200
// Tags: bitmasks, brute force, dp, greedy
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

int n, m;
char s[20], temp[20];

int cal(){
    int suma=0, sumb=0;
    repn(i, 1, 10){
        if(temp[i]=='1'){
            if(i%2) suma++;
            else sumb++;
        }
        if(i%2){
            if(suma+(10-i)/2<sumb) return i;
            else if(suma>sumb+(10-i)/2+1) return i;
        }
        else{
            if(suma+(10-i)/2<sumb) return i;
            else if(suma>sumb+(10-i)/2) return i;
        }
    }
    return 10;
}

void solve() {
    scanf("%s", s+1);
    repn(i, 1, 10){
        temp[i]=s[i];
        if(s[i]=='?'){
            if(i%2) temp[i]='1';
            else temp[i]='0';
        }
    }
    int ans=cal();
    repn(i, 1, 10){
        temp[i]=s[i];
        if(s[i]=='?'){
            if(i%2) temp[i]='0';
            else temp[i]='1';
        }
    }
    ans=min(ans, cal());
    printf("%d\n", ans);
}

int main() {
    IO;
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}

