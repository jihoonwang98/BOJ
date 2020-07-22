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

typedef pair<int, int> p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<p> s;

	int N;
	cin >> N;

	int* arr = new int[N + 1];
	for (int i = 1; i <= N; i++) cin >> arr[i];

	int* res = new int[N + 1];

	for (int i = N; i >= 1; i--) {
		if (i == N) {
			s.push(make_pair(arr[i], i));
			continue;
		}

		if (arr[i] < s.top().first) {
			s.push(make_pair(arr[i], i));
		}

		else {
			while (!s.empty() && arr[i] >= s.top().first) {
				p topP = s.top();
				s.pop();

				if (!s.empty()) res[topP.second] = s.top().first;
				else res[topP.second] = -1;
			}

			s.push(make_pair(arr[i], i));
		}
	}

	while (!s.empty()) {
		p topP = s.top();
		s.pop();

		if (!s.empty()) res[topP.second] = s.top().first;
		else res[topP.second] = -1;
	}

	for (int i = 1; i <= N; i++) cout << res[i] << ' ';
}
