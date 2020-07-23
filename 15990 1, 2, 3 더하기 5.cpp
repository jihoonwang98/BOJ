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
#define NUM 100000
#define MOD 1000000009

using namespace std;
typedef long long int ll;

ll memo[NUM + 5][4];

ll f(int n, int l) {
	if (memo[n][l] != -1) return memo[n][l];

	if (l == 1) {
		return memo[n][l] = (f(n - 1, 2) % MOD + f(n - 1, 3) % MOD) % MOD;
	}

	else if (l == 2) {
		return memo[n][l] = (f(n - 2, 1) % MOD + f(n - 2, 3) % MOD) % MOD;
	}

	else if (l == 3) {
		return memo[n][l] = (f(n - 3, 1) % MOD + f(n - 3, 2) % MOD) % MOD;
	}

}


int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= NUM; i++) {
		for (int j = 1; j <= 3; j++) {
			memo[i][j] = -1;
		}
	}

	memo[1][1] = 1;
	memo[1][2] = 0;
	memo[1][3] = 0;
	memo[2][1] = 0;
	memo[2][2] = 1;
	memo[2][3] = 0;
	memo[3][1] = 1;
	memo[3][2] = 1;
	memo[3][3] = 1;

	for (int i = 1; i <= T; i++) {
		int n;
		cin >> n;
		cout << (f(n, 1) % MOD + f(n, 2) % MOD + f(n, 3) % MOD) % MOD << '\n';

	}
}