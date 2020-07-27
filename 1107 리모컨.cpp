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

int N, M;
int gojang[10];


int isAvailable(int n) {
	string tmp = to_string(n);
	int len = tmp.size();

	int flag = 0;
	for (int i = 0; i < len; i++) {
		if (gojang[tmp[i] - '0']) {
			flag = 1;
		}
	}

	return !flag;
}

int jaritsu(int n) {
	if (n == 0) return 1;
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

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int n;
		cin >> n;
		gojang[n] = 1;
	}

	int upper = INF;
	for (int i = N; i <= 1000000; i++) {
		if (isAvailable(i)) {
			upper = i;
			break;
		}
	}

	int lower = INF;
	for (int i = N; i >= 0; i--) {
		if (isAvailable(i)) {
			lower = i;
			break;
		}
	}

	int res[3];
	res[0] = abs(N - 100);
	res[1] = (upper != INF) ? jaritsu(upper) + abs(N - upper) : INF;
	res[2] = (lower != INF) ? jaritsu(lower) + abs(N - lower) : INF;


	int res_min = INF;
	for (int i = 0; i < 3; i++) {
		if (res_min > res[i]) res_min = res[i];
	}
	cout << res_min;
}