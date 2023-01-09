// Problem: Education
// URL: https://codeforces.com/problemset/problem/1512/F
// Rating: 1900
// Tags: brute force, dp, greedy, implementation
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll c, a[210000], b[210000];
const ll M=1000000007;
vector<pair<ll, int>> t;

void solve(){
    t.clear();
    scanf("%d%lld", &n, &c);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    for(int i=1; i<n; i++) scanf("%lld", &b[i]);
    ll mx=0, sum=0, cnt=0;
    for(int i=1; i<=n; i++){
        if(a[i]>mx){
            mx=a[i];
            t.push_back(make_pair(sum, cnt));
            t.push_back(make_pair(a[i], -1));
            sum=0; cnt=0;
        }
        sum+=b[i]; cnt++;
    }
    ll now=0, step=0, ans=c;
    int tot=t.size();
    for(int i=0; i<tot; i++){
        auto x=t[i];
        if(x.second>=0){
            now-=x.first;
            step+=x.second;
        }
        else{
            if(now>=c) ans=min(ans, step);
            else ans=min(ans, step+(c-now+x.first-1)/x.first);
            while(i!=tot-1 && now<t[i+1].first){
                now+=x.first;
                step++;
            }
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
