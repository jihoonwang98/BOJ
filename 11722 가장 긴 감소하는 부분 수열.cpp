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

int arr[1005];
int dp[1005];

void fill(int n) {

	int flag = 0;
	int max = -1;
	for (int i = 1; i <= n - 1; i++) {
		if (arr[i] > arr[n]) {
			flag = 1;
			if (max < dp[i]) max = dp[i];
		}
	}

	if (!flag) dp[n] = 1;
	else {
		dp[n] = max + 1;
	}
}


int main() {
	int N;
	cin >> N;
	for (int i = 1;i <= N; i++) cin >> arr[i];
	dp[1] = 1;

	for (int i = 2; i <= N; i++) fill(i);

	int max = -1;
	for (int i = 1; i <= N; i++) {
		if (dp[i] > max) max = dp[i];
	}

	cout << max;
}