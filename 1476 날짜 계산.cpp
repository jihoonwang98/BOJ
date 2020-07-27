#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <algorithm>
#define NUM 1000
#define MOD 1000000009
const int INF = (unsigned)(-1) >> 1;

using namespace std;


int N;
int res = 0;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int e, s, m;
	cin >> e >> s >> m;

	int x = 1;
	while (1) {
		if (((x - 1) % 15 + 1 == e) && ((x - 1) % 28 + 1 == s) && ((x - 1) % 19 + 1 == m)) {
			cout << x;
			break;
		}
		x++;
	}


}