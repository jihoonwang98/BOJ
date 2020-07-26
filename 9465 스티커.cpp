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
#define NUM 100000
#define MOD 10007

using namespace std;

typedef long long int ll;

int arr[2][NUM + 5];
int memo[2][NUM + 5];


// �� n ���� ��ƼĿ �� ������ �ٿ��� ����(m==0)�� �����ϴ� ����� ��
// �� n ���� ��ƼĿ �� ������ �ٿ��� �Ʒ���(m==1)�� �����ϴ� ����� ��
int f(int n, int m) {
	if (n < 0) return 0;
	if (memo[m][n - 1] != -1) return memo[m][n - 1];

	if (m == 0) {
		return memo[m][n - 1] = max(f(n - 1, 1), f(n - 2, 1)) + arr[0][n - 1];
	}

	else if (m == 1) {
		return memo[m][n - 1] = max(f(n - 1, 0), f(n - 2, 0)) + arr[1][n - 1];
	}
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				memo[i][j] = -1;
			}
		}


		cout << max(f(n, 0), f(n, 1)) << '\n';

	}

}