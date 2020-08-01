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
const int INF = (unsigned)-1 >> 1;

int dir[4][2] = { {0,1}, {1,0},{0,-1},{-1,0} };
int map[20][20];
int mapTmp[20][20];

int permutation[5];
int N;
int res[20];
int maxRes = -1;

void up();
void down();
void left();
void right();

void p(int curr) {
	if (curr == 5) {
		/*for (int i = 0; i < 5; i++) cout << permutation[i] << ' ';
		cout << '\n';*/

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				mapTmp[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < 5; i++) {
			if (permutation[i] == 0) {
				up();
			}

			else if (permutation[i] == 1) {
				right();
			}

			else if (permutation[i] == 2) {
				down();
			}

			else if (permutation[i] == 3) {
				left();
			}

			/*for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout << mapTmp[i][j];
				}
				cout << '\n';
			}
			cout << '\n';*/
		}


		int maxVal = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (maxVal < mapTmp[i][j]) maxVal = mapTmp[i][j];
			}
		}

		if (maxVal > maxRes) maxRes = maxVal;
		return;
	}

	for (int i = 0; i < 4; i++) {
		permutation[curr] = i;
		p(curr + 1);
	}
}

void f() {

	int tmp[21] = { 0 };
	int tmpidx = 0;

	for (int i = 0; i < N; i++) {
		if (res[i] != 0) {
			tmp[tmpidx++] = res[i];
		}
	}
	for (int i = 0; i < N; i++) {
		res[i] = tmp[i];
	}
	int idx = 0;
	while (idx < N) {
		if (idx + 1 < N && res[idx] == res[idx + 1]) {
			res[idx] *= 2;
			res[idx + 1] = -1;
			idx += 2;
		}
		else {
			idx++;
		}
	}

	int blnk = 0;
	for (int i = 0; i < N; i++) {
		if (res[i] == -1) {
			blnk++;
			for (int j = i; j < N - 1; j++) {
				res[j] = res[j + 1];
			}
			res[N - blnk] = 0;
		}
	}

	/*for (int i = 0; i < N; i++) cout << res[i] << ' ';
	cout << '\n';*/
}

void up() {
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			res[i] = mapTmp[i][j];
		}
		f();
		for (int i = 0; i < N; i++) {
			mapTmp[i][j] = res[i];
		}
	}
}

void down() {
	for (int j = 0; j < N; j++) {
		for (int i = N - 1; i >= 0; i--) {
			res[N - 1 - i] = mapTmp[i][j];
		}
		f();
		for (int i = N - 1; i >= 0; i--) {
			mapTmp[N - 1 - i][j] = res[i];
		}
	}
}

void left() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			res[j] = mapTmp[i][j];
		}
		f();
		for (int j = 0; j < N; j++) {
			mapTmp[i][j] = res[j];
		}
	}
}

void right() {
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j >= 0; j--) {
			res[N - 1 - j] = mapTmp[i][j];
		}
		f();
		for (int j = N - 1; j >= 0; j--) {
			mapTmp[i][N - 1 - j] = res[j];
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	p(0);

	cout << maxRes;
}