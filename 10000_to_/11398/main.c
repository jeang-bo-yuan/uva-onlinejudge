#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#ifdef __cplusplus
typedef bool _Bool;
#endif

int main () {
    uint32_t ans = 0, flag = 0;
    char input[33] = ""; // max: 32個0
    _Bool not_end = 1;

    while (not_end) {
        if (scanf("%s", input) == EOF) return 1;
        switch (input[0]) {
        case '#':
            // end of a number
            printf("%" PRIu32 "\n", ans);
            ans = 0;
            break;
        case '~':
            // end of input
            not_end = 0;
            break;
        default:
            ; size_t len = strlen(input);
            switch (len) {
            case 1:
                flag = 1;
                break;
            case 2:
                flag = 0;
                break;
            default:
                // append (len - 2) flags behind ans
                len -= 2;
                while (len--) {
                    ans = (ans << 1) + flag;
                }
                break;
            }
            break;
        }  // end of switch(input[0])
    }  // end of while(not_end)
}
