/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
bool reverse(struct ListNode *head, int *size)
{
    *size = 0;
    struct ListNode *prev = NULL, *cur = head, *next;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        (*size)++;
    }
    (*size)--;
    bool temp = (prev == head);
    head = prev;
    return (*size) > 0 && temp;
}
 
struct ListNode *detectCycle(struct ListNode *head) {
    if (!head) return NULL;
    int size = 0;
    if (reverse(head, &size))
    {
        reverse(head, &size);
        int i;
        struct ListNode *node = head;
        for (i = 0; i < size; i++)
        {
            node = node->next;
        }
        int j = 0;
        struct ListNode *tmp = head;
        for (i = 0; i < size; i++)
        {
            if (tmp == node)
            {
                j = i;
            }
            tmp = tmp->next;
        }
        tmp = head;
        for (i = 0; i < (j>>1); i++)
        {
            tmp = tmp->next;
        }
        return tmp;
    }
    else
    {
        reverse(head, &size);
        return NULL;
    }
}