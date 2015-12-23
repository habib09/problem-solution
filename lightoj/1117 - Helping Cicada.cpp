#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int n, m;
int arr[16];
vector < int > v;
long long ans, s;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


void solve(int pos){
    if(pos >= m){
        if(v.size() > 0){
            s = 1;
            for(int i = 0; i < v.size(); i++){
                s = (s * v[i]) / gcd(s, v[i]);
            }
            if(s > n) return;
            if(v.size() % 2 == 0)
                ans = ans - n / s;
            else
                ans = ans + n / s;
        }
        return;
    }
    v.push_back(arr[pos]);
    solve(pos + 1);
    v.pop_back();
    solve(pos + 1);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int tc , cs = 1;
    scanf("%d", &tc);
    while(tc--){
        ans = 0;
        scanf("%d %d", &n,&m);
        for(int i = 0; i < m; i++)scanf("%d", &arr[i]);
        solve(0);
        printf("Case %d: %lld\n",cs++, n - ans);
        v.clear();
    }
}

