// Problem: String Equality
// URL: https://codeforces.com/problemset/problem/1451/C
// Rating: 1400
// Tags: dp, greedy, hashing, implementation, strings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
int n, k, cnta[30], cntb[30], numa[30], numb[30];
char a[1100000], b[1100000];

void solve(){
    scanf("%d%d", &n, &k);
    scanf("%s%s", &a, &b);
    memset(cnta, 0, sizeof(cnta));
    memset(cntb, 0, sizeof(cntb));
    for(int i=0; i<n; i++){
        cnta[a[i]-'a'+1]++;
        cntb[b[i]-'a'+1]++;
    }
    bool can=true; int suma=0, sumb=0;
    for(int i=1; i<=26; i++){
        numa[i]=cnta[i]%k; cnta[i]/=k;
        suma+=cnta[i];
        numb[i]=cntb[i]%k; cntb[i]/=k;
        sumb+=cntb[i];
        if(numb[i]!=numa[i]) can=false;
    }
    for(int i=26; i>1; i--){
        suma-=cnta[i]; sumb-=cntb[i];
        if(suma<sumb) can=false;
    }
    if(can) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
