/* library for dynamic one-way list */

typedef struct ListNode {
    long long int value;
    struct ListNode *next;
} ListNode;

int pushBack(ListNode**, long long int);
// 0.error report 1.list 2.value to add

int listDelete(ListNode**, long long int);
// 0. "1" if delete "0" if nothing found 1.list 2.value to delete

ListNode *listSearch(ListNode*, long long int);
// 0.pointer or NULL if nothing found 1.list 2.value to find

void listShow(ListNode*);