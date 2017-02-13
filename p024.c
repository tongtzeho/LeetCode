/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *result = head->next, *a = head, *b, *c, *d = a;
    while (a != NULL)
    {
        b = a->next;
        if (b == NULL) break;
        c = b->next;
        d->next = b;
        a->next = c;
        b->next = a;
        d = a;
        a = c;
    }
    return result;
}
