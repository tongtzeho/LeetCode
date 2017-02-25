/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode *gettail(struct ListNode *head, int *size)
{
    (*size) = 0;
    struct ListNode *node = head;
    while (node->next != NULL)
    {
        node = node->next;
        (*size)++;
    }
    return node;
}

void reverse(struct ListNode *head)
{
    struct ListNode *node = head, *prev = NULL, *next;
    while (node != NULL)
    {
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
}

int count(struct ListNode *head)
{
    int result = 0;
    struct ListNode *node = head;
    while (node->next != NULL)
    {
        node = node->next;
        result++;
    }
    return result;
}

struct ListNode *visit(struct ListNode *head, int i)
{
    struct ListNode *node = head;
    while (i > 0)
    {
        node = node->next;
        i--;
    }
    return node;
}
 
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if ((!headA) || (!headB)) return NULL;
    int a_c = 0;
    int b_c = 0;
    struct ListNode *tail1 = gettail(headA, &a_c);
    struct ListNode *tail2 = gettail(headB, &b_c);
    if (tail1 != tail2)
    {
        return NULL;
    }
    reverse(headA);
    int b_a = count(headB);
    reverse(tail1);
    return visit(headA, (a_c-b_c+b_a) >> 1);
}