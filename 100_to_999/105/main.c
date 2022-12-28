#include <stdio.h>
#include <inttypes.h>

// Format String for Li Hi Ri
#define FS4LHR "%" SCNu16 "%" SCNu32 "%" SCNu16

int main () {
    uint32_t height_arr[9998] = {0}, Hi = 0;
    uint16_t Li = 0, Ri = 0, max_Ri = 0; // 1 <= Li < Ri <= 9999

    while (scanf(FS4LHR, &Li, &Hi, &Ri) != EOF) {
        if (Ri > max_Ri)
            max_Ri = Ri;
        // 輸入後立即判斷每個位置的最大高度
        const uint16_t idx_end = Ri - 2;
        for (uint16_t idx = Li - 1; idx <= idx_end; ++idx) {
            if (Hi > height_arr[idx])
                height_arr[idx] = Hi;
        }
    }

    // print result
    printf("1");
    const uint16_t idx_end = max_Ri - 2;
    for (uint16_t idx = 1; idx <= idx_end; ++idx) {
        if (height_arr[idx] != height_arr[idx-1])
            printf(" %" PRIu32 " %" PRIu16, height_arr[idx-1], idx+1);
    }
    printf(" %" PRIu32 " %" PRIu16 " 0\n", height_arr[idx_end], max_Ri);
}
