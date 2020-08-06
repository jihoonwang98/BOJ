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
#include <functional>
#define NUM 200000
#define MOD 10007
#define MAX_V 100000

using namespace std;

typedef long long int ll;
const int INF = (unsigned)-1 >> 1;

typedef pair<int, int> p;

int R, C, N;
int res[11];
int visit[31][11];
int end2 = 0;
int minRes = INF;
int maxN;

inline int idx(int r, int c) {
	return (r - 1) * (C - 1) + c;
}

inline p coord(int idx) {
	return make_pair((idx - 1) / (C - 1) + 1, (idx - 1) % (C - 1) + 1);
}

inline int calculateRes() {
	for (int j = 1; j <= C; j++) {
		int currC = j;
		int currR = 1;

		while (currR <= R) {
			if (visit[currR][currC]) currC++;
			else if (currC >= 2 && visit[currR][currC - 1]) currC--;
			currR++;
		}

		if (currC != j) return 0;
	}

	return 1;
}

inline void f(int curr, int cnt) {
	if (calculateRes()) {
		if (cnt < minRes) minRes = cnt;
		return;
	}

	if (cnt >= 3) {
		return;
	}


	for (int i = curr + 1; i <= maxN; i++) {
		int r = coord(i).first;
		int c = coord(i).second;

		if ((c == 1 && !visit[r][c] && !visit[r][c + 1]) || (c == C - 1 && !visit[r][c] && !visit[r][c - 1]) || (1 < c && c < C - 1 && !visit[r][c] && !visit[r][c - 1] && !visit[r][c + 1])) {
			visit[r][c] = 1;
			f(i, cnt + 1);
			visit[r][c] = 0;
		}
	}
	return;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C >> N >> R;
	if (N == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= C; i++) res[i] = i;

	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		visit[a][b] = 1;
	}

	if (calculateRes()) {
		cout << "0";
		return 0;
	}


	maxN = idx(R, C - 1);
	for (int i = 1; i <= maxN; i++) {
		int r = coord(i).first;
		int c = coord(i).second;

		if ((c == 1 && !visit[r][c] && !visit[r][c + 1]) || (c == C - 1 && !visit[r][c] && !visit[r][c - 1]) || (1 < c && c < C - 1 && !visit[r][c] && !visit[r][c - 1] && !visit[r][c + 1])) {
			visit[r][c] = 1;
			f(i, 1);
			visit[r][c] = 0;
		}
	}

	if (minRes == INF) cout << -1;
	else cout << minRes;
}