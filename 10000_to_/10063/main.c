#include <stdio.h>
#include <stdbool.h>

struct Node_t {
    char val;
    struct Node_t* next;
};

void permutation (char* charset, struct Node_t* list);

int main () {
    bool not_first = false;
    char charset[10] = {'\0'}; // at most: 9 chars + '\0'
    while (gets(charset) != NULL) {
        if (not_first) putchar('\n');
        permutation(charset, NULL);
        not_first = true;
    }
}

// 使用回溯法（backtracking）
// 每一層負責將一個node擺入linked list中
void permutation (char* charset, struct Node_t* list) {
    if (*charset == '\0') {  // 遞迴終止條件
        // print
        for (struct Node_t* p = list; p != NULL; p = p->next)
            putchar(p->val);
        putchar('\n');
        return;
    }

    struct Node_t node = {*charset, NULL};
    struct Node_t** indir = &list; // indicate where to insert node
    do {
        // insert node into list (after *indir)
        node.next = *indir;
        *indir = &node;
        // run recursion
        permutation(charset + 1, list);
        // remove node from list
        *indir = node.next;
    } while ( *indir != NULL && (indir = &((*indir)->next)) );
}
