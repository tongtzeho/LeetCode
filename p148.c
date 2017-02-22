/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *prevtail;

struct ListNode *merge(const int sortedlength)
{
    struct ListNode *node1 = prevtail->next, *tail1;
    struct ListNode *node2 = node1, *tail2, *ret;
    int i;
    for (i = 0; i < sortedlength; i++)
    {
        node2 = node2->next;
        if (node2 == NULL)
        {
            prevtail = NULL;
            return node1;
        }
    }
    tail2 = tail1 = node2;
    for (i = 0; i < sortedlength && tail2 != NULL; i++)
    {
        tail2 = tail2->next;
    }
    if (node1->val <= node2->val) ret = node1;
    else ret = node2;
    while (node1 != tail1 || node2 != tail2)
    {
        if (node1 != tail1 && (node2 == tail2 || node1->val <= node2->val))
        {
            prevtail->next = node1;
            prevtail = node1;
            node1 = node1->next;
        }
        else
        {
            prevtail->next = node2;
            prevtail = node2;
            node2 = node2->next;
        }
    }
    prevtail->next = tail2;
    return ret;
}
 
struct ListNode* sortList(struct ListNode* head) {
    if (!head) return NULL;
    struct ListNode temphead;
    temphead.next = head;
    struct ListNode *temp = head;
    int i = 1;
    int size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    for (i = 1; i < size; i <<= 1)
    {
        prevtail = &temphead;
        while (prevtail != NULL && prevtail->next != NULL)
        {
            temp = prevtail;
            temp->next = merge(i);
        }
    }
    return temphead.next;
}
