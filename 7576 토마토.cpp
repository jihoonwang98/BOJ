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
const long long int LINF = (unsigned long long int)(-1) >> 1;
const int INF = (unsigned)(-1) >> 1;

using namespace std;

struct node {
	node(int r, int c, int d) : r(r), c(c), d(d) {}
	int r, c, d;
};

int dir[4][2] = { {0,1} , {1,0}, {0,-1}, {-1,0} };
int N, M;
int map[1001][1001];
int visited[1001][1001];
int total;
int curr;

vector<node> v;

void bfs() {
	queue<node> q;

	for (node n : v) {
		q.push(n);
		visited[n.r][n.c] = 1;
	}

	node popn(0, 0, 0);
	while (!q.empty()) {
		popn = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nR = popn.r + dir[i][0];
			int nC = popn.c + dir[i][1];

			if (nR <= 0 || nR >= N + 1 || nC <= 0 || nC >= M + 1) continue;

			if (visited[nR][nC] == 0 && map[nR][nC] == 0) {
				map[nR][nC] = 1;
				visited[nR][nC] = 1;
				q.push(node(nR, nC, popn.d + 1));
				curr++;
			}
		}
	}

	if (curr == total) {
		cout << popn.d << '\n';
	}

	else cout << -1;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] != -1) total++;
			if (map[i][j] == 1) {
				curr++;
				v.push_back(node(i, j, 0));
			}

		}
	}

	bfs();
}