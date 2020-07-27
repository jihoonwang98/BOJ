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
int arr[10];
int idx[10];
int flag[10];
int result = -9999999;

void f(int curr) {

	if (curr == N + 1) {

		int res = 0;
		int tmp[10];

		for (int i = 1; i <= N; i++) {
			tmp[idx[i]] = arr[i];
		}

		for (int i = 1; i <= N - 1; i++) {
			res += abs(tmp[i] - tmp[i + 1]);
		}

		if (result < res) result = res;
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!flag[i]) {
			flag[i] = 1;
			idx[curr] = i;
			f(curr + 1);
			flag[i] = 0;
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	f(1);
	cout << result;
}