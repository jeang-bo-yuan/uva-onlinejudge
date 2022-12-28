#include <stdio.h>

int main(){
	unsigned num1, num2;
	while(scanf("%u %u", &num1, &num2) != EOF){
		if (num1 == num2 && num1 == 0) return 0;

		// count
		short count = 0; // count the times of "carry" operations
		short carry = 0; // the num to be carried to next pos
		while (num1 != 0 || num2 != 0){
			if ((num1%10 + num2%10 + carry) > 9){
				++count;
				carry = 1;
			}else{
				carry = 0;
			}
			num1 /= 10;
			num2 /= 10;
		}
		
		//print
		switch (count){
		case 0:
			puts("No carry operation.");
			break;
		case 1:
			puts("1 carry operation.");
			break;
		default:
			printf("%hd carry operations.\n", count);
			break;
		}
	}

}