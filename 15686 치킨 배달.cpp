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

vector<p> store;
vector<p> house;
int N, M;
int S;
int map[51][51];
int combRes[20];
int res = INF;


void comb(int idx, int curr) {

	combRes[idx] = curr;

	if (idx == M) {
		for (int i = 1; i <= idx; i++) {
			int r = store[combRes[i] - 1].first;
			int c = store[combRes[i] - 1].second;
			map[r][c] = 9;
		}

		int chickDistsum = 0;
		for (int i = 0; i < house.size(); i++) {
			int houseR = house[i].first;
			int houseC = house[i].second;

			int chickDist = INF;
			for (int j = 0; j < store.size(); j++) {
				if (map[store[j].first][store[j].second] == 9) {
					int tmp = abs(houseR - store[j].first) + abs(houseC - store[j].second);
					if (tmp < chickDist) chickDist = tmp;
				}
			}

			chickDistsum += chickDist;
		}

		if (chickDistsum < res) res = chickDistsum;

		for (int i = 1; i <= idx; i++) {
			int r = store[combRes[i] - 1].first;
			int c = store[combRes[i] - 1].second;
			map[r][c] = 2;
		}


		return;
	}

	for (int i = curr + 1; i <= S; i++) {
		comb(idx + 1, i);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) house.push_back(make_pair(i, j));
			else if (map[i][j] == 2) store.push_back(make_pair(i, j));
		}
	}

	S = store.size();

	for (int i = 1; i <= S; i++) comb(1, i);

	cout << res;
}