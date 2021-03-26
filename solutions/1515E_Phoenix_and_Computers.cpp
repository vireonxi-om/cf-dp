// Problem: Phoenix and Computers
// URL: https://codeforces.com/problemset/problem/1515/E
// Rating: 2200
// Tags: combinatorics, dp, math
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll M, ans[410][410], tp[410], fac[410], inv[410];

ll power(ll a, ll b){
    if(b==0) return 1;
    ll temp=power(a, b/2);
    temp=(temp*temp)%M;
    if(b%2) temp*=a;
    return (temp%M);
}

void pre(){
    tp[0]=1;
    for(int i=1; i<=n; i++){ tp[i]=tp[i-1]*2; tp[i]%=M;}
    fac[0]=1; inv[0]=1;
    for(int i=1; i<=n; i++){
        fac[i]=(fac[i-1]*i)%M;
        inv[i]=power(fac[i], M-2);
    }
}

int main(){
    scanf("%d%lld", &n, &M);
    pre();
    for(int i=1; i<=n; i++) ans[i][i]=tp[i-1];
    for(int i=1; i<n-1; i++){
        for(int j=1; j<=i; j++){
            for(int k=1; k<=n-i-1; k++){
                ans[i+1+k][j+k]+=((ans[i][j]*tp[k-1])%M)*((((fac[j+k]*inv[j])%M)*inv[k])%M);
                ans[i+1+k][j+k]%=M;
            }
        }
    }
    ll result=0;
    for(int i=0; i<=n; i++){ result+=ans[n][i]; result%=M;}
    printf("%lld\n", result);
    return 0;
}

