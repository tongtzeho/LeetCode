/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *prev = NULL, *cur = head, *next = head->next, *temp;
    while (next != NULL)
    {
        temp = next->next;
        next->next = cur;
        cur->next = prev;
        prev = cur;
        cur = next;
        next = temp;
    }
    cur->next = prev;
    return cur;
}
