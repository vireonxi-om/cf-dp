// Problem: Interesting Function
// URL: https://codeforces.com/problemset/problem/1538/F
// Rating: 1500
// Tags: binary search, dp, math, number theory
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;

void solve(){
    scanf("%lld%lld", &a, &b);
    ll num=1, l, r, tot=0;
    for(int i=1; i<=10; i++){
        if(a<num) l=num;
        else{
            l=(a/num)*num+num;
        }
        if(b<num) break;
        else r=(b/num)*num;
        tot+=((r-l)/num+1);
        num*=10;
    }
    printf("%lld\n", tot);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
// maintenance note (6): add editorial link comment to this file — 2026-09-01
