
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
#include <fstream>
using namespace std;

// #define  eof (!cin.eof())

int n;

int main ()
{
    ofstream myfile;
    myfile.open ("example.txt");
    while(cin >> n, n)
    {
        myfile << n;
    }
    myfile.close();
    return 0;
}