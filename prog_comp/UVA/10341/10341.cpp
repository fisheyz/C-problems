
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

// #define  eof (!cin.eof())

int p, q, r, s, t, u;


double eq(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double ternarySearch(){

    double l = 0, r = 1;
    int aprox = 100;

    while(aprox--){

        double firstMidP = l + (r - l) / 3;
        double secondMidP = r - (r - l) / 3;
        // printf("First mid point result-> %.4lf\n", eq(firstMidP));
        // printf("Second mid point result-> %.4lf\n", eq(secondMidP));

        if (eq(firstMidP) == 0){
            return firstMidP;
        }

        if (eq(secondMidP) == 0){
            return secondMidP;
        }

        // puts("HERE");
        // printf("WTF -> %.4lf\n", eq(firstMidP) * eq(secondMidP));

        if (eq(firstMidP) * eq(secondMidP) <= 0){

            ( abs(eq(firstMidP)) <= abs(eq(secondMidP)) ) ?
                                                            r = secondMidP :
                                                            l = firstMidP;
        } else {

            ( abs(eq(firstMidP)) >= abs(eq(secondMidP)) ) ?
                                                            l = secondMidP :
                                                            r = firstMidP;

        }

    }
    // printf ("L -> %.4lf\n", l);
    // printf ("R -> %.4lf\n", r);

    return (l+r)/2 ;

}
// [0.....0,21312.....0,43343......0,9999....1]
int main ()
{
    double sol;

    // ios_base::sync_with_stdio(false);

    // while (cin << p << q << r << s << t << u, eof)
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        if(!p && !q && !r && !s && !t && !u) {
            // puts("cenasss");

            continue;
        }
        if (eq(0) * eq(1) > 0) {
            puts("No solution");
         } else {
            printf("%.4lf\n", ternarySearch());
        }
    }
// string k ;
// if (signbit(-1)) k = "signbit(-1)? ";

// cout << k;
    return 0;
}