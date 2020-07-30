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

int dir[4][2] = { {0,1} , {1,0}, {0,-1}, {-1,0} };
char map[101][101];
int visited[101][101];
int N, M;

struct node {
	node(int r, int c, int d) : r(r), c(c), d(d) {}
	int r, c;
	int d;
};


void bfs() {

	queue<node> q;
	q.push(node(1, 1, 1));
	visited[1][1] = 1;


	while (!q.empty()) {
		node popN = q.front();
		q.pop();
		if (popN.r == N && popN.c == M) {
			cout << popN.d;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nR = popN.r + dir[i][0];
			int nC = popN.c + dir[i][1];

			if (nR <= 0 || nR >= N + 1 || nC <= 0 || nC >= M + 1)continue;

			if (!visited[nR][nC] && map[nR][nC] == '1') {
				visited[nR][nC] = 1;
				q.push(node(nR, nC, popN.d + 1));
			}
		}
	}


}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin.get();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	bfs();

}