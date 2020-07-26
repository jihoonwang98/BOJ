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
#define NUM 10000
#define MOD 10007

using namespace std;

typedef long long int ll;

int arr[505][505];
int memo[505][505];

int f(int n, int m) {
	if (memo[n][m] != -1) return memo[n][m];

	if (m == 1) {
		return memo[n][m] = f(n - 1, 1) + arr[n][1];
	}

	if (n == m) {
		return memo[n][m] = f(n - 1, m - 1) + arr[n][m];
	}


	return memo[n][m] = max(f(n - 1, m - 1), f(n - 1, m)) + arr[n][m];
}


int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
			memo[i][j] = -1;
		}
	}

	memo[1][1] = arr[1][1];

	int res = -1;
	for (int i = 1; i <= n; i++) {
		int k = f(n, i);
		if (res < k) res = k;
	}
	cout << res;
}