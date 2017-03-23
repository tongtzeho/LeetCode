/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int cnt = 0;
    struct ListNode *node = head;
    while (node != NULL)
    {
        cnt++;
        node = node->next;
    }
    struct ListNode *prev = NULL, *cur = head, *next;
    int i;
    for (i = 0; i < cnt>>1; i++)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    if (cnt&1) cur = cur->next;
    while (cur != NULL && cur->val == prev->val)
    {
        cur = cur->next;
        prev = prev->next;
    }
    return cur == NULL;
}
