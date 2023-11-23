// Problem: Priority Queue
// URL: https://codeforces.com/problemset/problem/1542/D
// Rating: 2200
// Tags: combinatorics, dp, implementation, math, ternary search
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[510];
ll dp[510][510];
const ll M=998244353;
string s;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        cin>>s;
        if(s[0]=='-') a[i]=-1;
        else cin>>a[i];
    }
    ll ans=0, sum=0;
    for(int i=1; i<=n; i++){
        if(a[i]==-1) continue;
        for(int t=0; t<=n; t++){
            for(int j=0; j<=n; j++) dp[t][j]=0;
        }
        sum=0;
        dp[0][0]=1;
        for(int t=1; t<=i; t++){
            for(int j=0; j<=n; j++){
                dp[t][j]+=dp[t-1][j];
                dp[t][j]%=M;
                if(t==i) continue;
                if(a[t]==-1){
                    dp[t][max(0, j-1)]+=dp[t-1][j];
                    dp[t][max(0, j-1)]%=M;
                }
                else{
                    if(a[t]>=a[i]){
                        dp[t][j]+=dp[t-1][j]; dp[t][j]%=M;
                    }
                    else{
                        dp[t][j+1]+=dp[t-1][j]; dp[t][j]%=M;
                    }
                }
            }
        }
        for(int t=i+1; t<=n; t++){
            for(int j=0; j<=n; j++){
                dp[t][j]+=dp[t-1][j];
                dp[t][j]%=M;
                if(a[t]==-1){
                    if(j==0) continue;
                    dp[t][j-1]+=dp[t-1][j];
                    dp[t][j-1]%=M;
                }
                else{
                    if(a[t]>a[i]){
                        dp[t][j]+=dp[t-1][j]; dp[t][j]%=M;
                    }
                    else{
                        dp[t][j+1]+=dp[t-1][j]; dp[t][j]%=M;
                    }
                }
            }
        }
        for(int j=0; j<=n; j++){ sum+=dp[n][j]; sum%=M;}
        ans+=sum*a[i]; ans%=M;
    }
    printf("%lld\n", ans);
    return 0;
}
