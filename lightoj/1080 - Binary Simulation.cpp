#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int MaxVal;
int tree[100002];

void update(int idx,int val)
{
    while (idx <= MaxVal)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

int main()
{
   // freopen("input.txt", "r", stdin);
    int tc, cs = 1;
    char str[100002], str2[2];
    scanf("%d", &tc);
    int l1, l2, q;
    //cout << tc<< endl;
    while(tc--)
    {
        printf("Case %d:\n", cs++);
        scanf("%s", str);
        //cout << str << endl;

        MaxVal = strlen(str);
        memset(tree, 0, sizeof(int) * MaxVal + 1 );
        scanf("%d", &q);
        for(int i = 0; i < q; i++)
        {
            scanf("%s",str2);
            if(str2[0] == 'I')
            {
                scanf("%d %d", &l1, &l2);
                update(l1,1);
                update(l2 + 1, -1);
            }
            if(str2[0] == 'Q')
            {
                scanf("%d", &l1);
                int check = read(l1);
                //cout << "update is : "<< check << endl;
                if(check & 1) printf("%c\n", str[l1 - 1] == '0'?'1':'0');
                else
                    printf("%c\n", str[l1 -1]);
            }
        }
    }

    return 0;
}
