// Problem: Unstable String
// URL: https://codeforces.com/problemset/problem/1535/C
// Rating: 1400
// Tags: binary search, dp, greedy, implementation, strings, two pointers
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char s[210000];

void solve(){
    scanf("%s", s+1);
    n=strlen(s+1);
    int st=1, l, m;
    int zero, one;
    ll ans=0;
    while(st<=n){
        int cnt=0;
        while(st>1 && s[st-1]=='?'){ st--; cnt++;}
        l=st;
        zero=-1; one=-1;
        while(l<=n){
            if(s[l]=='0'){
                if((zero==-1 || zero==l%2) && one!=l%2) zero=l%2;
                else break;
            }
            if(s[l]=='1'){
                if((one==-1 || one==l%2) && zero!=l%2) one=l%2;
                else break;
            }
            l++;
        }
        ans+=((ll)l-st)*(l-st+1)/2;
        if(cnt) ans-=(ll)cnt*(cnt+1)/2;
        st=l;
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}


