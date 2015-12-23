#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <sstream>

#define MAX_N 100001

using namespace std;

//int dp[MAX_N][MAX_N];
int arr[MAX_N], a;
int tree[3*MAX_N];

void init(int node, int b, int e){
    if(b == e){
        tree[node] = arr[b];
        return;
    }
    int mid = (b + e) >> 1;
    int left = node << 1;
    int right = left + 1;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j){
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[node];

    //if(dp[i][j] != -1) return dp[i][j];

    int mid = (b + e) >> 1;
    int left = node << 1;
    int right = left + 1;
    return query(left, b, mid, i, j) + query(right, mid + 1, e, i, j);
}

void update(int node,int b, int e, int i, int value){
    //cout << node << endl;
    if(i < b || i > e) return;
    if(b >= i && e <= i){
        //if(a == 1) printf("%d\n", tree[node]);
        tree[node] += value;
        arr[i] += value;
        return;
    }

    int mid = (b + e) >> 1;
    int left = node << 1;
    int right = left + 1;
    update(left, b, mid, i, value);
    update(right, mid + 1, e, i, value);
    tree[node] = tree[left] + tree[right];
}
int main()
{
   // freopen("input.txt", "r", stdin);
    int tc, n, q, r1, r2, cs = 0;
    scanf("%d", &tc);
    string str;
    stringstream ss;
    while(tc--){
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        init(1, 0, n - 1);

        //cout << "printing tree .....\n";
        //for(int i = 1; i < 10; i++)cout << tree[i] << endl;
        //cout << "tree printed\n";

        //getline(cin, str);
        //memset(dp, -1, sizeof dp);
        printf("Case %d:\n", ++cs);
        for(int i = 0; i < q; i++){
            //getline(cin, str);
            //ss.clear();
            //ss << str;
            //ss >> a;
            //ss >> r1;
            scanf("%d ", &a);
            if(a == 1){
                scanf("%d", &r1);
                printf("%d\n", arr[r1]);
                int v = (-1) * arr[r1];
                //cout << v << endl;
                update(1, 0, n - 1, r1, v);
            }
            else if(a == 2){
                //ss >> r2;
                scanf("%d %d", &r1, &r2);
                update(1, 0, n - 1, r1, r2);
            }
            else{
                //ss >> r2;
                scanf("%d %d", &r1, &r2);
          //      for(int i = 1; i < 10; i++)cout << tree[i] << endl;
                printf("%d\n", query(1, 0, n - 1, r1, r2));
            }
            //cout << a << r1 << r2 << endl;
        //cout << "printing tree .....\n";
        //for(int i = 1; i < 10; i++)cout << tree[i] << endl;
        //cout << "tree printed\n";
        }

    }
    return 0;
}
