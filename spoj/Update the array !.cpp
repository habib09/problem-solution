#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int MaxVal;
//int tree[100002];
int tree[10002];

void update(int idx,int val)
{
    while (idx <= MaxVal)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int read(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int tc,v, cs = 1;
    scanf("%d",&tc);
    int l1, l2, q;
    //cout << tc<< endl;
    while(tc--)
    {

        scanf("%d %d",&MaxVal,&q);
        //cout << MaxVal << q << endl;
        memset(tree, 0, sizeof(tree));
        for(int i = 0; i < q; i++)
        {

                scanf("%d %d %d", &l1, &l2, &v);
                l1++;l2++;
                update(l1,v);
                update(l2 + 1, -v);

        }
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%d", &v);
            v++;
            printf("%d\n", read(v));
        }
    }

    return 0;
}
