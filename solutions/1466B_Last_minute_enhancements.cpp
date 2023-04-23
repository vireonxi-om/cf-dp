// Problem: Last minute enhancements
// URL: https://codeforces.com/problemset/problem/1466/B
// Rating: 800
// Tags: dp, greedy
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, cnt[210000], yes[210000];

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=2*n+10; i++){ cnt[i]=0; yes[i]=0;}
    for(int i=1; i<=n; i++){
        int num;
        scanf("%d", &num);
        cnt[num]++;
    }
    int result=0;
    for(int i=1; i<=2*n+10; i++){
        if(cnt[i]>0 || yes[i]==1) result++;
        if(cnt[i]>1 || cnt[i]==1 && yes[i]==1) yes[i+1]=1;
    }
    printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}