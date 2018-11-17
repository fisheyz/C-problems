
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

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define ll long long

using namespace std;
int t;
ll a, b, k, sol;


int parity(long long val){
    return ((val%2) == 0 ? 1 : 0);
}

long long read(ll bit[], int idx){
    int sum = 0;
    while (idx > 0){
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}


void update(ll bit[], int idx, int m){
    while (idx <= k){
        bit[idx] += m;
        idx += (idx & -idx);
    }
}

int main ()
{

    // scanf("%d", &t);
    // while(t--){
        scanf("%lld %lld %lld", &a, &b, &k);
        int val = 0;

        ll bit[k+50];
        // ll alist[k+50];

            FOR(i, 0, k+1){
                bit[i] = 0;
            }

            // FOR(i, 0, k){
            //     (parity(i)) == 1 ?  val = a : val = b*(-1);
            //     alist[i] = val;
            // }


            FOR(i, 0, k){
                (parity(i)) == 1 ?  val = a : val = b*(-1);
                update(bit, i+1, val);
                // printf("%d|%d\n", i+1, val);
            }

            sol = read(bit, k);
            printf("SOLUTION %lld\n", sol);
    // }

    return 0;
}