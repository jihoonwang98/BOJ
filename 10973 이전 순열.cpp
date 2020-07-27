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

int prevP() {
	int incIdx = -1;

	for (int i = N - 1; i >= 1; i--) {
		if (arr[i] > arr[i + 1]) {
			incIdx = i;
			break;
		}
	}

	if (incIdx == -1) return -1;

	int j;
	for (j = N; j > incIdx; j--) {
		if (arr[j] < arr[incIdx]) break;
	}

	swap(arr[incIdx], arr[j]);

	stack<int> s;
	for (int i = incIdx + 1; i <= N; i++) {
		s.push(arr[i]);
	}

	for (int i = incIdx + 1; i <= N; i++) {
		arr[i] = s.top();
		s.pop();
	}


	return 0;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	if (prevP()) {
		cout << -1;
		return 0;
	}

	else {
		for (int i = 1; i <= N; i++) cout << arr[i] << ' ';
	}
}