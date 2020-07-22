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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	double val[26] = { 0 };
	string op;
	stack<double> s;

	cin >> N;
	cin.get();

	getline(cin, op);

	for (int i = 0; i < N; i++)  cin >> val[i];

	int len = op.size();
	for (int i = 0; i < len; i++) {
		if (isalpha(op[i])) {
			s.push(val[op[i] - 'A']);
		}

		else {
			double num2 = s.top();
			s.pop();
			double num1 = s.top();
			s.pop();

			double res = 0;

			switch (op[i]) {
			case '+':
				res = num1 + num2;
				break;

			case '-':
				res = num1 - num2;
				break;

			case '*':
				res = num1 * num2;
				break;

			case '/':
				res = num1 / num2;
				break;
			}

			s.push(res);
		}
	}

	cout << fixed;
	cout.precision(2);

	cout << s.top();
}