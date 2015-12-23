#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int MaxVal;
//int tree[100002];
long long tree[100002];
long long tree2[100002];

void update(int idx,long long val)
{
    while (idx <= MaxVal)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

long long read(int idx)
{
    long long sum = 0;
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update2(int idx,long long val)
{
    while (idx <= MaxVal)
    {
        tree2[idx] += val;
        idx += (idx & -idx);
    }
}

long long read2(int idx)
{
    long long sum = 0;
    while (idx > 0)
    {
        sum += tree2[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

long long query(int idx){
    long long ans = read(idx) * idx;
    ans -= read2(idx);
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int tc,q, cs = 1, c;
    long long ans;
    scanf("%d",&tc);
    long long v, l1, l2;
    //cout << tc<< endl;
    while(tc--)
    {
        //cout << " bL";

        scanf("%d %d",&MaxVal, &c);
        //cout << MaxVal << q << endl;
       // MaxVal++;
        memset(tree, 0, sizeof(tree));
        memset(tree2, 0, sizeof(tree2));
        printf("Case %d:\n", cs++);
        for(int i = 0; i < c; i++)
        {
            scanf("%d %lld %lld", &q, &l1, &l2);
            //for(int i = 1; i < MaxVal; i++)
            //cout << tree[i] << endl;
            //cout << endl << endl;
            l1++;l2++;
            if(q == 0){
                scanf("%lld", &v);
                update(l1,v);
                update(l2 + 1, -v);
                update2(l1, v*(l1 - 1));
                update2(l2 + 1, -(v*l2));
            }
            else{
                ans = query(l2);
                ans -= query(l1 - 1);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}

