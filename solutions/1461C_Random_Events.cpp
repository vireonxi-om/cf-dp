// Problem: Random Events
// URL: https://codeforces.com/problemset/problem/1461/C
// Rating: 1500
// Tags: dp, math, probabilities
// Language: C++14 (GCC 6-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[110000];

void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    int k;
    for(k=n; k>0; k--) if(a[k]!=k) break;
    k++;
    int r; double p, result=0;
    for(int i=1; i<=m; i++){
        scanf("%d%lf", &r, &p);
        if(r>=(k-1)){
            if(result==0) result=p;
            else result=result+(1-result)*p;
        }
    }
    if(k==1) printf("1.000000\n");
    else printf("%.6f\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
