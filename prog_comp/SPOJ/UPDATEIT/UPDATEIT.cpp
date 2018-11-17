// #include <iostream>
// #include <string>
// #include <vector>
#include <algorithm>
// #include <sstream>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <iterator>
// #include <list>
// #include <stack>
// #include <map>
// #include <set>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <limits>
// #include <time.h>
// #include <math.h>
#include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <assert.h>

using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)

long long bit[10002];
int t, n, u, l, r, val, q;
long long sol;

long long read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val){
    while (idx <= n){
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

void range_update(int l, int r, int v)	{
	update(l, v);
	update(r + 1, -v);
}

// void myDebug(int m){
// 	printf("******BEGIN*****\n");
// 	for(int i = 1; i<=m; i++){
// 		// printf("BIT: %lld\n", bit[i]);
// 	}
// 	printf("******END*****\n");
// }

int main ()
{
    // ios_base::sync_with_stdio(false);
    scanf("%d", &t);

    while( t-- ){

        scanf("%d %d", &n, &u);

        FOR(i, 0, n+1){
            bit[i] = 0;
        }

        // Updates
        while( u-- ){
            scanf("%d %d %d", &l, &r, &val);
            range_update(l+1,r+1,val);
        }

        // Queries
        scanf("%d", &q);

        sol = 0;
        while( q-- ){
            scanf("%d", &val);
            sol = read(val+1);

            printf("%lld\n", sol);
        }
    }

    return 0;
}
