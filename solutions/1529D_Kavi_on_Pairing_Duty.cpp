// Problem: Kavi on Pairing Duty
// URL: https://codeforces.com/problemset/problem/1529/D
// Rating: 1700
// Tags: combinatorics, dp, math, number theory
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=998244353;
const int MAX=1100000;
int n, mind[MAX];
ll ans[MAX], sum[MAX];
vector<int> primes;


int main(){
    for(int i=2; i<=MAX; i++){
        if(mind[i] == 0){
            primes.emplace_back(i);
            mind[i]=i;
        }
        for(auto x: primes){
            if(x>mind[i] || x*i>MAX) break;
            mind[x*i]=x;
        }
    }

    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        ans[i]+=sum[i-1];
        int cnt=0, last=0, x=i, tot=1;
        while(x>1){
            int p=mind[x];
            if(last==p) cnt++;
            else{
                tot*=(cnt+1);
                last=p; cnt=1;
            }
            x/=p;
        }
        tot*=(cnt+1);
        ans[i]+=tot;
        ans[i]%=M;
        sum[i]=sum[i-1]+ans[i];
        sum[i]%=M;
    }
    printf("%lld\n", ans[n]);
    return 0;
}
