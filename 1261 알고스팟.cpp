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
typedef pair<int, int> p;
typedef pair<int, p> p2;
const int INF = (unsigned)-1 >> 1;

int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
char map[101][101];
int dist[101][101];
int N, M;

void dijkstra() {
	priority_queue<p2, vector<p2>, greater<p2>>pq;
	pq.push(make_pair(0, make_pair(1, 1)));

	while (!pq.empty()) {
		p2 popP = pq.top();
		pq.pop();

		int r = popP.second.first;
		int c = popP.second.second;
		int cost = popP.first;

		if (dist[r][c] < cost) continue;

		for (int k = 0; k < 4; k++) {
			int nR = r + dir[k][0];
			int nC = c + dir[k][1];

			if (nR >= N + 1 || nR <= 0 || nC >= M + 1 || nC <= 0) continue;

			if (dist[nR][nC] > cost + map[nR][nC] - '0') {
				dist[nR][nC] = cost + map[nR][nC] - '0';
				pq.push(make_pair(dist[nR][nC], make_pair(nR, nC)));
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dist[i][j] = INF;
		}
	}
	dist[1][1] = 0;

	dijkstra();
	cout << dist[N][M];
}