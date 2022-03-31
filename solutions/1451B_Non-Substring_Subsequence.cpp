// Problem: Non-Substring Subsequence
// URL: https://codeforces.com/problemset/problem/1451/B
// Rating: 900
// Tags: dp, greedy, implementation, strings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, q, l, r, a[110];

void solve(){
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; i++){
        scanf("%1d", &a[i]);
    }
    for(int i=1; i<=q; i++){
        scanf("%d%d", &l, &r);
        bool can=false;
        for(int j=1; j<l; j++){
            if(a[j]==a[l]) can=true;
        }
        for(int j=n; j>r; j--){
            if(a[j]==a[r]) can=true;
        }
        if(can) printf("YES\n");
        else printf("NO\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
