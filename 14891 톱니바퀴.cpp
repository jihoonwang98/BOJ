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

typedef pair<int, int> p;

int tobni[5][9];

int K;

void rotClk(int n) {
	int tmp[9] = { 0 };
	for (int i = 1; i <= 7; i++)tmp[i + 1] = tobni[n][i];
	tmp[1] = tobni[n][8];

	for (int i = 1; i <= 8; i++) tobni[n][i] = tmp[i];
}

void rotCntr(int n) {
	int tmp[9] = { 0 };
	for (int i = 2; i <= 8; i++)tmp[i - 1] = tobni[n][i];
	tmp[8] = tobni[n][1];

	for (int i = 1; i <= 8; i++) tobni[n][i] = tmp[i];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 8; j++) {
			char c;
			cin >> c;
			tobni[i][j] = c - '0';
		}
	}

	cin >> K;
	for (int i = 1; i <= K; i++) {
		int n, dir;
		cin >> n >> dir;

		int idx = n;
		int leftidx = n - 1;

		int dirArr[5] = { 0 };
		dirArr[n] = dir;

		while (leftidx >= 1) {
			if (tobni[idx][7] != tobni[leftidx][3]) {
				dirArr[leftidx] = (dirArr[idx] == 1) ? -1 : 1;
				idx--;
				leftidx--;
			}
			else {
				break;
			}
		}

		idx = n;
		int rightidx = n + 1;

		while (rightidx <= 4) {
			if (tobni[idx][3] != tobni[rightidx][7]) {
				dirArr[rightidx] = (dirArr[idx] == 1) ? -1 : 1;
				idx++;
				rightidx++;
			}
			else {
				break;
			}
		}

		for (int i = 1; i <= 4; i++) {
			if (dirArr[i] == 1) {
				rotClk(i);
			}

			else if (dirArr[i] == -1) {
				rotCntr(i);
			}
		}
	}

	int res = 0;
	int pow[5] = { 0,1,2,4,8 };
	for (int i = 1; i <= 4; i++) {
		if (tobni[i][1] == 1) {
			res += pow[i];
		}
	}

	cout << res;
}