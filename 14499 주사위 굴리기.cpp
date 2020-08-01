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

int dir[5][2] = { {0,0}, {0,1}, {0,-1}, {-1,0}, {1,0} };

int map[21][21];

int N, M;
int r, c;
int K;

int operation[1001];
int dice[7];
int up = 1;
int down = 6;
int right2 = 3;
int left2 = 4;
int north = 2;
int south = 5;

void mvR() {
	int tmpR = right2;
	int tmpU = up;
	int tmpL = left2;
	int tmpD = down;

	right2 = tmpU;
	up = tmpL;
	left2 = tmpD;
	down = tmpR;
}

void mvL() {
	int tmpR = right2;
	int tmpU = up;
	int tmpL = left2;
	int tmpD = down;

	right2 = tmpD;
	up = tmpR;
	left2 = tmpU;
	down = tmpL;
}

void mvS() {
	int tmpN = north;
	int tmpU = up;
	int tmpS = south;
	int tmpD = down;


	up = tmpN;
	south = tmpU;
	down = tmpS;
	north = tmpD;
}


void mvN() {
	int tmpN = north;
	int tmpU = up;
	int tmpS = south;
	int tmpD = down;


	up = tmpS;
	south = tmpD;
	down = tmpN;
	north = tmpU;
}


void copy2() {
	if (map[r][c] == 0) {
		map[r][c] = dice[down];
	}
	else {
		dice[down] = map[r][c];
		map[r][c] = 0;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> r >> c >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}


	for (int i = 1; i <= K; i++) cin >> operation[i];


	for (int i = 1; i <= K; i++) {
		int nR = r + dir[operation[i]][0];
		int nC = c + dir[operation[i]][1];

		if (nR < 0 || nR >= N || nC < 0 || nC >= M) continue;

		r = nR;
		c = nC;

		if (operation[i] == 1) {
			mvR();
		}

		else if (operation[i] == 2) {
			mvL();
		}

		else if (operation[i] == 3) {
			mvN();
		}

		else if (operation[i] == 4) {
			mvS();
		}
		copy2();
		cout << dice[up] << '\n';
	}


}