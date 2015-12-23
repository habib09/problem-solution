#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define mx 100001
#define INF 1 << 30
int arr[mx];
int tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int Left = node << 1;
    int Right = Left + 1;
    int mid = (b + e) >> 1;
    init(Left, b, mid);
    init(Right, mid+1, e);
    tree[node]= min(tree[Left], tree[Right]);
}
int query(int node,int b,int e,int i,int j)
{
    if (i > e || j < b)   return INF;
    if (b >= i && e <= j) return tree[node];
    int Left = node << 1;
    int Right = Left + 1;
    int mid = (b + e) >> 1;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid+1, e, i, j);
    return min(p1, p2);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int tc, cs = 0;
    int n, q, r1, r2;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        init(1,1,n);
        //update(1,1,n,2,0);
        //for(int i = 1; i <= 9; i++)cout << tree[i] << endl;
        printf("Case %d:\n", ++cs);
        for(int i = 0; i < q; i++){
            scanf("%d %d", &r1, &r2);
            printf("%d\n",query(1, 1, n, r1, r2));
        }
    }
    return 0;
}
