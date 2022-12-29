#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void permutation (const char* charset, char* output);

int main () {
    bool not_first = false;
    char charset[10] = {'\0'}; // at most: 9 chars + '\0'
    char output[10] = {'\0'};
    while (gets(charset) != NULL) {
        if (not_first) putchar('\n');
        permutation(charset, output);
        not_first = true;
    }
}

// 使用回溯法（backtracking）
// 每一層負責將一個字元擺入output中
void permutation (const char* charset /*一個陣列，其中第一個字元為負責的字元*/, char* output) {
    if (charset[0] == '\0') {  // 遞迴終止條件
        // print
        puts(output);
        return;
    }

    // 將output中的字元向右移
    for (size_t i = strlen(output); i > 0; --i) {
        output[i] = output[i - 1];
    }
    // 先放在最左邊
    output[0] = charset[0];
    // 由左至右，依序嘗試每個位置
    const size_t len = strlen(output);
    for (size_t i = 0; i < len; ++i) { // i從 0 到 strlen(output)-1
        permutation(charset + 1, output);
        // 若負責的字元不在最右邊，則向右移
        if (i != len - 1) {
            // swap output[i], output[i+1]
            char tmp = output[i];
            output[i] = output[i + 1];
            output[i + 1] = tmp;
        }
    }

    // 已嘗試所有可能，準備回溯
    // 將output回復原狀
    output[len - 1] = '\0';
    // 回溯
    return;
}
