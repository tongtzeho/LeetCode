class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = l1, *node = head, *l2head = l2;
        int add = 0;
        while (true)
        {
        	int d1 = 0;
        	int d2 = 0;
        	if (l1 != NULL) d1 = l1->val;
        	if (l2 != NULL) d2 = l2->val;
        	node->val = d1+d2+add;
        	if (node->val >= 10)
        	{
        		node->val -= 10;
        		add = 1;
			}
			else
			{
				add = 0;
			}
        	if (l1 != NULL) l1 = l1->next;
        	if (l2 != NULL) l2 = l2->next;
        	if (l1 == NULL && l2 == NULL)
        	{
        		if (add != 0)
        		{
        			if (node->next == NULL)
					{
					    node->next = l2head;
					}
					node->next->val = add;
					node->next->next = NULL;
				}
				else
				{
					node->next = NULL;
				}
        		return head;
			}
        	if (node->next == NULL) node->next = l2head;
        	node = node->next;
		}
		return head;
    }
};