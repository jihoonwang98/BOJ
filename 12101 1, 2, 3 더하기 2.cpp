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
#define NUM 1000000
#define MOD 1000000000
const int INF = (unsigned)(-1) >> 1;

using namespace std;

int N, K;

int memo[12][4];
vector<int> res;

int f(int n, int k) {
	if (memo[n][k] != -1) return memo[n][k];
	return memo[n][k] = f(n - k, 1) + f(n - k, 2) + f(n - k, 3);
}


void func(int n, int k) {
	if (n == 0) return;
	int s[4];
	for (int i = 1; i < 4; i++) s[i] = f(n, i);
	for (int i = 2; i <= 3; i++) s[i] = s[i] + s[i - 1];

	int i = 1;
	for (; s[i] < k; i++);
	res.push_back(i);

	if (i == 2) {
		k -= s[1];
	}

	else if (i == 3) {
		k -= s[2];
	}

	if (k > 0) func(n - i, k);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 4; j++) {
			memo[i][j] = -1;
		}
	}

	memo[1][1] = 1;
	memo[1][2] = memo[1][3] = 0;
	memo[2][1] = 1;
	memo[2][2] = 1;
	memo[2][3] = 0;
	memo[3][1] = 2;
	memo[3][2] = 1;
	memo[3][3] = 1;

	for (int i = 3; i < 12; i++) {
		for (int j = 1; j < 4; j++) {
			f(i, j);
		}
	}

	int f_N = f(N, 1) + f(N, 2) + f(N, 3);
	if (K > f_N) {
		cout << -1;
		return 0;
	}

	func(N, K);

	int len = res.size();
	for (int i = 0; i < len; i++) {
		if (i != len - 1) {
			cout << res[i] << '+';
		}
		else {
			cout << res[i];
		}
	}
}