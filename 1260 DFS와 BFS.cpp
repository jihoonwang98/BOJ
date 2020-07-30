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

int N, M, V;
int visited[1001];
vector<int> adj[1001];

void bfs() {
	queue<int> q;
	q.push(V);
	visited[V] = 1;

	while (!q.empty()) {
		int pop = q.front();
		q.pop();
		cout << pop << ' ';

		for (int a : adj[pop]) {
			if (!visited[a]) {
				visited[a] = 1;
				q.push(a);
			}
		}
	}
}

void dfs(int v) {

	visited[v] = 1;
	cout << v << ' ';

	for (int a : adj[v]) {
		if (!visited[a]) {
			dfs(a);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(V);
	cout << '\n';
	for (int i = 1; i <= N; i++) visited[i] = 0;
	bfs();
}