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

int arr[NUM + 5][3];
int dp0[NUM + 5][3];
int dp1[NUM + 5][3];
int dp2[NUM + 5][3];

int f0(int n, int m) {
	if (dp0[n][m]) return dp0[n][m];

	if (m == 0) {
		return dp0[n][m] = min(f0(n - 1, 1), f0(n - 1, 2)) + arr[n][m];
	}

	else if (m == 1) {
		return dp0[n][m] = min(f0(n - 1, 0), f0(n - 1, 2)) + arr[n][m];
	}

	else if (m == 2) {
		return dp0[n][m] = min(f0(n - 1, 0), f0(n - 1, 1)) + arr[n][m];
	}
}

int f1(int n, int m) {
	if (dp1[n][m]) return dp1[n][m];

	if (m == 0) {
		return dp1[n][m] = min(f1(n - 1, 1), f1(n - 1, 2)) + arr[n][m];
	}

	else if (m == 1) {
		return dp1[n][m] = min(f1(n - 1, 0), f1(n - 1, 2)) + arr[n][m];
	}

	else if (m == 2) {
		return dp1[n][m] = min(f1(n - 1, 0), f1(n - 1, 1)) + arr[n][m];
	}
}


int f2(int n, int m) {
	if (dp2[n][m]) return dp2[n][m];

	if (m == 0) {
		return dp2[n][m] = min(f2(n - 1, 1), f2(n - 1, 2)) + arr[n][m];
	}

	else if (m == 1) {
		return dp2[n][m] = min(f2(n - 1, 0), f2(n - 1, 2)) + arr[n][m];
	}

	else if (m == 2) {
		return dp2[n][m] = min(f2(n - 1, 0), f2(n - 1, 1)) + arr[n][m];
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	dp0[1][0] = arr[1][0];
	dp0[1][1] = dp0[1][2] = INF;
	dp0[2][0] = INF;
	dp0[2][1] = arr[1][0] + arr[2][1];
	dp0[2][2] = arr[1][0] + arr[2][2];

	dp1[1][0] = dp1[1][2] = INF;
	dp1[1][1] = arr[1][1];
	dp1[2][0] = arr[1][1] + arr[2][0];
	dp1[2][2] = arr[1][1] + arr[2][2];
	dp1[2][1] = INF;

	dp2[1][0] = dp2[1][1] = INF;
	dp2[1][2] = arr[1][2];
	dp2[2][0] = arr[1][2] + arr[2][0];
	dp2[2][1] = arr[1][2] + arr[2][1];
	dp2[2][2] = INF;


	int tmp[6];
	tmp[0] = f0(N, 1);
	tmp[1] = f0(N, 2);
	tmp[2] = f1(N, 0);
	tmp[3] = f1(N, 2);
	tmp[4] = f2(N, 0);
	tmp[5] = f2(N, 1);

	int res = INF;
	for (int i = 0; i < 6; i++) {
		if (res > tmp[i]) res = tmp[i];
	}
	cout << res;
}