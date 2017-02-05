/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *prevtail = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *tmphead = prevtail;
    prevtail->next = head;
    struct ListNode *pivottail = head;
    while (pivottail != NULL && pivottail->val < x)
    {
        pivottail = pivottail->next;
        prevtail = prevtail->next;
    }
    if (pivottail == NULL) return head;
    struct ListNode *cur = pivottail->next;
    struct ListNode *prev = pivottail;
    while (cur != NULL)
    {
        if (cur->val < x)
        {
            prevtail->next = cur;
            prev->next = cur->next;
            cur->next = pivottail;
            prevtail = cur;
            cur = prev->next;
        }
        else
        {
            cur = cur->next;
            prev = prev->next;
        }
    }
    cur = tmphead->next;
    return tmphead->next;
}