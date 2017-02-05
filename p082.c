/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *tmphead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *cur, *next;
    tmphead->next = head;
    cur = tmphead;
    next = head;
    while (next != NULL)
    {
        if (next->next == NULL)
        {
            break;
        }
        else if (next->val != next->next->val)
        {
            cur = next;
            next = next->next;
        }
        else
        {
            while (true)
            {
                while (next->next != NULL && next->val == next->next->val)
                {
                    next = next->next;
                }
                if (next->next != NULL && next->next->next != NULL && next->next->val == next->next->next->val)
                {
                    next = next->next;
                }
                else
                {
                    break;
                }
            }
            cur->next = next->next;
            cur = cur->next;
            if (cur == NULL || cur->next == NULL) break;
            else next = cur->next;
        }
    }
    return tmphead->next;
}