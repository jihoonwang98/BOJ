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

int N, M;
int visited[1001];
vector<int> adj[1001];
int res;

void dfs(int v) {

	visited[v] = 1;
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

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			res++;
			dfs(i);
		}
	}
	cout << res;

}