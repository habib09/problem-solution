#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX_N 1000001

using namespace std;

char P[MAX_N];
char T[MAX_N];
int b[MAX_N], m;

void Failure()
{
    int i = 0, j = -1;
    b[0] = -1;
    while(i < m)
    {
        while(j >= 0 && P[i] != P[j])
            j = b[j];
        i++;
        j++;
        b[i] = j;
    }
}

int KmpProcess()
{
    int i = 0, j = 0;
    while(i < m)
    {
        while(j >= 0 && P[j] != T[i])
            j = b[j];
        i++;
        j++;
    }
    return j;
}

int main()
{
    int j,i,cs = 0,tc;
    char c[2];
    //freopen("input.txt","r",stdin);
    scanf("%d",&tc);
    gets(c);
    while(tc--)
    {

        m = (int)strlen(gets(T));
        //cout << c << endl;
        j = 0;
        for(i = m - 1; i >= 0; i--,j++)
            P[j] = T[i];


        //cout << P << endl <<  R << endl;
        P[m] = '\0';
        Failure();
        j = KmpProcess();
        printf("Case %d: %d\n",++cs, m + m - j);
    }
    return 0;
}
