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
#define NUM 1000
#define MOD 1000000009
const int INF = (unsigned)(-1) >> 1;

using namespace std;


int N;
int res = 0;

char map[55][55];


void chkCandy() {

	int maxC = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			int left = 0;
			int r = i;
			int c = j - 1;
			while (c >= 1 && map[r][c] == map[i][j]) {
				left++;
				c--;
			}

			int right = 0;
			r = i;
			c = j + 1;
			while (c <= N && map[r][c] == map[i][j]) {
				right++;
				c++;
			}

			int garo = left + right + 1;


			int up = 0;
			r = i - 1;
			c = j;
			while (r >= 1 && map[r][c] == map[i][j]) {
				up++;
				r--;
			}

			int down = 0;
			r = i + 1;
			c = j;
			while (r <= N && map[r][c] == map[i][j]) {
				down++;
				r++;
			}

			int sero = up + down + 1;

			if (maxC < max(garo, sero)) maxC = max(garo, sero);
		}
	}
	if (res < maxC) res = maxC;
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
		for (int j = 1; j <= N - 1; j++) {
			if (map[i][j] != map[i][j + 1]) {
				swap(map[i][j], map[i][j + 1]);
				chkCandy();
				swap(map[i][j], map[i][j + 1]);
			}
		}
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] != map[i + 1][j]) {
				swap(map[i][j], map[i + 1][j]);
				chkCandy();
				swap(map[i][j], map[i + 1][j]);
			}
		}
	}

	cout << res;

}