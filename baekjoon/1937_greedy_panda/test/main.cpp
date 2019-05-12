#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

const int MAX = 1000000;
const int N = 8;

int main() {
	srand(time(NULL));

	for (int k = 1; k <= 10; k++) {
		FILE *pt;
		char fileName[100];
		sprintf(fileName, "in_%02d.txt", k);
		pt = fopen(fileName, "w");

		if (pt == NULL) continue;

		//printf("%d\n", N);
		fprintf(pt, "%d\n", N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int value = rand() % 50 + 1;
				//printf("%d ", value);
				fprintf(pt, "%d ", value);
			}
			//printf("\n");
			fprintf(pt, "\n");
		}

		fclose(pt);
	}


	return 0;
}
