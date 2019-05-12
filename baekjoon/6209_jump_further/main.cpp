#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int index, delta;
	Node *left;
	Node *right;
};

bool operator> (const Node &a, const Node &b) {
	return a.delta > b.delta;
}

int D, N, M;
int dists[50004];

Node deltas[50004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main() {
	scanf("%d %d %d", &D, &N, &M);
	for (int n = 0; n < N; n++) {
		scanf("%d", dists + n);
	}
	dists[N] = D;
	sort(dists, dists + N + 1);

	int prev = 0;
	for (int n = 0; n < N + 1; n++) {
		int cur = dists[n];
		int delta = cur - prev;

		deltas[n].index = n;
		deltas[n].delta = delta;

		deltas[n].right = &deltas[n + 1];
		deltas[n + 1].left = &deltas[n];

		q.push({delta, n});

		prev = cur;
	}
	deltas[N].right = NULL;

	Node head;
	head.index = -1;
	head.delta = 0x3f3f3f3f;
	head.right = &deltas[0];
	deltas[0].left = &head;

	printf("\t");
	Node *cur = head.right;
	while (cur != NULL) {
		printf("%2d ", cur->delta);
		cur = cur->right;
	}
	printf("\n");

	while (M) {
		int delta = q.top().first;
		int index = q.top().second;
		q.pop();
		if (delta < deltas[index].delta) continue;

		M--;
		
		Node *leftnode = deltas[index].left;
		Node *rightnode = deltas[index].right;

		if (leftnode != NULL && leftnode->delta < rightnode->delta) { // merge with left
			leftnode->delta += delta;
			q.push({leftnode->delta, leftnode->index});
		} else { // merge with right
			rightnode->delta += delta;
			q.push({rightnode->delta, rightnode->index});
		}

		if (leftnode != NULL) leftnode->right = rightnode;
		if (rightnode != NULL) rightnode->left = leftnode;

		printf("\t");
		Node *cur = head.right;
		while (cur != NULL) {
			printf("%2d ", cur->delta);
			cur = cur->right;
		}
		printf("\n");
	}

	while (q.top().first < deltas[q.top().second].delta) q.pop();

	printf("%d\n", q.top().first);

	return 0;
}
