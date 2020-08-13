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
#define NOT_VISITED -1

using namespace std;

const int INF = (unsigned)(-1) >> 1;

struct node {
	node(int r, int c, int d, int a) : r(r), c(c), d(d), ab(a) {}
	int r, c, d;
	int ab;
};

int N, M, K;
int map[1001][1001];
int visit[1001][1001][11];
int dir[4][2] = { {0,1}, {1,0}, {0,-1},{-1,0} };



void bfs() {
	queue<node> q;
	visit[1][1][K] = 1;
	q.push(node(1, 1, 1, K));


	while (!q.empty()) {
		node popn = q.front();
		q.pop();

		if (popn.r == N && popn.c == M) {
			cout << popn.d;
			return;
		}

		for (int k = 0; k < 4; k++) {
			int nR = popn.r + dir[k][0];
			int nC = popn.c + dir[k][1];

			if (nR <= 0 || nR >= N + 1 || nC <= 0 || nC >= M + 1) continue;

			if (map[nR][nC] == 0 && visit[nR][nC][popn.ab] == NOT_VISITED) {
				visit[nR][nC][popn.ab] = popn.d + 1;
				q.push(node(nR, nC, popn.d + 1, popn.ab));
			}
			else if (map[nR][nC] == 1 && popn.ab > 0 && visit[nR][nC][popn.ab - 1] == NOT_VISITED) {
				visit[nR][nC][popn.ab - 1] = popn.d + 1;
				q.push(node(nR, nC, popn.d + 1, popn.ab - 1));
			}
		}

	}

	cout << -1;
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	cin.get();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char tmp;
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 0; k <= K; k++) {
				visit[i][j][k] = NOT_VISITED;
			}
		}
	}

	bfs();

	/*for (int k = 0; k < 2; k++) {
		cout << k << '\n';

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cout << visit[i][j][k] << ' ';
			}
			cout << '\n';
		}

		cout << '\n';
	}*/

}