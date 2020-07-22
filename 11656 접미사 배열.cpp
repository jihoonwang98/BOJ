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

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	vector<string> v;
	int len = s.size();
	v.reserve(len);

	for (int i = 0; i < len; i++) {
		v.push_back(s.substr(i));
	}

	sort(v.begin(), v.end());

	for (string s : v) {
		cout << s << '\n';
	}
}