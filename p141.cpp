/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        struct ListNode *node = head;
        struct ListNode *next;
        while (true)
        {
            next = node->next;
            if (next == head)
            {
                return true;
            }
            else if (next == NULL)
            {
                return false;
            }
            node->next = head;
            node = next;
        }
        return false;        
    }
};