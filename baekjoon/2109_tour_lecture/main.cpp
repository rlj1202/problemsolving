#include <bits/stdc++.h>

using namespace std;

struct element {
	int pay, day;

	bool operator<(const element &o) const {
		return day < o.day;
	}
};

priority_queue<element> elements;
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		int pay, day;
		cin >> pay >> day;

		elements.push({ pay, day });
	}

	int sum = 0;

	for (int today = 10000; today >= 1; today--) {
		while (!elements.empty()) {
			if (elements.top().day < today) break;

			pq.push(elements.top().pay);
			elements.pop();
		}

		if (pq.empty()) continue;

		sum += pq.top();
		pq.pop();
	}

	cout << sum << '\n';

	return 0;
}
