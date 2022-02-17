// Problem: Move and Turn
// URL: https://codeforces.com/problemset/problem/1459/B
// Rating: 1300
// Tags: dp, math
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
    scanf("%d", &n);
    int k=n/2, result;
    if(n&1) result=2*(k+1)*(k+2);
    else result=(k+1)*(k+1);
    printf("%d\n", result);
    return 0;
}
