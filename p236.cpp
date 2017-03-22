/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<TreeNode*> cur, vp, vq;

    void f(TreeNode *root, TreeNode *p ,TreeNode *q) {
        TreeNode *node = root, *prev;
        while (node != NULL)
        {
            if (node->left == NULL)
            {
                cur.push_back(node);
                if (node == p) vp = cur;
                if (node == q) vq = cur;
                node = node->right;
            }
            else
            {
                prev = node->left;
                while (prev->right != NULL && prev->right != node)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = node;
                    cur.push_back(node);
                    if (node == p) vp = cur;
                    if (node == q) vq = cur;
                    node = node->left;
                }
                else
                {
                    prev->right = NULL;
                    while (cur.back() != node->left)
                    {
                        cur.pop_back();
                    }
                    cur.pop_back();
                    node = node->right;
                }
            }
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        cur.clear();
        vp.clear();
        vq.clear();
        f(root, p, q);
        int i;
        TreeNode *result = NULL;
        for (i = 0; i < vp.size() && i < vq.size(); i++)
        {
            if (vp[i] == vq[i])
            {
                result = vp[i];
            }
            else
            {
                break;
            }
        }
        return result;
    }
};
