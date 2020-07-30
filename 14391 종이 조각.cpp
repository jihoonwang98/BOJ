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
char map[5][5];
int flag[5][5];
int res = -1;

void f(int curr) {
	if (curr == N * M + 1) {

		/*cout << "flag : \n";
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cout << flag[i][j];
			}
			cout << '\n';
		}
		cout << '\n';*/

		int val = 0;
		int visited[5][5] = { 0 };

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!visited[i][j]) {
					if (flag[i][j] == 0) {
						int r = i;
						int c = j;

						string str = "";
						while (c <= M && flag[r][c] == 0) {
							visited[r][c] = 1;
							str += map[r][c];
							c++;
						}

						/*cout << str << '\n';*/

						val += stoi(str);
					}

					else {
						int r = i;
						int c = j;

						string str = "";
						while (r <= N && flag[r][c] == 1) {
							visited[r][c] = 1;
							str += map[r][c];
							r++;
						}

						/*cout << str << '\n';*/

						val += stoi(str);
					}

				}
			}
		}

		/*cout << "val : " << val << '\n';*/
		if (val > res) res = val;
		return;
	}
	int r = (curr - 1) / M + 1;
	int c = (curr - 1) % M + 1;
	
	flag[r][c] = 1;
	f(curr + 1);

	flag[r][c] = 0;
	f(curr + 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	f(1);
	cout << res;

}