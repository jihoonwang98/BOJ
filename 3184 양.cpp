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

int R, C;
char map[251][251];
int region[251][251];
int visit[251][251];
int regionNum = 1;
vector<p> num;

void dfs(int r, int c) {
	visit[r][c] = 1;
	region[r][c] = regionNum;


	for (int k = 0; k < 4; k++) {
		int nR = r + dir[k][0];
		int nC = c + dir[k][1];

		if (nR <= 0 || nR >= R + 1 || nC <= 0 || nC >= C + 1) continue;
		if (!visit[nR][nC] && map[nR][nC] != '#') {
			dfs(nR, nC);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
		}
	}


	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (!visit[i][j] && map[i][j] != '#') {
				dfs(i, j);
				regionNum++;
			}
		}
	}
	num.assign(regionNum + 1, make_pair(0, 0));

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {/*
			cout << region[i][j];*/
			if (map[i][j] == 'v') {
				num[region[i][j]].first++;
			}

			else if (map[i][j] == 'o') {
				num[region[i][j]].second++;
			}
		}
		/*cout << '\n';*/
	}
	/*for (int i = 1; i <= regionNum; i++) {
		cout << num[i].first << ' ' << num[i].second << '\n';
	}*/

	int wolf = 0;
	int lamb = 0;
	for (int i = 1; i <= regionNum; i++) {
		if (num[i].first < num[i].second) {
			lamb += num[i].second;
		}
		else {
			wolf += num[i].first;
		}
	}
	cout << lamb << ' ' << wolf;
}