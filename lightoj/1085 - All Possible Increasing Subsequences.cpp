#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int MaxVal;
int tree[100002];
int arr[100002];
int const mod = 1000000007;

struct data{
    int value;
    int id;
}st[100002];

void update(int idx,long long val)
{
    while (idx <= MaxVal)
    {
        tree[idx] = (tree[idx] + val) % mod;
        idx += (idx & -idx);
    }
}

int read(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum = (sum + tree[idx]) % mod;
        idx -= (idx & -idx);
    }
    return sum;
}

void build_bit(int idx){
    int pre = read(idx - 1);
    update(idx, pre + 1);
}

bool cmp(data a, data b){
    if(a.value != b.value)
        return a.value < b.value;
    return a.id > b.id;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int tc,q, cs = 1, s, ans;
    scanf("%d", &tc);
    while(tc--)
    {
        memset(tree, 0, sizeof(tree));
        scanf("%d", &s);
        for(int i = 0; i < s; i++){
                scanf("%d",&arr[i]);
                st[i].value = arr[i];
                st[i].id = i + 1;
        }
        //for(int i = 0; i < s; i++)narr[i] = arr[i];
        sort(st,st + s, cmp);
        //for(int i = 0; i < s; i++)cout << st[i].id << "(" << st[i].value << ") " ;cout << endl;
        MaxVal = s;
        //build_bit(st[0].id);
        for(int i = 0; i < s; i++){
                build_bit(st[i].id);
        }
        ans = read(s);
        printf("Case %d: %d\n", cs++, ans);
    }
    return 0;
}
