// Problem: Red and Blue
// URL: https://codeforces.com/problemset/problem/1469/B
// Rating: 1000
// Tags: dp, greedy
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, r[110], b[110];

void solve(){
    r[0]=0; b[0]=0;
    int maxr=0, maxb=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &r[i]);
        r[i]+=r[i-1];
        maxr=max(maxr, r[i]);
    }
    scanf("%d", &m);
    for(int i=1; i<=m; i++){
        scanf("%d", &b[i]);
        b[i]+=b[i-1];
        maxb=max(maxb, b[i]);
    }
    int ans=maxr+maxb;
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}

