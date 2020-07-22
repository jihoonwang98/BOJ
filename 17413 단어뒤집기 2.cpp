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

	string str;
	getline(cin, str);

	stack<char> s;

	int len = str.size();

	int i = 0;
	while (i < len) {
		if (str[i] == ' ') {
			cout << ' ';
			i++;
			continue;
		}

		if (str[i] == '<') {
			cout << '<';
			i++;
			while (str[i] != '>') {
				cout << str[i++];
			}
			cout << '>';
			i++;

			continue;
		}

		while ((str[i] != '<' && str[i] != ' ') && i < len) {
			s.push(str[i++]);
		}

		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
	}
}
