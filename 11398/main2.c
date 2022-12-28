// version 2
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

int main () {
    uint32_t ans = 0, flag = 0, num_of_zero = 0;
    int input;
    bool not_end = true;

    while (not_end && (input = getchar()) != EOF) {
        switch (input) {
        case '~':
            // end of input
            not_end = false;
            break;
        case '#':
            // end of a number
            printf("%" PRIu32 "\n", ans);
            ans = 0;
            break;
        case ' ': case '\n': case '\t':
            // 確認剛剛遇到了幾個0
            if (num_of_zero == 0) break;
            switch (num_of_zero) {
            case 1:
                flag = 1;
                break;
            case 2:
                flag = 0;
                break;
            default:
                // append (num_of_zero - 2) flags after ans
                num_of_zero -= 2;
                while (num_of_zero--)
                    ans = (ans << 1) + flag;
                break;
            }
            num_of_zero = 0;
            break;
        default:
            num_of_zero++;
            break;
        }
    }  // 輸入結束
}
