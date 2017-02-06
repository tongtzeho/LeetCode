/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (m == n) return head;
    struct ListNode fakehead;
    fakehead.next = head;
    struct ListNode *insprev = &fakehead, *insnext = head, *prev = NULL, *cur = NULL;
    int cnt = 1;
    while (cnt < m)
    {
        cnt++;
        insprev = insnext;
        insnext = insnext->next;
    }
    prev = insnext;
    cur = insnext->next;
    while (cnt < n)
    {
        cnt++;
        prev->next = cur->next;
        insprev->next = cur;
        cur->next = insnext;
        insnext = cur;
        cur = prev->next;
    }
    return fakehead.next;
}