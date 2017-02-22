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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode *node = root, *tmp;
        while (node != NULL)
        {
            if (node->left == NULL)
            {
                result.push_back(node->val);
                node = node->right;
            }
            else
            {
                tmp = node->left;
                while (tmp->right != NULL && tmp->right != node)
                {
                    tmp = tmp->right;
                }
                if (tmp->right == NULL)
                {
                    result.push_back(node->val);
                    tmp->right = node;
                    node = node->left;
                }
                else
                {
                    tmp->right = NULL;
                    node = node->right;
                }
            }
        }
        return result;
    }
};
