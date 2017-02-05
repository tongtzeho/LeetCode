/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return head;
    struct ListNode *cur = head, *next = head->next;
    while (next != NULL)
    {
        while (next != NULL && cur->val == next->val)
        {
            next = next->next;
        }
        cur->next = next;
        cur = next;
        if (next != NULL) next = next->next;
        else break;
    }
    return head;
}