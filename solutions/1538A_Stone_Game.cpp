// Problem: Stone Game
// URL: https://codeforces.com/problemset/problem/1538/A
// Rating: 800
// Tags: brute force, dp, greedy
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

void solve(){
    scanf("%d", &n);
    int num, mini=1100, maxi=-1, p1=-1, p2=-1;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        if(num<mini){
            mini=num; p1=i;
        }
        if(num>maxi){
            maxi=num; p2=i;
        }
    }
    int ans=max(p1, p2);
    ans=min(ans, n+1-min(p1, p2));
    ans=min(ans, n-(max(p1, p2)-min(p1, p2)-1));
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
