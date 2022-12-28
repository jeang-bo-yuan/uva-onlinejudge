#include <stdio.h>

int main(){
	unsigned long n1 = 0, n2 = 0;
	while (scanf("%lu %lu", &n1, &n2) != EOF)
		printf("%lu\n", (n1>n2 ? n1-n2 : n2-n1));
	return 0;
}
