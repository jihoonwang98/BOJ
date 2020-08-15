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

char up[3][3];
char down[3][3];
char front[3][3];
char back[3][3];
char left2[3][3];
char right2[3][3];

p rotRC_clock(p rc) {
	return make_pair(rc.second, 2 - rc.first);
}

p rotRC_cntr(p rc) {
	return make_pair(2 - rc.second, rc.first);
}

void initialize() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			up[i][j] = 'w';
			down[i][j] = 'y';
			front[i][j] = 'r';
			back[i][j] = 'o';
			left2[i][j] = 'g';
			right2[i][j] = 'b';
		}
	}
}


void rot(const string& op) {
	if (op[0] == 'U') {
		if (op[1] == '+') {
			char tmp[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[i][j] = up[i][j];
				}
			}


			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					p rotrc = rotRC_clock(make_pair(i, j));
					up[rotrc.first][rotrc.second] = tmp[i][j];
				}
			}

			char tmp_front[3];
			char tmp_back[3];
			char tmp_left[3];
			char tmp_right[3];


			for (int i = 0; i < 3; i++) {
				tmp_front[i] = front[0][i];
				tmp_back[i] = back[0][i];
				tmp_left[i] = left2[0][i];
				tmp_right[i] = right2[0][i];
			}

			for (int i = 0; i < 3; i++) {
				front[0][i] = tmp_right[i];
				left2[0][i] = tmp_front[i];
				back[0][i] = tmp_left[i];
				right2[0][i] = tmp_back[i];
			}
		}

		else if (op[1] == '-') {
			char tmp[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[i][j] = up[i][j];
				}
			}


			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					p rotrc = rotRC_cntr(make_pair(i, j));
					up[rotrc.first][rotrc.second] = tmp[i][j];
				}
			}

			char tmp_front[3];
			char tmp_back[3];
			char tmp_left[3];
			char tmp_right[3];


			for (int i = 0; i < 3; i++) {
				tmp_front[i] = front[0][i];
				tmp_back[i] = back[0][i];
				tmp_left[i] = left2[0][i];
				tmp_right[i] = right2[0][i];
			}

			for (int i = 0; i < 3; i++) {
				front[0][i] = tmp_left[i];
				left2[0][i] = tmp_back[i];
				back[0][i] = tmp_right[i];
				right2[0][i] = tmp_front[i];
			}
		}
	}

	if (op[0] == 'D') {
		if (op[1] == '+') {
			char tmp[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[i][j] = down[i][j];
				}
			}


			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					p rotrc = rotRC_clock(make_pair(i, j));
					down[rotrc.first][rotrc.second] = tmp[i][j];
				}
			}

			char tmp_front[3];
			char tmp_back[3];
			char tmp_left[3];
			char tmp_right[3];


			for (int i = 0; i < 3; i++) {
				tmp_front[i] = front[2][i];
				tmp_back[i] = back[2][i];
				tmp_left[i] = left2[2][i];
				tmp_right[i] = right2[2][i];
			}

			for (int i = 0; i < 3; i++) {
				front[2][i] = tmp_left[i];
				left2[2][i] = tmp_back[i];
				back[2][i] = tmp_right[i];
				right2[2][i] = tmp_front[i];
			}
		}

		else if (op[1] == '-') {
			char tmp[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[i][j] = down[i][j];
				}
			}


			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					p rotrc = rotRC_cntr(make_pair(i, j));
					down[rotrc.first][rotrc.second] = tmp[i][j];
				}
			}

			char tmp_front[3];
			char tmp_back[3];
			char tmp_left[3];
			char tmp_right[3];


			for (int i = 0; i < 3; i++) {
				tmp_front[i] = front[2][i];
				tmp_back[i] = back[2][i];
				tmp_left[i] = left2[2][i];
				tmp_right[i] = right2[2][i];
			}

			for (int i = 0; i < 3; i++) {
				front[2][i] = tmp_right[i];
				left2[2][i] = tmp_front[i];
				back[2][i] = tmp_left[i];
				right2[2][i] = tmp_back[i];
			}

		}
	}


	if (op[0] == 'F') {
		if (op[1] == '+') {
			char tmp[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[i][j] = front[i][j];
				}
			}


			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					p rotrc = rotRC_clock(make_pair(i, j));
					front[rotrc.first][rotrc.second] = tmp[i][j];
				}
			}

			char tmp_up[3];
			char tmp_right[3];
			char tmp_down[3];
			char tmp_left[3];


			for (int i = 0; i < 3; i++) {
				tmp_up[i] = up[2][i];
				tmp_right[i] = right2[i][0];
				tmp_down[i] = down[0][2 - i];
				tmp_left[i] = left2[2 - i][2];
			}

			for (int i = 0; i < 3; i++) {
				up[2][i] = tmp_left[i];
				right2[i][0] = tmp_up[i];
				down[0][2 - i] = tmp_right[i];
				left2[2 - i][2] = tmp_down[i];
			}
		}

		else if (op[1] == '-') {
			char tmp[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[i][j] = front[i][j];
				}
			}


			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					p rotrc = rotRC_cntr(make_pair(i, j));
					front[rotrc.first][rotrc.second] = tmp[i][j];
				}
			}

			char tmp_up[3];
			char tmp_right[3];
			char tmp_down[3];
			char tmp_left[3];


			for (int i = 0; i < 3; i++) {
				tmp_up[i] = up[2][i];
				tmp_right[i] = right2[i][0];
				tmp_down[i] = down[0][2 - i];
				tmp_left[i] = left2[2 - i][2];
			}

			for (int i = 0; i < 3; i++) {
				up[2][i] = tmp_right[i];
				right2[i][0] = tmp_down[i];
				down[0][2 - i] = tmp_left[i];
				left2[2 - i][2] = tmp_up[i];
			}
		}
	}


	if (op[0] == 'B') {
		if (op[1] == '+') {
			char tmp[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[i][j] = back[i][j];
				}
			}


			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					p rotrc = rotRC_clock(make_pair(i, j));
					back[rotrc.first][rotrc.second] = tmp[i][j];
				}
			}

			char tmp_up[3];
			char tmp_left[3];
			char tmp_down[3];
			char tmp_right[3];


			for (int i = 0; i < 3; i++) {
				tmp_up[i] = up[0][2 - i];
				tmp_left[i] = left2[i][0];
				tmp_down[i] = down[2][i];
				tmp_right[i] = right2[2 - i][2];
			}

			for (int i = 0; i < 3; i++) {
				up[0][2 - i] = tmp_right[i];
				left2[i][0] = tmp_up[i];
				down[2][i] = tmp_left[i];
				right2[2 - i][2] = tmp_down[i];
			}
		}

		else if (op[1] == '-') {
			char tmp[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[i][j] = back[i][j];
				}
			}


			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					p rotrc = rotRC_cntr(make_pair(i, j));
					back[rotrc.first][rotrc.second] = tmp[i][j];
				}
			}

			char tmp_up[3];
			char tmp_left[3];
			char tmp_down[3];
			char tmp_right[3];


			for (int i = 0; i < 3; i++) {
				tmp_up[i] = up[0][2 - i];
				tmp_left[i] = left2[i][0];
				tmp_down[i] = down[2][i];
				tmp_right[i] = right2[2 - i][2];
			}

			for (int i = 0; i < 3; i++) {
				up[0][2 - i] = tmp_left[i];
				left2[i][0] = tmp_down[i];
				down[2][i] = tmp_right[i];
				right2[2 - i][2] = tmp_up[i];
			}
		}
	}


	if (op[0] == 'R') {
		if (op[1] == '+') {
			char tmp[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[i][j] = right2[i][j];
				}
			}


			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					p rotrc = rotRC_clock(make_pair(i, j));
					right2[rotrc.first][rotrc.second] = tmp[i][j];
				}
			}

			char tmp_up[3];
			char tmp_back[3];
			char tmp_down[3];
			char tmp_front[3];


			for (int i = 0; i < 3; i++) {
				tmp_up[i] = up[2 - i][2];
				tmp_back[i] = back[i][0];
				tmp_down[i] = down[2 - i][2];
				tmp_front[i] = front[2 - i][2];
			}

			for (int i = 0; i < 3; i++) {
				up[2 - i][2] = tmp_front[i];
				back[i][0] = tmp_up[i];
				down[2 - i][2] = tmp_back[i];
				front[2 - i][2] = tmp_down[i];
			}
		}

		else if (op[1] == '-') {
			char tmp[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[i][j] = right2[i][j];
				}
			}


			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					p rotrc = rotRC_cntr(make_pair(i, j));
					right2[rotrc.first][rotrc.second] = tmp[i][j];
				}
			}

			char tmp_up[3];
			char tmp_back[3];
			char tmp_down[3];
			char tmp_front[3];


			for (int i = 0; i < 3; i++) {
				tmp_up[i] = up[2 - i][2];
				tmp_back[i] = back[i][0];
				tmp_down[i] = down[2 - i][2];
				tmp_front[i] = front[2 - i][2];
			}

			for (int i = 0; i < 3; i++) {
				up[2 - i][2] = tmp_back[i];
				back[i][0] = tmp_down[i];
				down[2 - i][2] = tmp_front[i];
				front[2 - i][2] = tmp_up[i];
			}
		}
	}

	if (op[0] == 'L') {
		if (op[1] == '+') {
			char tmp[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[i][j] = left2[i][j];
				}
			}


			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					p rotrc = rotRC_clock(make_pair(i, j));
					left2[rotrc.first][rotrc.second] = tmp[i][j];
				}
			}

			char tmp_up[3];
			char tmp_front[3];
			char tmp_down[3];
			char tmp_back[3];


			for (int i = 0; i < 3; i++) {
				tmp_up[i] = up[i][0];
				tmp_front[i] = front[i][0];
				tmp_down[i] = down[i][0];
				tmp_back[i] = back[2 - i][2];
			}

			for (int i = 0; i < 3; i++) {
				up[i][0] = tmp_back[i];
				front[i][0] = tmp_up[i];
				down[i][0] = tmp_front[i];
				back[2 - i][2] = tmp_down[i];
			}
		}

		else if (op[1] == '-') {
			char tmp[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[i][j] = left2[i][j];
				}
			}


			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					p rotrc = rotRC_cntr(make_pair(i, j));
					left2[rotrc.first][rotrc.second] = tmp[i][j];
				}
			}

			char tmp_up[3];
			char tmp_front[3];
			char tmp_down[3];
			char tmp_back[3];


			for (int i = 0; i < 3; i++) {
				tmp_up[i] = up[i][0];
				tmp_front[i] = front[i][0];
				tmp_down[i] = down[i][0];
				tmp_back[i] = back[2 - i][2];
			}

			for (int i = 0; i < 3; i++) {
				up[i][0] = tmp_front[i];
				front[i][0] = tmp_down[i];
				down[i][0] = tmp_back[i];
				back[2 - i][2] = tmp_up[i];
			}
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
		initialize();
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			string op;
			cin >> op;
			rot(op);
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << up[i][j];
			}
			cout << '\n';
		}
	}
}