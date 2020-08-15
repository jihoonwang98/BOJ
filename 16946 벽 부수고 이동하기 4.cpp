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
#define MAX_V 100000
#define MOD 1000000009

const long long int LINF = (unsigned long long int)(-1) >> 1;
const int INF = (unsigned)(-1) >> 1;

using namespace std;
typedef pair<int, int> p;

int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int map[1001][1001];
int region[1001][1001];
int N, M;
int regionNum = 1;
int area = 0;
vector<int> areaArr;
int visit[1001][1001];

void dfs(int r, int c) {
	visit[r][c] = 1;
	region[r][c] = regionNum;
	area++;

	for (int k = 0; k < 4; k++) {
		int nR = r + dir[k][0];
		int nC = c + dir[k][1];
		if (nR <= 0 || nR >= N + 1 || nC <= 0 || nC >= M + 1) continue;

		if (!visit[nR][nC] && map[nR][nC] == 0) dfs(nR, nC);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char tmp;
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
	}
	areaArr.push_back(0);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visit[i][j] && map[i][j] == 0) {
				area = 0;
				dfs(i, j);
				areaArr.push_back(area);
				regionNum++;
			}
		}
	}

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << region[i][j];
		}
		cout << '\n';
	}

	for (int x : areaArr) cout << x << '\n';*/


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 1) {
				vector<int> tmp;
				for (int k = 0; k < 4; k++) {
					int nR = i + dir[k][0];
					int nC = j + dir[k][1];
					if (nR <= 0 || nR >= N + 1 || nC <= 0 || nC >= M + 1) continue;

					if (region[nR][nC] == 0) continue;

					int exist = 0;
					for (int x = 0; x < tmp.size(); x++) {
						if (tmp[x] == region[nR][nC]) {
							exist = 1;
							break;
						}
					}
					if (!exist)	tmp.push_back(region[nR][nC]);
				}

				int sum = 0;
				for (int x = 0; x < tmp.size(); x++) {
					sum += areaArr[tmp[x]];
				}
				map[i][j] = (sum + 1) % 10;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}


}