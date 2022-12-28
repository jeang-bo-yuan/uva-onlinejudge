#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
  int test_cases = 0;
  scanf("%d", &test_cases);
  while(test_cases--){
    /* initialize and input */
    int num = 0;
    scanf("%d", &num);
    int *address_arr = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; ++i){
      scanf("%d", address_arr + i);
    }

    /* sort arr -- insert sort */
    for (int i = 1; i < num; ++i){
      if (address_arr[i] > address_arr[i-1]) continue;
      int tmp = address_arr[i], insert_id = i;
      do{
        address_arr[insert_id] = address_arr[insert_id-1];
        --insert_id;
      } while (insert_id > 0 && tmp < address_arr[insert_id-1]);
      address_arr[insert_id] = tmp;
    }

#ifdef DEBUG
	for (int i=0; i<num; ++i){
		printf("%d ", address_arr[i]);
	}
	putchar('\n');
#endif

    /* produce output */
    int address_of_mid = address_arr[(num+1)/2-1]; /* midpoint of array */
    int dis_sum = 0;				 /* distance sum */
    for (int i = 0; i < num; ++i){
      dis_sum += abs(address_arr[i] - address_of_mid);
    }
    printf("%d\n", dis_sum);

    free(address_arr);
  }
}
