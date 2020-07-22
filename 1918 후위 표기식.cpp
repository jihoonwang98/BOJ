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

int priority(char c) {
	switch (c) {
	case '(':
		return 0;

	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string op;
	getline(cin, op);

	stack<char> s;
	int len = op.size();

	for (int i = 0; i < len; i++) {
		if (isalpha(op[i])) {
			cout << op[i];
		}

		else {
			if (op[i] == '(') {
				s.push('(');
			}

			else if (op[i] == ')') {
				while (s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				s.pop();
			}

			else {
				if (s.empty()) s.push(op[i]);

				else {
					if (priority(s.top()) < priority(op[i])) s.push(op[i]);

					else {
						while (!s.empty() && priority(s.top()) >= priority(op[i])) {
							cout << s.top();
							s.pop();
						}
						s.push(op[i]);
					}
				}

			}
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}


}