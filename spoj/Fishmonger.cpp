#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <sstream>
#define  MAX_N 52
#define  INF 100000000

using namespace std;

typedef pair < int, int> ii;

vector <ii> topsort;

ii dp[MAX_N][1000];
int travel_time[MAX_N][MAX_N];
int travel_cost[MAX_N][MAX_N];

int n, t;

ii solve(int u, int t){

    if(t < 0) return ii(INF,INF);
    if(u == n - 1) return ii(0,0);
    if(dp[u][t] != ii(-1,-1)) return dp[u][t];

    ii ans = ii(INF,INF);
    for(int v = 0; v < n; v++){
        if(v != u){
            ii nextcity = solve(v, t - travel_time[u][v]);
            if(nextcity.first + travel_cost[u][v] < ans.first){
                ans.first = nextcity.first + travel_cost[u][v];
                ans.second = nextcity.second + travel_time[u][v];
            }
        }
    }
    //topsort.push_back(ii(u,t));
    return dp[u][t] = ans;
}

int main(){
   // freopen("input.txt","r",stdin);
    int a;
    while(scanf("%d %d", &n, &t) == 2 && n && t){
        //stringstream ss;
        //memset(dp, -1, sizeof dp);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= t; j++)
                dp[i][j] = ii(-1,-1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &a);
                travel_time[i][j] = a;
                //travel_time[j][i] = a;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &a);
                travel_cost[i][j] = a;
                //travel_cost[j][i] = a;
            }
        }
//        for(int i = 0; i < n; i++){
//            for(int j = 0; j < n; j++){
//                cout << travel_cost[i][j] << " ";
//            }
//            cout << endl;
//        }
        ii ans = solve(0,t);
        //cout << topsort.size() << endl;
        //for(int i = 0; i < topsort.size(); i++)
          //  cout << topsort[i].first << " " << topsort[i].second << endl;

        cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}
