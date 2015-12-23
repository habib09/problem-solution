#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define MAX_N 1000005


char T[MAX_N],P[MAX_N];
int b[MAX_N],n,m;

void KmpProcess(){
    int i = 0, j = -1;
    b[0] = -1;
    while(i < m){
        while(j >= 0 && P[i] != P[j]) j = b[j];

        i++;j++;
        b[i] = j;
    }
}

int KMP(){
    int ans = 0;
    int i = 0, j = 0;
    while(i < n){
        while(j >= 0 && T[i] != P[j]) j = b[j];

        i++;j++;
        if(j == m){
            ans++;
            j = b[j];
        }
    }
    return ans;
}

int main()
{
   // freopen("input.txt","r",stdin);
    int tc, cs = 0;
    char c[2];
    scanf("%d",&tc);
    gets(c);
    while(tc--){
        n = (int)strlen(gets(T));
        m = (int)strlen(gets(P));
        KmpProcess();
        printf("Case %d: %d\n",++cs,KMP());
    }
    return 0;
}
