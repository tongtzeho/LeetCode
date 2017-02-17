/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<RandomListNode*, RandomListNode*> f;

    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode *result = new RandomListNode(head->label), *node = head, *curnode;
        f.insert(pair<RandomListNode*, RandomListNode*>(head, result));
        for (node = head; node != NULL; node = node->next)
        {
            curnode = f[node];
            curnode->label = node->label;
            if (node->random != NULL)
            {
                if (f.find(node->random) == f.end())
                {
                    curnode->random = new RandomListNode(node->random->label);
                    f.insert(pair<RandomListNode*, RandomListNode*>(node->random, curnode->random));
                }
                else
                {
                    curnode->random = f[node->random];
                }
            }
            if (node->next != NULL)
            {
                if (f.find(node->next) == f.end())
                {
                    curnode->next = new RandomListNode(node->next->label);
                    f.insert(pair<RandomListNode*, RandomListNode*>(node->next, curnode->next));
                }
                else
                {
                    curnode->next = f[node->next];
                }
            }
        }
        return result;
    }
};
