// Problem: Replace and Keep Sorted
// URL: https://codeforces.com/problemset/problem/1485/B
// Rating: 1200
// Tags: dp, implementation, math
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, q, k, a[110000];
ll b[110000];

int main(){
    scanf("%d%d%d", &n, &q, &k);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=2; i<n; i++) b[i]=a[i+1]-a[i-1]-2;
    for(int i=3; i<n; i++) b[i]+=b[i-1];
    int l, r;
    while(q--){
        ll now=0;
        scanf("%d%d", &l, &r);
        if(l!=r){
            now+=b[r-1]-b[l];
            now+=k-a[r-1]-1;
            now+=a[l+1]-2;
        }
        else{
            now=k-1;
        }
        printf("%lld\n", now);
    }
}
