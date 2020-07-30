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
#define NUM 10000
#define MOD 1000000009
const long long int LINF = (unsigned long long int)(-1) >> 1;
const int INF = (unsigned)(-1) >> 1;

using namespace std;

int arr[21];

void add(int x) {
	arr[x] = 1;
}

void remove(int x) {
	arr[x] = 0;
}

void check(int x) {
	cout << arr[x] << '\n';
}

void toggle(int x) {
	arr[x] ^= 1;
}

void all() {
	for (int i = 1; i <= 20; i++) arr[i] = 1;
}

void empty2() {
	for (int i = 1; i <= 20; i++) arr[i] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;
	cin.get();
	for (int i = 1; i <= M; i++) {
		string op;
		getline(cin, op);

		if (strncmp(op.c_str(), "add", 3) == 0) {
			string sub = op.substr(4);
			int x = stoi(sub);
			add(x);
		}

		else if (strncmp(op.c_str(), "remove", 6) == 0) {
			string sub = op.substr(7);
			int x = stoi(sub);
			remove(x);
		}

		else if (strncmp(op.c_str(), "check", 5) == 0) {
			string sub = op.substr(6);
			int x = stoi(sub);
			check(x);
		}

		else if (strncmp(op.c_str(), "toggle", 6) == 0) {
			string sub = op.substr(7);
			int x = stoi(sub);
			toggle(x);
		}

		else if (strncmp(op.c_str(), "all", 3) == 0) {
			all();
		}

		else if (strncmp(op.c_str(), "empty", 5) == 0) {
			empty2();
		}


	}
}