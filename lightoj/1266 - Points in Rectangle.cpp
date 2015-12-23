#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int tree[1002][1002];


int max_x = 1001, max_y = 1001;

void update(int x , int y , int val){
	int y1;
	while (x <= max_x){
		y1 = y;
		while (y1 <= max_y){
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}
int query(int x, int y){
    int sum = 0;
    int y1;
    while(x > 0){
        y1 = y;
        while(y1 > 0){
            sum += tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return sum;

}

int querypoint(int x, int y){
    return query(x,y) - query(x - 1, y) - query(x, y - 1) + query(x - 1, y - 1);

}

int main()
{
    //freopen("input.txt", "r", stdin);
    int tc, cs = 1, ans;
    int a, x1, x2, y1, y2;
    scanf("%d", &tc);
    while(tc--){
        memset(tree, 0, sizeof(tree));
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", cs++);
        while(q--){
            scanf("%d %d %d", &a, &x1, &y1);
            x1++;y1++;
            if(a == 0){
                if(!querypoint(x1, y1)){
                    update(x1, y1, 1);
                }
            }
            else{
                scanf("%d %d", &x2, &y2);
                x2++;y2++;
                ans = query(x2,y2);
                ans -= query(x1 - 1, y2);
                ans -= query(x2, y1 - 1);
                ans += query(x1 - 1, y1 - 1);
                printf("%d\n", ans);
            }
        }

    }
}

