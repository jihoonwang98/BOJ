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

struct node {
	node(int x, int y, int z) : x(x), y(y), z(z) {}
	int x, y, z;
};

int a, b, c;
int visit[201][201][201];
vector<int> result;


void bfs() {
	queue<node> q;
	q.push(node(0, 0, c));
	visit[0][0][c] = 1;

	while (!q.empty()) {
		node popn = q.front();
		q.pop();

		if (popn.x == 0) {
			result.push_back(popn.z);
		}

		if (popn.x != 0) {
			if (popn.y < b) {            // x를 y에 따르는 경우
				int avail = b - popn.y;
				int nextX;
				int nextY;
				int nextZ;

				if (avail >= popn.x) {            // 다 따를 수 있는 경우
					nextX = 0;
					nextY = popn.y + popn.x;
					nextZ = popn.z;
				}
				else {                         // 일부만 따르는 경우
					nextX = popn.x - avail;
					nextY = b;
					nextZ = popn.z;
				}

				if (!visit[nextX][nextY][nextZ]) {
					q.push(node(nextX, nextY, nextZ));
					visit[nextX][nextY][nextZ] = 1;
				}

			}


			if (popn.z < c) {             // x를 z에 따르는 경우
				int avail = c - popn.z;
				int nextX;
				int nextY;
				int nextZ;

				if (avail >= popn.x) {            // 다 따를 수 있는 경우
					nextX = 0;
					nextY = popn.y;
					nextZ = popn.z + popn.x;
				}
				else {                         // 일부만 따르는 경우
					nextX = popn.x - avail;
					nextY = popn.y;
					nextZ = c;
				}

				if (!visit[nextX][nextY][nextZ]) {
					q.push(node(nextX, nextY, nextZ));
					visit[nextX][nextY][nextZ] = 1;
				}
			}

		}

		if (popn.y != 0) {
			if (popn.x < a) {              // y를 x에 따르는 경우
				int avail = a - popn.x;
				int nextX;
				int nextY;
				int nextZ;

				if (avail >= popn.y) {            // 다 따를 수 있는 경우
					nextX = popn.x + popn.y;
					nextY = 0;
					nextZ = popn.z;
				}
				else {                         // 일부만 따르는 경우
					nextX = a;
					nextY = popn.y - avail;
					nextZ = popn.z;
				}

				if (!visit[nextX][nextY][nextZ]) {
					q.push(node(nextX, nextY, nextZ));
					visit[nextX][nextY][nextZ] = 1;
				}

			}


			if (popn.z < c) {					// y를 z에 따르는 경우
				int avail = c - popn.z;
				int nextX;
				int nextY;
				int nextZ;

				if (avail >= popn.y) {            // 다 따를 수 있는 경우
					nextX = popn.x;
					nextY = 0;
					nextZ = popn.z + popn.y;
				}
				else {                         // 일부만 따르는 경우
					nextX = popn.x;
					nextY = popn.y - avail;
					nextZ = c;
				}

				if (!visit[nextX][nextY][nextZ]) {
					q.push(node(nextX, nextY, nextZ));
					visit[nextX][nextY][nextZ] = 1;
				}
			}
		}

		if (popn.z != 0) {
			if (popn.x < a) {						// z를 x에 따르는 경우
				int avail = a - popn.x;
				int nextX;
				int nextY;
				int nextZ;

				if (avail >= popn.z) {            // 다 따를 수 있는 경우
					nextX = popn.x + popn.z;
					nextY = popn.y;
					nextZ = 0;
				}
				else {                         // 일부만 따르는 경우
					nextX = a;
					nextY = popn.y;
					nextZ = popn.z - avail;
				}

				if (!visit[nextX][nextY][nextZ]) {
					q.push(node(nextX, nextY, nextZ));
					visit[nextX][nextY][nextZ] = 1;
				}

			}


			if (popn.y < b) {					// z를 y에 따르는 경우
				int avail = b - popn.y;
				int nextX;
				int nextY;
				int nextZ;

				if (avail >= popn.z) {            // 다 따를 수 있는 경우
					nextX = popn.x;
					nextY = popn.y + popn.z;
					nextZ = 0;
				}
				else {                         // 일부만 따르는 경우
					nextX = popn.x;
					nextY = b;
					nextZ = popn.z - avail;
				}

				if (!visit[nextX][nextY][nextZ]) {
					q.push(node(nextX, nextY, nextZ));
					visit[nextX][nextY][nextZ] = 1;
				}
			}
		}
	}


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;

	bfs();
	sort(result.begin(), result.end());
	for (int& x : result) cout << x << ' ';
}