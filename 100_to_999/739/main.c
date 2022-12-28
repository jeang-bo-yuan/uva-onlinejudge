#include <stdio.h>
#include <string.h>

char buf[BUFSIZ] = {'\0'};
char encode(char);

int main() {
	setbuf(stdout, buf);
	printf("         %-25s%s\n", "NAME", "SOUNDEX CODE");

	char name[21] = {'\0'};
	while (scanf("%20s", name) != EOF) {  // for each line of input
		printf("         %-25s%c", name, name[0]);

		// parse the numeric part of "soundex code"
		char prev_code = encode(name[0]), cur_code = '0';
		short still_need = 3;
		for (char *p = name + 1; still_need && *p; ++p) {
			cur_code = encode(*p);
			if (cur_code != '0' && cur_code != prev_code) {
				--still_need;
				putchar(cur_code);
			}
			prev_code = cur_code;
		}
		// print 0s
		while (still_need--) putchar('0');

		putchar('\n');
	}

	printf("%32s\n", "END OF OUTPUT");

	fflush(stdout);
}

/* function definition */
char encode(char c) {
	if (strchr("AEIOUYWH", c))
		return '0';
	else if (strchr("BPFV", c))
		return '1';
	else if (strchr("CSKGJQXZ", c))
		return '2';
	else if (strchr("DT", c))
		return '3';
	else if (c == 'L')
		return '4';
	else if (strchr("MN", c))
		return '5';
	else
		return '6';
}
