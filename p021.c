/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    struct ListNode *min, *max;
    if (l1->val < l2->val)
    {
        min = l1;
        max = l2;
    }
    else
    {
        min = l2;
        max = l1;
    }
    struct ListNode *head = min;
    while (max != NULL)
    {
        if (min->next == NULL)
        {
            min->next = max;
            break;
        }
        else
        {
            if (max->val < min->next->val)
            {
                struct ListNode *maxnext = max->next;
                max->next = min->next;
                min->next = max;
                min = max;
                max = maxnext;
            }
            else
            {
                min = min->next;
            }
        }
    }
    return head;
}