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

using namespace std;

int cnt[1000010] = { 0 };

struct Node {
	Node(int i, int v, int o) : idx(i), val(v), org(o) {}
	int idx;
	int val;
	int org;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<Node> s;

	int N;
	cin >> N;

	int* arr_org = new int[N + 1];
	int* arr = new int[N + 1];
	int* res = new int[N + 1];

	for (int i = 1; i <= N; i++) {
		cin >> arr_org[i];
		cnt[arr_org[i]]++;
	}

	for (int i = 1; i <= N; i++) {
		arr[i] = cnt[arr_org[i]];
	}



	for (int i = N; i >= 1; i--) {
		if (i == N) {
			s.push(Node(i, arr[i], arr_org[i]));
			continue;
		}


		if (arr[i] < s.top().val) {
			s.push(Node(i, arr[i], arr_org[i]));
		}

		else {
			while (!s.empty() && arr[i] >= s.top().val) {
				Node topN = s.top();
				s.pop();

				if (!s.empty()) res[topN.idx] = s.top().org;
				else res[topN.idx] = -1;
			}

			s.push(Node(i, arr[i], arr_org[i]));
		}
	}

	while (!s.empty()) {
		Node topN = s.top();
		s.pop();

		if (!s.empty()) res[topN.idx] = s.top().org;
		else res[topN.idx] = -1;
	}

	for (int i = 1; i <= N; i++) cout << res[i] << ' ';

}
