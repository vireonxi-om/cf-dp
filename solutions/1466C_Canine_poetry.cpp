// Problem: Canine poetry
// URL: https://codeforces.com/problemset/problem/1466/C
// Rating: 1300
// Tags: dp, greedy, strings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
char s[110000];

void solve(){
    set<int> a[30];
    scanf("%s", s+1);
    int n=strlen(s+1);
    for(int i=1; i<=n; i++){
        a[s[i]-'a'].insert(i);
    }
    int result=0;
    for(int i=0; i<26; i++){
        if(a[i].empty()) continue;
        auto it=a[i].begin();
        while(it!=a[i].end()){
            int pos=(*it); a[i].erase(pos);
            it=a[i].begin();
            if(it!=a[i].end()&&(*it)==pos+1){a[i].erase(pos+1); result++;}
            it=a[i].begin();
            if(it!=a[i].end()&&(*it)==pos+2){a[i].erase(pos+2); result++;}
            it=a[i].begin();
        }
    }
    printf("%d\n", result);

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}