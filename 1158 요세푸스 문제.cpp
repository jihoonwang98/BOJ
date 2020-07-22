#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

struct Node {
	int val;
	struct Node* link;
};

Node* head = NULL;
Node* tail = NULL;
int elemNum = 0;

Node* makeNode(int v) {
	Node* newNode = new Node;
	newNode->val = v;
	newNode->link = NULL;
	return newNode;
}

bool empty() {
	return (elemNum == 0);
}

void pushToTail(int val) {
	Node* n = makeNode(val);

	if (empty()) {
		head = tail = n;
		tail->link = head;
	}

	else {
		tail->link = n;
		tail = n;
		tail->link = head;
	}

	elemNum++;
}

void printAll() {
	int flag = 0;
	for (Node* ptr = head; !flag; ptr = ptr->link) {
		cout << ptr->val << ' ';
		if (ptr == tail) flag = 1;
	}
	cout << '\n';
}

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) pushToTail(i);
	//printAll();
	Node* prev = tail;
	Node* curr = head;

	vector<int> v;

	while (!empty()) {
		for (int k = 1; k <= K - 1; k++) {
			curr = curr->link;
			prev = prev->link;
		}

		prev->link = curr->link;
		int x = curr->val;
		v.push_back(x);
		delete curr;
		elemNum--;
		curr = prev->link;
	}

	cout << "<";
	for (int i = 0; i < v.size(); i++) {
		if (i != v.size() - 1) {
			cout << v[i] << ", ";
		}
		else cout << v[i] << ">";
	}

}
