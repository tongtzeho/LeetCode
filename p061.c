/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !k) return head;
    struct ListNode *node = head;
    unsigned size = 1;
    while (node->next != NULL)
    {
        node = node->next;
        size++;
    }
    k %= size;
    if (!k) return head;
    node->next = head;
    node = head;
    while (size > k+1)
    {
        node = node->next;
        size--;
    }
    head = node->next;
    node->next = NULL;
    return head;
}