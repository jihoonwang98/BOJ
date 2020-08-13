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
int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
int dir2[4][2] = { {0,0},{0,1},{1,0},{1,1} };
int map[101][101];
int N;
void makeCurves(int r, int c, int d, int g, vector<p>& v) {
	int endidx = 0;

	v.push_back(make_pair(r, c));
	v.push_back(make_pair(r + dir[d][0], c + dir[d][1]));
	if (g == 0) return;

	endidx = 1;


	int cnt = g;
	while (cnt--) {
		p rot = v[endidx];
		for (int i = endidx - 1; i >= 0; i--) {
			p curr = make_pair(v[i].first, v[i].second);
			p vctr = make_pair(curr.second - rot.second, -(curr.first - rot.first));
			v.push_back(make_pair(rot.first + vctr.first, rot.second + vctr.second));
		}
		endidx = v.size() - 1;
	}

	return;
}

int chkSqr(int r, int c) {
	int ret = 1;

	for (int k = 0; k < 4; k++) {
		int nR = r + dir2[k][0];
		int nC = c + dir2[k][1];

		if (map[nR][nC] != 1) {
			ret = 0;
			return ret;
		}
	}

	return ret;
}






int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int r, c, d, g;
		cin >> c >> r >> d >> g;
		vector<p> v;
		makeCurves(r, c, d, g, v);
		for (p& pairs : v) {
			map[pairs.first][pairs.second] = 1;
		}
	}

	/*for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (map[i][j]) cout << i << ' ' << j << '\n';
		}
	}*/

	int res = 0;
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (chkSqr(i, j)) res++;
		}
	}

	cout << res;
}