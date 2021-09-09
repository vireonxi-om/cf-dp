// Problem: I Hate 1111
// URL: https://codeforces.com/problemset/problem/1526/B
// Rating: 1400
// Tags: dp, math, number theory
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

void solve(){
    scanf("%d", &n);
    bool can=false;
    for(int i=0; i<=110; i++){
        if(n<i*11) break;
        if((n-i*11)%111==0){
            can=true;
            break;
        }
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


