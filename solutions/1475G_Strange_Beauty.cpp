// Problem: Strange Beauty
// URL: https://codeforces.com/problemset/problem/1475/G
// Rating: 1900
// Tags: dp, math, number theory, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[210000], dp[210000];


void solve(){
    scanf("%d", &n);
    for(int i=1; i<210000; i++) dp[i]=0;
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    for(int i=1; i<=n; i++){
        int len=0;
        for(int j=1; j<=sqrt(a[i]); j++){
            if(a[i]%j==0){
                len=max(len, max(dp[j], dp[a[i]/j]));
            }
        }
        dp[a[i]]=len+1;
    }
    int result=0;
    for(int i=1; i<210000; i++){
        result=max(result, dp[i]);
    }
    result=n-result;
    printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
