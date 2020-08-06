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
#include <functional>
#define NUM 200000
#define MOD 10007
#define MAX_V 100000

using namespace std;
typedef pair<int, int> p;
int N;

struct node {
	node(int v) : v(v), left(NULL), right(NULL), parent(NULL) {}
	int v;
	struct node* left;
	struct node* right;
	struct node* parent;
};


node* ptrArr[10001];
int nodeN[10001];
int nodeidx[10001];
int root;

node* makeNode(int v) {
	node* n = new node(v);
	n->left = n->right = n->parent = NULL;
	return n;
}

inline node* mostLeftChild(int v) {
	node* curr = ptrArr[v];
	while (curr->left != NULL) {
		curr = curr->left;
	}
	return curr;
}

inline node* mostRightChild(int v) {
	node* curr = ptrArr[v];
	while (curr->right != NULL) {
		curr = curr->right;
	}
	return curr;
}

int countNodeNumByDfs(node* curr) {
	if (nodeN[curr->v]) return nodeN[curr->v];

	if (curr->left == NULL && curr->right == NULL) {
		nodeN[curr->v] = 1;
		return 1;
	}

	else if (curr->left == NULL && curr->right != NULL) {
		nodeN[curr->v] = countNodeNumByDfs(curr->right) + 1;
		return nodeN[curr->v];
	}

	else if (curr->left != NULL && curr->right == NULL) {
		nodeN[curr->v] = countNodeNumByDfs(curr->left) + 1;
		return nodeN[curr->v];
	}

	else {
		nodeN[curr->v] = countNodeNumByDfs(curr->left) + countNodeNumByDfs(curr->right) + 1;
		return nodeN[curr->v];
	}
}

inline int leftChildN(int v) {
	if (ptrArr[v]->left == NULL) return -1;
	return nodeN[ptrArr[v]->left->v];
}

inline int rightChildN(int v) {
	if (ptrArr[v]->right == NULL) return -1;
	return nodeN[ptrArr[v]->right->v];
}

void setIdx(node* curr) {
	if (curr->left == NULL && curr->right == NULL) return;

	if (!nodeidx[curr->v] && leftChildN(curr->v) != -1 && nodeidx[mostLeftChild(curr->v)->v] != 0) {
		nodeidx[curr->v] = nodeidx[mostLeftChild(curr->v)->v] + leftChildN(curr->v);
	}

	else if (!nodeidx[curr->v] && rightChildN(curr->v) != -1 && nodeidx[mostRightChild(curr->v)->v] != 0) {
		nodeidx[curr->v] = nodeidx[mostRightChild(curr->v)->v] - rightChildN(curr->v);
	}


	if (leftChildN(curr->v) != -1 && !nodeidx[mostLeftChild(curr->v)->v]) nodeidx[mostLeftChild(curr->v)->v] = nodeidx[curr->v] - leftChildN(curr->v);
	if (rightChildN(curr->v) != -1 && !nodeidx[mostRightChild(curr->v)->v]) nodeidx[mostRightChild(curr->v)->v] = nodeidx[curr->v] + rightChildN(curr->v);



	if (curr->left != NULL) setIdx(curr->left);
	if (curr->right != NULL) setIdx(curr->right);
}


void bfs() {
	vector<vector<int>> v(50);

	int maxH = -1;
	queue<p> q;
	q.push(make_pair(root, 1));

	while (!q.empty()) {
		p popP = q.front();
		q.pop();
		if (maxH < popP.second) maxH = popP.second;
		v[popP.second].push_back(nodeidx[popP.first]);
		if (ptrArr[popP.first]->left != NULL) q.push(make_pair(ptrArr[popP.first]->left->v, popP.second + 1));
		if (ptrArr[popP.first]->right != NULL) q.push(make_pair(ptrArr[popP.first]->right->v, popP.second + 1));
	}

	int reslevel = 1;
	int resV = -1;
	for (int i = 1; i <= maxH; i++) {
		int minV = *(v[i].begin());
		int maxV = *(v[i].end() - 1);

		if (maxV - minV + 1 > resV) {
			resV = maxV - minV + 1;
			reslevel = i;
		}
	}
	cout << reslevel << " " << resV;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) ptrArr[i] = makeNode(i);

	for (int i = 1; i <= N; i++) {
		int n, l, r;
		cin >> n >> l >> r;

		if (l != -1) {
			ptrArr[n]->left = ptrArr[l];
			ptrArr[l]->parent = ptrArr[n];
		}

		if (r != -1) {
			ptrArr[n]->right = ptrArr[r];
			ptrArr[r]->parent = ptrArr[n];
		}
	}

	root = 1;
	while (ptrArr[root]->parent != NULL) {
		root = ptrArr[root]->parent->v;
	}

	countNodeNumByDfs(ptrArr[root]);


	nodeidx[mostLeftChild(root)->v] = 1;
	nodeidx[root] = leftChildN(root) + 1;
	nodeidx[mostRightChild(root)->v] = nodeN[root];

	setIdx(ptrArr[root]);
	/*for (int i = 1; i <= N; i++) {
		cout << nodeidx[i] << "\n";
	}*/

	bfs();
}