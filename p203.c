/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode fakehead;
    fakehead.next = head;
    struct ListNode *prev = &fakehead, *cur = head;
    while (cur != NULL)
    {
        if (cur->val == val)
        {
            prev->next = cur->next;
            cur = prev->next;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return fakehead.next;
}
