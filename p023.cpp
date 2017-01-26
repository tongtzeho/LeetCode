/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct cmp {
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val < b->val;
    }
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<ListNode*, cmp> ms;
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        vector<ListNode*>::iterator iter;
        for (iter = lists.begin(); iter != lists.end(); iter++)
        {
            if (*iter != NULL)
            {
                ms.insert(*iter);
            }
        }
        while (!ms.empty())
        {
            ListNode *tmp = *ms.begin();
            ms.erase(ms.begin());
            cur->next = tmp;
            if (tmp->next != NULL)
            {
                ms.insert(tmp->next);
            }
            cur = tmp;
        }
        return head->next;
    }
};