
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
long long budget = 0;
long k = 0;
long long expenses(long long mid, long long items[])
{

    long long r = 0;
    long long items_copy[k];

    for (long long i = 0; i < k; i++){
        items_copy[i] = items[i]+(i+1)*mid;
    }

    sort(items_copy, items_copy+k);

    for (long long i = 0 ; i < mid ; i++){
        r += items_copy[i];
        if (r > budget){
            return r;
        }
    }
    return r;
}

int main ()
{

    ios_base::sync_with_stdio(false);


    cin >> k >> budget;
    long long items[k];

    for (long long i = 0; i < k; i++){
            cin >> items[i];
    }

    long long l = 0, r = k;
    long solution = 0;

    while(l < r) {
        long long mid = l + (r - l) / 2;
        if (expenses(mid, items) > budget) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    solution = l;

    //acho que o meu binary sort nao esta bem implementado porque nao sei como evitar este if statement
    if (expenses(solution, items) > budget ){
        solution--;
    }

    cout << solution << " " << expenses(solution, items) << endl;
    return 0;
}