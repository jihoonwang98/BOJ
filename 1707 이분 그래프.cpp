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

int K, V, E;
vector<int> adj[20002];
int visited[20002];
int res;

void dfs(int v, int color) {
	if (res) return;
	visited[v] = color;

	for (int a : adj[v]) {
		if (visited[a] && visited[a] == visited[v]) {
			res = 1;
			return;
		}
	}

	for (int a : adj[v]) {
		if (!visited[a]) {
			if (color == 1) dfs(a, 2);
			else if (color == 2) dfs(a, 1);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;
	while (K--) {
		cin >> V >> E;
		for (int i = 1; i <= E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 1; i <= V; i++) {
			if (!visited[i]) dfs(i, 1);
		}

		if (res) cout << "NO\n";
		else cout << "YES\n";


		for (int i = 1; i <= V; i++) {
			adj[i].clear();
			visited[i] = 0;
		}
		res = 0;
	}

}