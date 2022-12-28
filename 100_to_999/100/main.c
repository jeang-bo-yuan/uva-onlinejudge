#include <stdio.h>

/* return the cycle_length of num */
unsigned cyc_len(unsigned num){
  unsigned len = 1;
  while (num != 1) {
    num = (num & 1 ? 3*num+1 : num/2);
    ++len;
  }
  return len;
}

int main(){
  char buf[BUFSIZ] = {'\0'};
  setbuf(stdout, buf);
  
  unsigned i = 1, j = 1;
  while (scanf("%u %u", &i, &j) != EOF) {
    printf("%u %u ", i, j);
    if (i > j){
      /* swap */
      unsigned tmp = i;
      i = j;
      j = tmp;
    }

    /* iterate and find max cycle_length */
    unsigned max_cyc_len = 0, tmp = 0;
    for (unsigned num = i; num <= j; ++num){
      tmp = cyc_len(num);
      max_cyc_len = (tmp > max_cyc_len ? tmp : max_cyc_len);
    }
    printf("%u\n", max_cyc_len);
  }
  fflush(stdout);
}
