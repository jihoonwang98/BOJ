#include <iostream>
#include <string>
#include <algorithm>
#define SIZE 200000
using namespace std;

int M;
typedef struct node* NodePtr;


typedef struct node
{
	char c;
	NodePtr left, right;
}Node;

NodePtr front = nullptr;
NodePtr rear = nullptr;
NodePtr curr = nullptr;

NodePtr createNode(char c)
{
	NodePtr tmp = new Node;
	tmp->c = c;
	tmp->left = tmp->right = nullptr;
	return tmp;
}


void pushToRear(char c)
{
	NodePtr newN = createNode(c);

	rear->right = newN;
	newN->left = rear;

	rear = newN;
}


void add(char c)
{
	if (curr == rear)
	{
		pushToRear(c);
		curr = rear;
		return;
	}
	NodePtr leftnode = curr;
	NodePtr rightnode = curr->right;
	NodePtr newnode = createNode(c);

	leftnode->right = newnode;
	newnode->left = leftnode;

	rightnode->left = newnode;
	newnode->right = rightnode;

	curr = newnode;
}

void del()
{
	if (curr == front) return;
	if (curr == rear)
	{
		NodePtr newRear = rear->left;
		newRear->right = nullptr;
		free(rear);
		curr = rear = newRear;
		return;
	}
	NodePtr tmp = curr;
	NodePtr leftnode = curr->left;
	NodePtr rightnode = curr->right;

	leftnode->right = rightnode;
	rightnode->left = leftnode;
	curr = leftnode;
	free(tmp);
}

void moveleft()
{
	if (curr == front) return;

	curr = curr->left;
}

void moveright()
{
	if (curr == rear) return;
	curr = curr->right;
}



void input()
{
	front = rear = curr = createNode(' ');

	string tmp;
	getline(cin, tmp);

	for (int i = 0; i < tmp.length(); i++)
	{
		pushToRear(tmp[i]);
	}

	curr = rear;
	cin >> M;
	cin.get();
}

void printOut()
{
	NodePtr tmp = front->right;

	while (tmp)
	{
		cout << tmp->c;
		tmp = tmp->right;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	input();

	for (int i = 1; i <= M; i++)
	{
		string tmp;
		getline(cin, tmp);


		switch (tmp[0])
		{
		case 'L':
			moveleft();
			break;

		case 'D':
			moveright();
			break;

		case 'B':
			del();
			break;

		case 'P':
			add(tmp[2]);
			break;
		}
	}

	printOut();

}
