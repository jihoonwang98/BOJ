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
int map[11][11];
int idx[11];
int flag[11];
int res = INF;

void cal() {
	int flag = 0;
	int ret = 0;
	for (int i = 1; i <= N - 1; i++) {
		if (map[idx[i]][idx[i + 1]] == 0) {
			flag = 1;
			break;
		}
		ret += map[idx[i]][idx[i + 1]];
	}
	if (map[idx[N]][idx[1]] == 0) flag = 1;
	if (flag) return;
	ret += map[idx[N]][idx[1]];
	if (res > ret) res = ret;
}


void f(int curr) {

	if (curr == N + 1) {
		cal();
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
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	f(1);
	cout << res;
}