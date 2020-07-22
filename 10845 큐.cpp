#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <list>
#include <queue>
#include <stack>

using namespace std;


int main() {
	int N;
	cin >> N;
	cin.get();

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		string op;
		getline(cin, op);

		if (strncmp(op.c_str(), "push", 4) == 0) {
			int x = stoi(op.substr(5));
			q.push(x);
		}

		else if (strncmp(op.c_str(), "pop", 3) == 0) {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}

		else if (strncmp(op.c_str(), "size", 4) == 0) {
			cout << q.size() << '\n';
		}

		else if (strncmp(op.c_str(), "empty", 5) == 0) {
			cout << q.empty() << '\n';
		}

		else if (strncmp(op.c_str(), "front", 5) == 0) {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}

		else if (strncmp(op.c_str(), "back", 4) == 0) {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}
}
