
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
int k = 0, n = 0, c = 0;

bool place_cows(int mid, int stalls[]){
    int cows = 1, pos = stalls[0];
    for (int i = 1; i < n; i++){
        if ( stalls[i]-pos >= mid ){
            pos = stalls[i];
            // cout << pos;
            cows++;
            if (cows == c){
                return true;
            }
        }
    }
    return false;
}

int main ()
{

    ios_base::sync_with_stdio(false);
    cin >> k;
    while (k--){
        cin >> n >> c;
        int stalls[n];
        for (int i = 0; i < n ; i++){
            cin >> stalls[i];
        }

        int l = 0, r = stalls[n-1];
        int solution = -1;

        sort(stalls,stalls+n);

        while (l < r){
            int mid = (l + r) / 2;
            // cout << "mid-"<<mid << endl;
            if ( place_cows(mid, stalls) ){
                if ( mid > solution ){
                    solution = mid;
                }
                l = mid +1;
            } else {
                r = mid;
            }

        }

        cout <<solution << endl;
    }

    return 0;
}