// Problem: Grime Zoo
// URL: https://codeforces.com/problemset/problem/1465/D
// Rating: 2100
// Tags: dp, greedy, implementation, math, ternary search
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y, result=0;
int pre[110000], suf[110000];
char s[110000];
vector<int> p;
vector<int>::iterator it;

int main(){
    scanf("%s%lld%lld", s+1, &x, &y);
    int n=strlen(s+1);
    pre[0]=0; suf[n+1]=0;
    for(int i=1; i<=n; i++){
        pre[i]=pre[i-1];
        if(s[i]=='?') p.push_back(i);
        if(s[i]=='0' || s[i]=='?') pre[i]++;
    }
    for(int i=n; i>=1; i--) {
        suf[i] = suf[i + 1];
        if (s[i] == '0' || s[i] == '?') suf[i]++;
    }
    for(int i=1; i<=n; i++) {
        if (s[i] == '0' || s[i] == '?') result += y * (i - 1 - pre[i - 1]);
        else result += x * pre[i - 1];
    }
    int cnt=0; ll r1=result, r2=result;
    for(int i=1; i<=n; i++){
        if(s[i]=='?'){
            r1 += y*(suf[i+1]-(i-1-pre[i-1]+cnt))+x*((pre[i-1]-cnt)-(n-i-suf[i+1]));
            cnt++;
            result=min(result, r1);
        }
    }
    cnt=0;
    for(int i=n; i>=1; i--){
        if(s[i]=='?'){
            r2 += y*(suf[i+1]-cnt-(i-1-pre[i-1]))+x*(pre[i-1]-(n-i-suf[i+1]+cnt));
            cnt++;
            result=min(result, r2);
        }
    }
    printf("%lld\n", result);
    return 0;
}