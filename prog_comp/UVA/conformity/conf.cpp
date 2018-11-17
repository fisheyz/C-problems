
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

int main() {
	int n;

	while (cin >> n, n) {
		cin.ignore(1024, '\n');
		map<string, int> log;

		int maxN = -1;
		string x[6];

		for (int i = 0; i < n; i++) {
			string strings;
			// cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4] >> x[5];

			getline (cin, strings);
            istringstream this_line(strings);
            istream_iterator<string> begin(this_line), end;
            vector<string> values(begin, end);

			sort(values.begin(), values.end());

			string code;
			for (auto it: values){
				code += it;
			}
			// for (int j = 0; j < 6; j++) {
			// 	code += x[j];
			// }

			if (!log.count(code)) {
				log[code] = 1;
				maxN = max(maxN, 1);
			} else {
				int m = log[code] + 1;
				log[code] = m;
				maxN = max(maxN, m);
			}
		}

		int count = 0;
		map<string, int>::iterator it;
		for (it = log.begin(); it != log.end(); it++) {
			if (it->second == maxN)
				count += it->second;
		}

		printf("%d\n", count);
	}

	return 0;
}