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
#define NUM 200000
#define MOD 10007

using namespace std;

typedef long long int ll;

const int inf = (unsigned)-1 >> 1;
int N;
int K;
int visit[200001];

struct node {
	node(int n, int t) : n(n), t(t) {}
	int n;
	int t;
};

void bfs() {
	queue<node> q;
	q.push(node(N, 0));
	visit[N] = 1;

	while (!q.empty()) {
		node popn = q.front();
		q.pop();

		if (popn.n == K) {
			cout << popn.t << '\n';
			return;
		}

		if (popn.n + 1 <= NUM && !visit[popn.n + 1]) {
			visit[popn.n + 1] = 1;
			q.push(node(popn.n + 1, popn.t + 1));
		}

		if (popn.n - 1 >= 0 && !visit[popn.n - 1]) {
			visit[popn.n - 1] = 1;
			q.push(node(popn.n - 1, popn.t + 1));
		}

		if (popn.n * 2 <= NUM && !visit[popn.n * 2]) {
			visit[popn.n * 2] = 1;
			q.push(node(popn.n * 2, popn.t + 1));
		}
	}
}



int main() {
	cin >> N >> K;
	bfs();
}