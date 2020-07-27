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
#include <cmath>
#define NUM 1000
#define MOD 1000000009
const int INF = (unsigned)(-1) >> 1;

using namespace std;

int N;

int jaritsu(int n) {
	int tmp = n;
	int ret = 0;
	while (tmp) {
		tmp /= 10;
		ret++;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int j = jaritsu(N);

	int res = 0;
	for (int i = 1; i <= j - 1; i++) {
		res += 9 * (int)pow(10, i - 1) * i;
	}

	res += (N - (int)pow(10, j - 1) + 1) * j;

	cout << res;
}