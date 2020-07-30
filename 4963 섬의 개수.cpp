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

int dir[8][2] = { {0,1}, {1,1}, {1,0},{1,-1}, {0,-1},{-1,-1},{-1,0}, {-1,1} };

int N, M;
int map[52][52];
int visited[52][52];
int val;

void dfs(int r, int c) {

	visited[r][c] = 1;


	for (int i = 0; i < 8; i++) {
		int nR = r + dir[i][0];
		int nC = c + dir[i][1];

		if (nR <= 0 || nR >= N + 1 || nC <= 0 || nC >= M + 1) continue;

		if (!visited[nR][nC] && map[nR][nC] == 1) dfs(nR, nC);
	}


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> M >> N;
		if (N == 0 && M == 0) return 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> map[i][j];
				visited[i][j] = 0;
			}
		}

		val = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!visited[i][j] && map[i][j] == 1) {
					dfs(i, j);
					val++;
				}
			}
		}
		cout << val << '\n';

	}



}