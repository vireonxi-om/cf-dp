// Problem: Nezzar and Lucky Number
// URL: https://codeforces.com/problemset/problem/1478/B
// Rating: 1100
// Tags: brute force, dp, greedy, math
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int q, d, a[11000];

void solve(){
    scanf("%d%d", &q, &d);
    for(int i=1; i<=q; i++) scanf("%d", &a[i]);
    for(int i=1; i<=q; i++){
        int num=a[i];
        bool can=false;
        while(num){
            int t=num%10;
            if(t==d) can=true;
            num/=10;
        }
        if(can){ printf("YES\n"); continue;}
        int num1=a[i]%10, maxi=0;
        for(int j=1; j<=9; j++){
            if((d*j)%10==num1){
                maxi=d*j;
                break;
            }
        }
        if(maxi==0){
            if(num1<d && num1>0) maxi=(d+1)*10+num1;
            else maxi=d*10+num1;
        }
        if(maxi>a[i]) printf("NO\n");
        else printf("YES\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}