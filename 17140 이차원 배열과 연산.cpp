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

int arr[101][101];

int N = 3;
int M = 3;
int r, c, k;


void opR() {

	int rowN[101] = { 0 };
	for (int i = 1; i <= N; i++) {

		int cnt[101] = { 0 };
		vector<p> v;

		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 0) continue;
			cnt[arr[i][j]]++;
		}

		for (int j = 1; j <= 100; j++) {
			if (cnt[j]) {
				v.push_back(make_pair(cnt[j], j));
			}
		}

		sort(v.begin(), v.end());

		int row[101];
		int rowidx = 1;

		int s = v.size();
		int k = min(s, 50);
		for (int j = 0; j < k; j++) {
			row[rowidx++] = v[j].second;
			row[rowidx++] = v[j].first;
		}

		rowN[i] = rowidx - 1;

		for (int j = 1; j < rowidx; j++) {
			arr[i][j] = row[j];
		}
	}

	int nextM = -1;
	for (int i = 1; i <= N; i++) {
		if (rowN[i] > nextM) nextM = rowN[i];
	}

	M = nextM;

	for (int i = 1; i <= N; i++) {
		for (int j = rowN[i] + 1; j <= M; j++) {
			arr[i][j] = 0;
		}
	}

}

void opC() {
	int colN[101] = { 0 };
	for (int j = 1; j <= M; j++) {

		int cnt[101] = { 0 };
		vector<p> v;

		for (int i = 1; i <= N; i++) {
			if (arr[i][j] == 0) continue;
			cnt[arr[i][j]]++;
		}

		for (int i = 1; i <= 100; i++) {
			if (cnt[i]) {
				v.push_back(make_pair(cnt[i], i));
			}
		}

		sort(v.begin(), v.end());

		int col[101];
		int colidx = 1;

		int s = v.size();
		int k = min(s, 50);
		for (int i = 0; i < k; i++) {
			col[colidx++] = v[i].second;
			col[colidx++] = v[i].first;
		}

		colN[j] = colidx - 1;

		for (int i = 1; i < colidx; i++) {
			arr[i][j] = col[i];
		}
	}

	int nextN = -1;
	for (int i = 1; i <= M; i++) {
		if (colN[i] > nextN) nextN = colN[i];
	}

	N = nextN;

	for (int j = 1; j <= M; j++) {
		for (int i = colN[j] + 1; i <= N; i++) {
			arr[i][j] = 0;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}

	if (1 <= r && r <= 3 && 1 <= c && c <= 3 && arr[r][c] == k) {
		cout << 0;
		return 0;
	}



	int t = 0;

	while (t <= 99) {
		if (N >= M) {
			opR();
		}
		else {
			opC();
		}

		/*for (int i = 1; i <= N; i++) {
			for (int j = 1;j <= M; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';*/

		t++;
		if (arr[r][c] == k) {
			cout << t;
			return 0;
		}
	}

	cout << -1;

}