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

int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

char map[26][26];
int visited[26][26];
int N;

vector<int> danji;
int val = 0;

void dfs(int r, int c) {
	visited[r][c] = 1;
	val++;

	for (int i = 0; i < 4; i++) {
		int nR = r + dir[i][0];
		int nC = c + dir[i][1];

		if (nR <= 0 || nC <= 0 || nR >= N + 1 || nC >= N + 1) continue;

		if (map[nR][nC] == '1' && visited[nR][nC] == 0) {
			dfs(nR, nC);
		}
	}

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin.get();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j] && map[i][j] == '1') {
				val = 0;
				dfs(i, j);
				danji.push_back(val);
			}
		}
	}

	cout << danji.size() << '\n';
	sort(danji.begin(), danji.end());
	for (int i : danji) cout << i << '\n';

}