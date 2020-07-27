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
#define NUM 1000
#define MOD 1000000009
const int INF = (unsigned)(-1) >> 1;

using namespace std;

int N, M;
int arr[10];
int arr2[10];
int cnt[10];
int idx = 0;

int res[10];

void f(int curr) {
	if (curr == M) {
		for (int i = 0; i < M; i++) cout << arr2[res[i]] << ' ';
		cout << '\n';
		return;
	}


	for (int i = 0; i < idx; i++) {
		res[curr] = i;
		f(curr + 1);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	int i = 0;
	while (i < N) {
		arr2[idx] = arr[i];
		cnt[idx] = upper_bound(arr, arr + N, arr[i]) - lower_bound(arr, arr + N, arr[i]);
		idx++;

		int it = i + 1;
		while (arr[it] == arr[i]) it++;
		i = it;
	}

	f(0);
}