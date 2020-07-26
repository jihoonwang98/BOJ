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

int N;
int arr[NUM + 5][3];
int memo[NUM + 5][3];

int f(int n, int m) {
	if (memo[n][m]) return memo[n][m];

	if (m == 0) {
		return memo[n][m] = min(f(n - 1, 1), f(n - 1, 2)) + arr[n][m];
	}

	else if (m == 1) {
		return memo[n][m] = min(f(n - 1, 0), f(n - 1, 2)) + arr[n][m];
	}

	else if (m == 2) {
		return memo[n][m] = min(f(n - 1, 0), f(n - 1, 1)) + arr[n][m];
	}
}



int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	for (int j = 0; j < 3; j++) memo[1][j] = arr[1][j];

	int res = 1000001;
	for (int j = 0; j < 3; j++) {
		int k = f(N, j);
		if (res > k) res = k;
	}
	cout << res;

}