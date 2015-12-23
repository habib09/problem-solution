#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int dp[10003];
int a, b, c, d, e, f;
int fn( int n ) {
    if( n == 0 ) return dp[0];
    if( n == 1 ) return dp[1];
    if( n == 2 ) return dp[2];
    if( n == 3 ) return dp[3];
    if( n == 4 ) return dp[4];
    if( n == 5 ) return dp[5];
    if( dp[n]!=-1) return dp[n];
    else{
        return dp[n]=( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) )%10000007;
        //return dp[n];
    }
}
int main() {
   // freopen("input.txt","r",stdin);
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        memset(dp,-1,sizeof dp);
        dp[0]=a%10000007;
        dp[1]=b%10000007;
        dp[2]=c%10000007;
        dp[3]=d%10000007;
        dp[4]=e%10000007;
        dp[5]=f%10000007;
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
