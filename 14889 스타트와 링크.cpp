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
int ability[21][21];
int flag[21];
int res = INF;

// N명 중 r명 선택
void comb(int curr, int cnt, int r) {
	if (cnt == r) {
		int home = 0;
		int away = 0;

		int c = N / 2;
		int idx1 = 1, idx2 = 1;
		int homeArr[21];
		int awayArr[21];

		for (int i = 1; i <= N; i++) {
			if (flag[i]) {
				homeArr[idx1++] = i;
			}
			else {
				awayArr[idx2++] = i;
			}
		}

		for (int i = 1; i <= c - 1; i++) {
			for (int j = i + 1; j <= c; j++) {
				home += ability[homeArr[i]][homeArr[j]];
				home += ability[homeArr[j]][homeArr[i]];

				away += ability[awayArr[i]][awayArr[j]];
				away += ability[awayArr[j]][awayArr[i]];
			}
		}

		if (abs(home - away) < res) res = abs(home - away);
		return;
	}
	if (curr > N)  return;

	flag[curr] = 1;
	comb(curr + 1, cnt + 1, r);

	flag[curr] = 0;
	comb(curr + 1, cnt, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> ability[i][j];
		}
	}

	comb(1, 0, N / 2);
	cout << res;
}