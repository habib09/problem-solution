#include <string.h>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <math.h>


int gcd(int a, int b) {
  if(b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int countDivisor(int n) {
  int divisor = 0;
  for (int i = 1; i * i <= n; i++) {
    if (i * i == n) {
      divisor += 1;
    } else if (n % i == 0) {
      divisor += 2;
    }
  }
  return divisor;
}

int main(){
    //freopen("input.txt", "r", stdin);

    int tc, a, b, g, counter;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d", &a, &b);
        g = gcd(a,b);
        counter = countDivisor(g);

        printf("%d\n",counter);
    }

}
