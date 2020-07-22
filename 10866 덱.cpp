#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
#include <deque>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> dq;
	int N;
	cin >> N;
	cin.get();
	for (int i = 1; i <= N; i++) {
		string op;
		getline(cin, op);

		if (strncmp(op.c_str(), "push_front", 10) == 0) {
			int x = stoi(op.substr(11));
			dq.push_front(x);
		}

		else if (strncmp(op.c_str(), "push_back", 9) == 0) {
			int x = stoi(op.substr(10));
			dq.push_back(x);
		}

		else if (strncmp(op.c_str(), "pop_front", 9) == 0) {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}

		else if (strncmp(op.c_str(), "pop_back", 8) == 0) {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}

		else if (strncmp(op.c_str(), "size", 4) == 0) {
			cout << dq.size() << '\n';
		}

		else if (strncmp(op.c_str(), "empty", 5) == 0) {
			cout << dq.empty() << '\n';
		}

		else if (strncmp(op.c_str(), "front", 5) == 0) {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
			}
		}

		else if (strncmp(op.c_str(), "back", 4) == 0) {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
			}
		}

	}
}
