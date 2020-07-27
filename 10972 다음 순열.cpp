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
#define NUM 10000
#define MOD 1000000009
const int INF = (unsigned)(-1) >> 1;

using namespace std;

int N;
int arr[NUM];
int nextArr[NUM];

int nextP() {
	int decIdx = -1;
	int remain[NUM];
	int remainidx = 0;

	for (int i = N - 1; i >= 1; i--) {
		if (arr[i] < arr[i + 1]) {
			decIdx = i;
			break;
		}
	}

	if (decIdx == -1) return -1;

	for (int i = N; i >= decIdx; i--) {
		remain[remainidx++] = arr[i];
	}

	sort(remain, remain + remainidx);

	int x = 0;
	for (int i = 0; i < remainidx; i++) {
		if (arr[decIdx] < remain[i]) {
			x = remain[i];
			break;
		}
	}

	for (int i = 1; i <= decIdx - 1; i++) nextArr[i] = arr[i];
	nextArr[decIdx] = x;

	int idx = decIdx + 1;
	for (int i = 0; i < remainidx; i++) {
		if (x != remain[i]) {
			nextArr[idx++] = remain[i];
		}
	}

	return 0;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	if (nextP()) {
		cout << -1;
		return 0;
	}

	else {
		for (int i = 1; i <= N; i++) cout << nextArr[i] << ' ';
	}
}