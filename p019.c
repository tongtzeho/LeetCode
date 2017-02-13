/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *rmprev = head, *iter = head;
    int size = 0;
    while (iter != NULL)
    {
        iter = iter->next;
        size++;
        if (size > n) break;
    }
    while (iter != NULL)
    {
        iter = iter->next;
        rmprev = rmprev->next;
    }    
    if (size > n) rmprev->next = rmprev->next->next;
    else head = head->next;
    return head;
}