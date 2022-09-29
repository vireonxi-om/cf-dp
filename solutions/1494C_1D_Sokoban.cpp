// Problem: 1D Sokoban
// URL: https://codeforces.com/problemset/problem/1494/C
// Rating: 1900
// Tags: binary search, dp, greedy, implementation, two pointers
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, cnt1[210000], cnt2[210000];
vector<int> a1, a2, b1, b2;
 
void solve(){
    scanf("%d%d", &n, &m);
    a1.clear(); a2.clear(); b1.clear(); b2.clear();
    for(int i=0; i<210000; i++){cnt1[i]=0; cnt2[i]=0;}
    int num;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        if(num>0) a1.push_back(num);
        else a2.push_back(-num);
    }
    for(int i=1; i<=m; i++){
        scanf("%d", &num);
        if(num>0) b1.push_back(num);
        else b2.push_back(-num);
    }
    sort(a2.begin(), a2.end());
    sort(b2.begin(), b2.end());
    int ans1=0, ans2=0, n1=a1.size(), n2=a2.size();
    for(int i=n1-1; i>=0; i--){
        auto p=lower_bound(b1.begin(), b1.end(), a1[i]);
        if(p!=b1.end() && (*p)==a1[i]) cnt1[i]=cnt1[i+1]+1;
        else cnt1[i]=cnt1[i+1];
    }
    for(int i=n2-1; i>=0; i--){
        auto p=lower_bound(b2.begin(), b2.end(), a2[i]);
        if(p!=b2.end() && (*p)==a2[i]) cnt2[i]=cnt2[i+1]+1;
        else cnt2[i]=cnt2[i+1];
    }
    if(!a1.empty()){
        auto it=lower_bound(b1.begin(), b1.end(), a1[0]);
    for(int i=0; i<n1; i++){
        while(it!=b1.end() && (i+1==n1 || i+1<n1 && (*it)<a1[i+1])){
            auto now=lower_bound(b1.begin(), b1.end(), (*it)-i);
            ans1=max(ans1, (int)distance(now, it)+1+cnt1[i+1]);
            it++;
        }
    }
    }
    if(!a2.empty()){
        auto it=lower_bound(b2.begin(), b2.end(), a2[0]);
    for(int i=0; i<n2; i++){
        while(it!=b2.end() && (i+1==n2 || i+1<n2 && (*it)<a2[i+1])){
            auto now=lower_bound(b2.begin(), b2.end(), (*it)-i);
            ans2=max(ans2, (int)distance(now, it)+1+cnt2[i+1]);
            it++;
        }
    }
    }
    
    printf("%d\n", ans1+ans2);
}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
 