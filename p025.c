/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k == 1) return head;
    int cnt = 0;
    struct ListNode *prevtail = NULL, *curtail = head, *oldhead = head, *newhead = head->next;
    struct ListNode *result = head, *memoldhead = oldhead, *curtailnext = curtail->next;
    while (true)
    {
        if (curtail != NULL)
        {
            cnt++;
            if (cnt == k)
            {
                memoldhead = oldhead;
                curtailnext = curtail->next;
                while (oldhead != curtail)
                {
                    if (prevtail != NULL) prevtail->next = newhead;
                    oldhead->next = curtail->next;
                    curtail->next = oldhead;
                    oldhead = newhead;
                    newhead = newhead->next;
                }
                if (result == head) result = curtail;
                prevtail = memoldhead;
                curtail = oldhead = curtailnext;
                if (oldhead != NULL) newhead = oldhead->next;
                cnt = 0;
            }
            else
            {
                curtail = curtail->next;
            }
        }
        else
        {
            break;
        }
    }
    return result;    
}