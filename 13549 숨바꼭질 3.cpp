
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
#define MAX_V 100000

using namespace std;

typedef long long int ll;
typedef pair<int, int> p;
const int INF = (unsigned)-1 >> 1;

int N, K;
int dist[MAX_V + 1];

void dijkstra(int s) {
	for (int i = 0; i <= MAX_V; i++) dist[i] = INF;
	dist[s] = 0;

	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push(make_pair(0, s));

	while (!pq.empty()) {
		p popP = pq.top();
		int curr = popP.second;
		int cost = popP.first;
		pq.pop();

		if (curr == K) {
			cout << cost;
			return;
		}

		if (cost > dist[curr]) continue;


		int next = curr + 1;
		int nextCost = cost + 1;
		if (next <= MAX_V && dist[next] > nextCost) {
			dist[next] = nextCost;
			pq.push(make_pair(dist[next], next));
		}

		next = curr - 1;
		nextCost = cost + 1;
		if (next >= 0 && dist[next] > nextCost) {
			dist[next] = nextCost;
			pq.push(make_pair(dist[next], next));
		}

		next = curr * 2;
		nextCost = cost;
		if (next <= MAX_V && dist[next] > nextCost) {
			dist[next] = nextCost;
			pq.push(make_pair(dist[next], next));
		}
	}

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	dijkstra(N);
}