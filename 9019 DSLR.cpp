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
#define NOT_VISITED -9

using namespace std;

struct node {
	node(int n, int p, int c) : n(n), prev(p), c(c) {}
	int n;
	int prev;
	char c;
};

typedef pair<int, char> p;  // <prev, op>

p memo[10001];

int D(int n) {
	return (2 * n) % 10000;
}

int S(int n) {
	return (n == 0) ? 9999 : (n - 1);
}

int L(int n) {
	return (n % 1000) * 10 + (n / 1000);
}


int R(int n) {
	return (n / 10) + (n % 10) * 1000;
}


void bfs(int start, int end) {
	for (int i = 0; i <= 10000; i++) {
		memo[i].first = memo[i].second = NOT_VISITED;
	}

	queue<node> q;
	q.push(node(start, -1, 0));
	memo[start].first = -1;
	memo[start].second = 0;


	while (!q.empty()) {
		node popn = q.front();
		q.pop();

		if (popn.n == end) {
			stack<char> stk;
			stk.push(popn.c);

			int curr = memo[popn.n].first;
			while (curr != start) {
				stk.push(memo[curr].second);
				curr = memo[curr].first;
			}

			while (!stk.empty()) {
				cout << stk.top();
				stk.pop();
			}
			cout << "\n";

			/*stack<int> stkint;
			stkint.push(popn.n);

			curr = memo[popn.n].first;
			while (curr != -1) {
				stkint.push(curr);
				curr = memo[curr].first;
			}

			while (!stkint.empty()) {
				cout << stkint.top() << ' ';
				stkint.pop();
			}
			cout << "\n";*/



			return;
		}

		int d = D(popn.n);
		int s = S(popn.n);
		int l = L(popn.n);
		int r = R(popn.n);

		if (memo[d].first == NOT_VISITED) {
			q.push(node(d, popn.n, 'D'));
			memo[d].first = popn.n;
			memo[d].second = 'D';
		}

		if (memo[s].first == NOT_VISITED) {
			q.push(node(s, popn.n, 'S'));
			memo[s].first = popn.n;
			memo[s].second = 'S';
		}

		if (memo[l].first == NOT_VISITED) {
			q.push(node(l, popn.n, 'L'));
			memo[l].first = popn.n;
			memo[l].second = 'L';
		}

		if (memo[r].first == NOT_VISITED) {
			q.push(node(r, popn.n, 'R'));
			memo[r].first = popn.n;
			memo[r].second = 'R';
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		bfs(a, b);
	}
}