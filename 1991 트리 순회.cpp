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

struct node {
	node(char c) : c(c), left(NULL), right(NULL) {}
	char c;
	struct node* left;
	struct node* right;
};

int N;
node* root = NULL;
node* arr[26];

node* makeNode(char c) {
	node* newNode = new node(c);
	return newNode;
}

void preorder(node* curr) {
	if (curr == NULL) return;
	cout << curr->c;
	preorder(curr->left);
	preorder(curr->right);

}

void inorder(node* curr) {
	if (curr == NULL) return;
	inorder(curr->left);
	cout << curr->c;
	inorder(curr->right);
}

void postorder(node* curr) {
	if (curr == NULL) return;
	postorder(curr->left);
	postorder(curr->right);
	cout << curr->c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) arr[i] = makeNode('A' + i);
	for (int i = 0; i < N; i++) {
		char p, c1, c2;
		cin >> p >> c1 >> c2;

		if (c1 != '.') {
			arr[p - 'A']->left = arr[c1 - 'A'];
		}

		if (c2 != '.') {
			arr[p - 'A']->right = arr[c2 - 'A'];
		}
	}

	root = arr[0];
	preorder(root);
	cout << '\n';
	inorder(root);
	cout << '\n';
	postorder(root);

}