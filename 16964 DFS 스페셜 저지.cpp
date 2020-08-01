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


typedef pair<int, int> p;
int N;
int correct = 1;
vector<int> adj[MAX_V + 1];
int dfsRes[MAX_V + 1];

int isConnected(int u, int v) {
	if (find(adj[u].begin(), adj[u].end(), v) != adj[u].end()) return 1;
	else return 0;
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

	for (int i = 1; i <= N; i++)  cin >> dfsRes[i];
	if (dfsRes[1] != 1) {
		correct = 0;
		cout << 0;
		return 0;
	}

	stack<p> s;
	s.push(make_pair(1, adj[1].size()));
	int idx = 2;

	while (!s.empty()) {
		if (s.top().second == 0) {
			s.pop();
			if (!s.empty())s.top().second--;
			else break;
			continue;
		}

		if (idx > N) continue;

		if (isConnected(s.top().first, dfsRes[idx])) {
			s.push(make_pair(dfsRes[idx], adj[dfsRes[idx]].size() - 1));
			idx++;
		}

		else {
			correct = 0;
			break;
		}
	}

	cout << correct;

}