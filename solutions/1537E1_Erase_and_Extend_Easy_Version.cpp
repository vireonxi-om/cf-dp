// Problem: Erase and Extend (Easy Version)
// URL: https://codeforces.com/problemset/problem/1537/E1
// Rating: 1600
// Tags: binary search, brute force, dp, greedy, hashing, implementation, string suffix structures, strings, two pointers
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
char ans[5100], cur[5100], s[5100];

bool check(){
    bool yes=false;
    for(int i=0; i<k; i++){
        if(ans[i]>cur[i]){ yes=true; break;}
        else if(ans[i]<cur[i]){yes=false; break;}
    }
    return yes;
}

int main(){
    scanf("%d%d%s", &n, &k, &s);
    for(int j=0; j<k; j++) ans[j]='z';
    ans[k]='\0';
    for(int i=0; i<n; i++){
        if(s[i]>s[0]) break;
        for(int j=0; j<k; j++){
            cur[j]=s[j%(i+1)];
        }
        if(check()){
            for(int j=0; j<k; j++) ans[j]=cur[j];
        }
    }
    printf("%s\n", ans);
}
