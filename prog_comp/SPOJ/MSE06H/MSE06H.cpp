// BIT ranged query single update
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
int T, N, M, K;
long long sol;
pair <int, int> bridges[1000005];

bool comp(pair<int, int> p1, pair<int, int> p2){
    if (p1.first == p2.first)
        return (p1.second < p2.second);
    return (p1.first < p2.first);

}

long long read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int m){
    while (idx <= m){
        bit[idx] += 1;
        idx += (idx & -idx);
    }
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
    scanf("%d", &T);
    FOR(t, 0, T){

        scanf("%d %d %d", &N, &M, &K);

        FOR( i, 0, M+1 ){
            bit[i] = 0;
        }

        FOR( i, 0, K){
            scanf("%d %d", &bridges[i].first, &bridges[i].second);
        }

        sort(bridges, bridges+K, comp);

        sol = 0;

        FOR(i, 0, K){
            update(bridges[i].second, M);
            sol += read(M) - read(bridges[i].second);
        }

        printf( "Test case %d: %lld\n", t+1, sol );

    }

    return 0;
}
