// Problem: Love Song
// URL: https://codeforces.com/problemset/problem/1539/B
// Rating: 800
// Tags: dp, implementation, strings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q, a[30][110000];
char s[110000];

int main(){
    scanf("%d%d%s", &n, &q, s+1);
    for(int i=1; i<=n; i++){
        for(int j=0; j<26; j++){
            a[j][i]=a[j][i-1];
            if(s[i]-'a'==j) a[j][i]++;
        }
    }
    int l, r;
    while(q--){
        scanf("%d%d", &l, &r);
        int ans=r-l+1;
        for(int j=0; j<26; j++){
            ans+=j*(a[j][r]-a[j][l-1]);
        }
        printf("%d\n", ans);
    }
}

