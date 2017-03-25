/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    if (node == NULL) return;
    else if (node->next == NULL)
    {
        node = NULL;
    }
    else
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
}