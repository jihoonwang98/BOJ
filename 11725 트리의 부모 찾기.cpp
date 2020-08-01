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

#define MAX_V 100000
#define MOD 1000000009
const long long int LINF = (unsigned long long int)(-1) >> 1;
const int INF = (unsigned)(-1) >> 1;

using namespace std;

int N;
vector<int> adj[MAX_V + 1];
int visit[MAX_V + 1];
int parent[MAX_V + 1];

void dfs(int u) {

	visit[u] = 1;
	for (int& v : adj[u]) {
		if (!visit[v]) {
			parent[v] = u;
			dfs(v);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);
	for (int i = 2; i <= N; i++) cout << parent[i] << '\n';
}