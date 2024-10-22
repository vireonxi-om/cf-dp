// Problem: Building a Fence
// URL: https://codeforces.com/problemset/problem/1469/C
// Rating: 1600
// Tags: dp, greedy, implementation, two pointers
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, k, h[210000];

void solve(){
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) scanf("%d", &h[i]);
    int l=h[1], r=h[1];
    bool can=true;
    for(int i=2; i<=n; i++){
        l=max(h[i], l-k+1);
        r=min(h[i]+k-1, r+k-1);
        if(r<l) can=false;
        if(i==n && h[i]<l) can=false;
    }
    if(can) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}