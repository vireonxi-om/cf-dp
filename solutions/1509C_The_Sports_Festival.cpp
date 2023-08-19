// Problem: The Sports Festival
// URL: https://codeforces.com/problemset/problem/1509/C
// Rating: 1800
// Tags: dp, greedy
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[2100], dp[2100][2100];
ll ans=0;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){ scanf("%lld", &a[i]); dp[i][i]=0;}
    sort(a+1, a+n+1);
    for(int l=2; l<=n; l++){
        for(int i=1; i<=n-l+1; i++){
            dp[i][i+l-1]=a[i+l-1]-a[i]+min(dp[i][i+l-2], dp[i+1][i+l-1]);
        }
    }
    printf("%lld\n", dp[1][n]);
    return 0;
}

