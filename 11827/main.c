#include <stdio.h>
#include <stdint.h>

// erase spaces from stdin, return 1 if encounter '\n' or EOF, or 0 otherwise
// NOTE: It may use ungetc()
_Bool is_the_last(void) {
	int c = 0;
	while ((c = getchar()) != EOF) {
		switch (c) {
		case '\n':
			return 1;
		case ' ': case '\t':
			continue;
		default:
			ungetc(c, stdin);
			return 0;
		}
	}
	return 1;
}

// Return the GCD of a and b
uint32_t gcd(uint32_t a, uint32_t b) {
	uint32_t tmp;
	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

//
int main() {
	uint16_t N = 0, num_arr_len = 0;
	uint32_t num_arr[99] = {0};

	scanf("%hu", &N);
	getchar();  //clear newline character
	while (N--) {  //for N test cases
		num_arr_len = 0;
		do {
			scanf("%u", num_arr + (num_arr_len++));
		} while (!is_the_last());  //input each number until encountering EOL

		uint32_t max_gcd = 0, tmp = 0;
		for (uint16_t a_id = 0; a_id < num_arr_len; ++a_id) {
			for (uint16_t b_id = a_id + 1; b_id < num_arr_len; ++b_id) {
				tmp = gcd(num_arr[a_id], num_arr[b_id]);
				max_gcd = (tmp > max_gcd ? tmp : max_gcd);
			}
		}
		printf("%u\n", max_gcd);
	}
}
