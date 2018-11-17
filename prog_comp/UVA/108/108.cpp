
#include <stdio.h>
#include <algorithm>
// #include <iostream>
// #include <string>
// #include <vector>
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
// #include <string.h>
// #include <stdlib.h>
// #include <assert.h>
// #include <fstream>
using namespace std;

// #define  eof (!cin.eof())
#define FOR(i, a, b) for(int i=(a);i<(b);i++)

int N;
int input[105][105];
int sum[105][105];
int currSum[105];

void findSolution()
{

    int sol = -5000;

    FOR(i, 0, N)
    {
        FOR(j, i, N)
        {
            currSum[0] = 0;
            FOR(k, 0, N)
            {
                currSum[k+1]=max(sum[k][j+1]-sum[k][i]+currSum[k],
                                 sum[k][j+1]-sum[k][i]);

                sol=max(sol,currSum[k+1]);
            }
        }
    }
    printf("%d\n", sol);
}

int main ()
{
    while(scanf("%d", &N) == 1){

        FOR(i, 0, N){
            FOR(j,0, N){
            scanf("%d", &input[i][j]);
            }
        }

        FOR(i, 0, N){
            sum[i][0] = 0;
            FOR(j,1,N+1){
                sum[i][j] = sum[i][j-1]+
                            input[i][j-1];
            }
        }

    findSolution();
    }
    return 0;
}