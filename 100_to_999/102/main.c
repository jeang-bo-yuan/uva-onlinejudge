#include <stdio.h>

enum color_t { brown = 0, green, clear };

// enumerate all possible methods
const char methods[6][4] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

// count numbers of movements based on specific method
unsigned count(const char* method, const unsigned bin_color[][3]);

int main() {
	// bin_color[i] -> i-th bin
	// bin_color[i][brown] -> brown colors in i-th bin
	unsigned bin_color[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

	while (scanf("%u", &bin_color[0][0]) != EOF) {
		// enter the other 8 numbers
		for (short i = 1; i <= 8; ++i) {
			scanf("%u", (*bin_color) + i);
		}

		// try first method
		unsigned min = count(methods[0], bin_color);
		const char* best_method = methods[0];
		// try all methods and compare with the current minimum
		for (short i = 1; i <= 5; ++i) {
			unsigned tmp = count(methods[i], bin_color);
			if (tmp < min) {
				min = tmp;
				best_method = methods[i];
			}
		}

		printf("%s %u\n", best_method, min);
	}
}


unsigned count(const char* method, const unsigned bin_color[][3]) {
	unsigned res = 0;
	for (short i = 0; i < 3; ++i) {  // iterate all color
		enum color_t color = (method[i] == 'B' ? brown :
		                      method[i] == 'G' ? green : clear);
		res += bin_color[(i+1)%3][color] + bin_color[(i+2)%3][color];
	}
	return res;
}
