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

int N;
int arr[NUM + 5];
int res[NUM + 5];
int resIdx = 0;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	res[resIdx++] = arr[1];

	for (int i = 2; i <= N; i++) {
		int idx = lower_bound(res, res + resIdx, arr[i]) - res;
		if (idx == resIdx) {
			res[resIdx++] = arr[i];
		}
		else res[idx] = arr[i];
	}

	cout << resIdx;
}