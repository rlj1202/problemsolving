#include <cstdio>
#include <vector>

using namespace std;

struct Staff {
	int id;
	int customid;
	int salary;
};

vector<int> adj[500005];
int salaries[500005];
int customids[500005];
int staffcnts[500005];

int tree[2000006];
int lazy[2000006];

// assign custom ids and count staff
int assign_custom_id(int id, int customid) {
	customids[id] = customid;

	int staffcnt = 0;

	for (int staff : adj[id]) {
		staffcnt += assign_custom_id(staff, customid + 1 + staffcnt) + 1;
	}

	return staffcnts[id] = staffcnt;
}

void update_lazy(int p, int q, int node) {
	if (lazy[node]) {
		tree[node] += (q - p + 1) * lazy[node];
		if (p != q) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int p, int q, int node, int l, int r, int delta) {
	update_lazy(p, q, node);

	if (r < p || q < l) return;
	if (l <= p && q <= r) {
		lazy[node] += delta;
		update_lazy(p, q, node);
		return;
	}

	int mid = (p + q) >> 1;
	update(p, mid, node * 2, l, r, delta);
	update(mid + 1, q, node * 2 + 1, l, r, delta);
	//tree[node] = tree[node * 2] + tree[node * 2 + 1];;
}

int query(int p, int q, int node, int i) {
	update_lazy(p, q, node);

	if (i < p || q < i) return 0;
	if (p == q) return tree[node];

	int mid = (p + q) >> 1;
	return query(p, mid, node * 2, i) + query(mid + 1, q, node * 2 + 1, i);
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int salary;
	scanf("%d", &salary);
	salaries[1] = salary;

	for (int n = 2; n <= N; n++) {
		int salary, boss;
		scanf("%d %d", &salary, &boss);

		adj[boss].push_back(n);
		salaries[n] = salary;
	}

	assign_custom_id(1, 1);

	while (M--) {
		char cmd;
		int staffid;
		scanf(" %c %d", &cmd, &staffid);

		if (cmd == 'p') {
			int salary;
			scanf("%d", &salary);

			int l = customids[staffid] + 1;
			int r = customids[staffid] + staffcnts[staffid];

			update(1, N, 1, l, r, salary);
		} else if (cmd == 'u') {
			int result = query(1, N, 1, customids[staffid]);
			printf("%d\n", salaries[staffid] + result);
		}
	}

	return 0;
}
