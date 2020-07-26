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

using namespace std;

typedef long long int ll;

int memo[NUM + 5][NUM + 5];

// n을 1, 2, 3 k 개의 합으로 나타내는 방법의 수 
int f(int n, int k) {
	if (memo[n][k] != -1) return memo[n][k];
	if (n < k) return memo[n][k] = 0;
	if (n == k) return memo[n][k] = 1;
	if (n > 3 && k == 1) return memo[n][k] = 0;

	int res = 0;
	for (int i = 1; i <= 3; i++) {
		res = (res % MOD + f(n - i, k - 1) % MOD) % MOD;
	}

	return memo[n][k] = res;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i <= NUM;i++) {
		for (int j = 0; j <= NUM; j++) {
			memo[i][j] = -1;
		}
	}

	memo[1][1] = memo[2][1] = memo[3][1] = 1;


	while (T--) {
		int n, m;
		cin >> n >> m;

		int res = 0;
		for (int i = 1; i <= m; i++) {
			res = (res % MOD + f(n, i) % MOD) % MOD;
		}
		cout << res << '\n';
	}
}