
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
#include <cctype>
#include <cstdio>

using namespace std;

#define MAX_BUF 16  // Buffer for reading type of operation
#define MAX 1000100 // Size of array holding segment tree

// #define  eof (!cin.eof())


int v[MAX];  // Array of values
int st[MAX]; // Segment tree (in this case storing sum of intervals)
int N, K;

void myDebug(){
  printf("DEBUG\n");
  for (int i = 1; i <= N ; i++){
    printf("%d \n", v[i]);
  }
  printf("DEBUG\n");
}

int reduce(int a){
  if (a == 0) return 0;
  return a < 0 ? -1 : 1;
}

int merge(int a, int b) {
  return a*b;
}

// Build initial segment tree (in position node, interval [start,end])
void build(int node, int start, int end) {
  // cout << "node->" << node << "start->" << start << "end->" << end << endl;
  if (start==end) {
    st[node] = v[start];
    // cout << st[node];
  } else {
    int m = start+(end-start)/2;                 // middle point
    build(node*2, start, m);                     // build left side
    build(node*2+1, m+1, end);                   // build right side
    st[node] = merge(st[node*2], st[node*2+1]);  // merge to create current node
  }
  // printf("%d [%d,%d] = %d\n", node, start, end, st[node]);
}

// Make a query of interval [x,y]

int query(int node, int start, int end, int x, int y) {

  // Interval does not intersect, return "neutral element"
  if (start>y || end<x) return 1;

  // Interval contained in [x,y], return stored result
  if (start>=x && end<=y) return st[node];

    // Query both sides and merge results
  int m = start+(end-start)/2;
  int a = query(node*2, start, m, x, y);
  int b = query(node*2+1, m+1, end, x, y);
  // printf("query::: %d [%d,%d] = %d\n", node, start, end, st[node]);
  return merge(a, b);
}

// Update node x with value val
void update(int node, int start, int end, int x, int val) {
  // printf("node: %d, start: %d, end: %d, x: %d, y: %d \n", node, start, end, x, val);
  if (x<start || x>end) return;
  if (start == end && start == x) {
    st[node] = val;
    // printf("update::: %d [%d,%d] = %d\n", node, start, end, st[node]);
  } else {
    int m = start+(end-start)/2;
    update(node*2, start, m, x, val);
    update(node*2+1, m+1, end, x, val);
    st[node] = merge(st[node*2], st[node*2+1]);
    //  printf("update::: %d [%d,%d] = %d\n", node, start, end, st[node]);
  }

}


int main ()
{

  // ios_base::sync_with_stdio(false);
  while(scanf("%d %d", &N, &K) == 2){
    int x, y;
    char com[2];

    for (int i = 1; i <= N; i++){
      scanf("%d", &y);
      v[i] = reduce(y);
    }

    build(1, 1, N);

    while (K--){
      scanf("%s %d %d", com, &x, &y);

      // printf("Com: %s|\n", com);
      // printf("x: %d|\n", x);
      // printf("y: %d|\n", y);
      if (com[0] == 'C') {
        update(1, 1, N, x, reduce(y));

      } else {
        int sol = query(1, 1, N, x, y);
        // printf("X:%d\n",x);
        // printf("X: %d", x);
        if (sol == 0)
          printf("0");
         else if (sol < 0)
          printf("-");
         else
          printf("+");
      }
    }
    puts("");
  }
  return 0;
}