#include <iostream>

struct Card {
	char rank, suit;
};

Card table;

int main() {
	char raw[3];
	scanf("%s", raw);

	table = {raw[0], raw[1]};

	bool result = false;

	for (int i = 0; i < 5; i++) {
		scanf("%s", raw);

		Card card = {raw[0], raw[1]};

		if (table.rank == card.rank || table.suit == card.suit) {
			result = true;
			break;
		}
	}

	printf("%s\n", result ? "YES" : "NO");

	return 0;
}
