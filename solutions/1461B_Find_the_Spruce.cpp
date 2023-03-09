// Problem: Find the Spruce
// URL: https://codeforces.com/problemset/problem/1461/B
// Rating: 1400
// Tags: brute force, dp, implementation
// Language: C++14 (GCC 6-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, b[600][600];
char a[600][600];

void solve(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) scanf("%s", &a[i]);
    int result=0;
    for(int i=0; i<m; i++){
        if(a[n-1][i]=='*') b[n-1][i]=1;
        else b[n-1][i]=0;
    }
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<m; j++){
            if(a[i][j]=='*'){
                b[i][j]=1;
                if(j>0 && j<m-1){
                    int k=min(b[i+1][j], b[i+1][j+1]);
                    k=min(k, b[i+1][j-1]);
                    b[i][j]+=k;
                }
            }
            else b[i][j]=0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            result+=b[i][j];
        }
    }
    printf("%d\n", result);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
