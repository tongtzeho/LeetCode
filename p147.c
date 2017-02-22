/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head) return NULL;
    struct ListNode *prevtail = head, *tail = head->next, *nexttail, *prev, *node;
    while (tail != NULL)
    {
        if (tail->val < prevtail->val)
        {
            prev = NULL;
            node = head;
            while (node->val < tail->val)
            {
                prev = node;
                node = node->next;
            }
            nexttail = tail->next;
            prevtail->next = nexttail;
            tail->next = node;
            if (prev != NULL)
            {
                prev->next = tail;
            }
            else
            {
                head = tail;
            }
            tail = nexttail;
        }
        else
        {
            prevtail = tail;
            tail = tail->next;
        }
    }
    return head;
}
