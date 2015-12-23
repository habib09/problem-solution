#include <iostream>
#include <cstdio>
#define  mx 100001

using namespace std;

typedef unsigned long long i64;

int arr[mx];

struct info{
    i64 prop,sum;
}tree[mx*3];



void update(int node,int b,int e,int i,int j,i64 x){

    if (i > e || j < b)   return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e-b+1)*x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = ((e - b) >> 1) + b;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}


i64 query(int node,int b,int e,int i,int j,i64 carry=0){
    if (i > e || j < b)       return 0;

    if(b >= i and e <= j) return tree[node].sum+carry * (e - b + 1);


    int Left = node << 1;
    int Right = Left + 1;
    int mid = ((e - b) >> 1) + b;

    i64 p1 = query(Left, b, mid,  i, j,   carry + tree[node].prop);
    i64 p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return  p1 + p2;

}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, tc, c, k, p, q, v;
    scanf("%d", &tc);
    while(tc--){
        for(int i = 1; i <= 3 * mx; i++)
            tree[i].prop = tree[i].sum = 0;
        cin >> n >> c;
        for(int i = 0; i < c; i++){
            cin >> k >> p >> q;

            //cout << "k = " << k << endl;
            if(k == 0){
                cin >> v;
                update(1, 1, n, p, q, v);
            }
            else{

                printf("%llu\n",query(1, 1, n, p, q, 0));
            }

        }

//        for(int i = 1; i <= 3 * n; i++)
//                cout << tree[i].prop << " " <<  tree[i].sum << " ";
//                cout << endl;

    }
    return 0;
}
