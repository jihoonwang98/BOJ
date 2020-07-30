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
	node() : r(0), c(0), d(0) {}
	node(int r, int c, int d) : r(r), c(c), d(d) {}
	int r, c, d;
};

int T;
int dir[8][2] = { {1,2}, {2,1}, {2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };
int N;
int visited[300][300];
node curr;
node dest;

void bfs() {

	queue<node> q;
	q.push(curr);
	visited[curr.r][curr.c] = 1;

	while (!q.empty()) {
		node popn = q.front();
		q.pop();
		if (dest.r == popn.r && dest.c == popn.c) {
			cout << popn.d << '\n';
			return;
		}

		for (int i = 0; i < 8; i++) {
			int nR = popn.r + dir[i][0];
			int nC = popn.c + dir[i][1];

			if (nR < 0 || nR >= N || nC < 0 || nC >= N) continue;

			if (!visited[nR][nC]) {
				visited[nR][nC] = 1;
				q.push(node(nR, nC, popn.d + 1));
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		cin >> curr.r >> curr.c;
		cin >> dest.r >> dest.c;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 0;
			}
		}
		bfs();
	}

}