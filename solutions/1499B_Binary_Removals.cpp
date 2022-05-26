// Problem: Binary Removals
// URL: https://codeforces.com/problemset/problem/1499/B
// Rating: 1000
// Tags: brute force, dp, greedy, implementation
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
char s[110];

void solve(){
    scanf("%s", &s);
    n=strlen(s);
    int pos1=-1, pos0=-1;
    for(int i=0; i<n-1; i++){
        if(s[i]=='1' && s[i+1]=='1'){
            pos1=i;
            break;
        }
    }
    for(int i=n-1; i>0; i--){
        if(s[i]=='0' && s[i-1]=='0'){
            pos0=i;
            break;
        }
    }
    bool can=false;
    if(pos0==-1 || pos1==-1) can=true;
    else if(pos1>pos0) can=true;
    if(can) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
