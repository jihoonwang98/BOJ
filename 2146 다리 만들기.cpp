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

const int inf = (unsigned)-1 >> 1;

int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N;
int map[102][102];
int visit[102][102];
int component = 0;
int res = inf;

struct node {
	node(int r, int c, int d) :r(r), c(c), d(d) {}
	int r, c, d;
};

void bfs1(int r, int c, int k) {

	queue<node> q;
	map[r][c] = k;
	visit[r][c] = 1;
	q.push(node(r, c, 0));

	while (!q.empty()) {
		node popn = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nR = popn.r + dir[i][0];
			int nC = popn.c + dir[i][1];
			if (nR <= 0 || nR >= N + 1 || nC <= 0 || nC >= N + 1) continue;

			if (visit[nR][nC] == 0 && map[nR][nC] == 1) {
				visit[nR][nC] = 1;
				map[nR][nC] = k;
				q.push(node(nR, nC, 0));
			}
		}
	}
}

void bfs2(int r, int c, int x) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[i][j] = 0;
		}
	}

	queue<node> q;
	visit[r][c] = 1;
	q.push(node(r, c, 0));


	while (!q.empty()) {
		node popn = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nR = popn.r + dir[k][0];
			int nC = popn.c + dir[k][1];
			if (nR <= 0 || nR >= N + 1 || nC <= 0 || nC >= N + 1) continue;

			if (map[nR][nC] != 0 && map[nR][nC] != x) {
				if (res > popn.d) res = popn.d;
				return;
			}
		}

		for (int k = 0; k < 4; k++) {
			int nR = popn.r + dir[k][0];
			int nC = popn.c + dir[k][1];
			if (nR <= 0 || nR >= N + 1 || nC <= 0 || nC >= N + 1) continue;

			if (visit[nR][nC] == 0 && map[nR][nC] == 0) {
				visit[nR][nC] = 1;
				q.push(node(nR, nC, popn.d + 1));
			}
		}
	}


}

void printMap() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1 && !visit[i][j]) {
				bfs1(i, j, ++component);
			}
		}
	}

	//printMap();


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 0) continue;

			int chk = 0;
			for (int k = 0; k < 4; k++) {
				int nR = i + dir[k][0];
				int nC = j + dir[k][1];
				if (nR <= 0 || nR >= N + 1 || nC <= 0 || nC >= N + 1) continue;
				if (map[nR][nC] == 0) {
					chk = 1;
					break;
				}
			}

			if (chk) bfs2(i, j, map[i][j]);
		}
	}

	cout << res;
}