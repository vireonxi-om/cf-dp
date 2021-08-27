// Problem: Napoleon Cake
// URL: https://codeforces.com/problemset/problem/1501/B
// Rating: 900
// Tags: dp, implementation, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, ans[210000];

void solve(){
    for(int i=0; i<=n; i++) ans[i]=0;
    scanf("%d", &n);
    int num;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        int t=min(i, num);
        ans[i-t+1]=max(ans[i-t+1], t);
    }
    int now=0;
    for(int i=1; i<=n; i++){
        int t=max(now, ans[i]);
        if(t){ ans[i]=1; t--;}
        else ans[i]=0;
        now=t;
    }
    for(int i=1; i<=n; i++) printf("%d ", ans[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
