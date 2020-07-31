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
int bfsRes[MAX_V + 1];

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

	for (int i = 1; i <= N; i++) cin >> bfsRes[i];

	int correct = 1;
	int j = 2;
	for (int i = 1; i <= N; i++) {
		int childN = bfsRes[i] == 1 ? adj[bfsRes[i]].size() : adj[bfsRes[i]].size() - 1;
		while (childN--) {
			if (find(adj[bfsRes[i]].begin(), adj[bfsRes[i]].end(), bfsRes[j]) == adj[bfsRes[i]].end()) {
				correct = 0;
				break;
			}
			j++;
		}
		if (!correct) break;
	}

	cout << correct;
}