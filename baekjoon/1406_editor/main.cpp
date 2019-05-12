#include <stdio.h>
#include <stdlib.h>

struct Node {
	char c;
	Node *left;
	Node *right;
};

int N;

Node *head;
Node *cursor;

int main() {
	// read input
	char tmp[600005];
	scanf("%s", tmp);
	scanf("%d", &N);

	// init
	head = (Node*) malloc(sizeof(Node));
	*head = {' ', NULL, NULL};

	// make linked list
	Node *prevNode = head;
	for (int i = 0; tmp[i] != 0; i++) {
		prevNode->right = (Node*) malloc(sizeof(Node));
		*(prevNode->right) = {tmp[i], prevNode, NULL};
		prevNode = prevNode->right;
	}
	cursor = prevNode;

	// simulate
	while (N--) {
		char cmd;
		char arg;
		scanf(" %c", &cmd);

		if (cmd == 'L') {
			if (cursor->left != NULL) cursor = cursor->left;
		} else if (cmd == 'D') {
			if (cursor->right != NULL) cursor = cursor->right;
		} else if (cmd == 'B') {
			if (cursor->left != NULL) {
				Node *left = cursor->left;
				Node *right = cursor->right;
				free(cursor);

				left->right = right;
				if (right != NULL) right->left = left;

				cursor = left;
			}
		} else if (cmd == 'P') {
			scanf(" %c", &arg);
			
			Node *newNode = (Node*) malloc(sizeof(Node));
			newNode->c = arg;

			Node *left = cursor;
			Node *right = cursor->right;

			left->right = newNode;
			newNode->left = left;
			newNode->right = right;
			if (right != NULL) right->left = newNode;

			cursor = newNode;
		}
	}

	// print result
	Node *cur = head->right;
	while (cur != NULL) {
		printf("%c", cur->c);
		cur = cur->right;
	}
	printf("\n");

	return 0;
}
