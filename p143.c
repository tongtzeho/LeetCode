/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if (!head) return;
    int size = 0;
    struct ListNode *node = head, *prev, *next;
    while (node != NULL)
    {
        node = node->next;
        size++;
    }
    int i;
    prev = NULL;
    node = head;
    for (i = 0; i < (size+1)>>1; i++)
    {
        prev = node;
        node = node->next;
    }
    prev->next = NULL;
    prev = NULL;
    while (node != NULL)
    {
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    node = head;
    for (i = 0; i < size; i++)
    {
        if ((i&1) == 0)
        {
            next = node->next;
            node->next = prev;
            node = next;
        }
        else
        {
            next = prev->next;
            prev->next = node;
            prev = next;
        }
    }
}