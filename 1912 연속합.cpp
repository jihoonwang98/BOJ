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

using namespace std;
const int INF = (unsigned)(-1) >> 1;

int N;
int dp[NUM + 5];
int arr[NUM + 5];

int f(int n) {
	if (dp[n] != INF) return dp[n];
	return dp[n] = max(f(n - 1) + arr[n], arr[n]);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = INF;
	}

	f(N);
	int res = -100000009;
	for (int i = 1; i <= N; i++) {
		if (res < dp[i]) res = dp[i];
	}

	cout << res;
}