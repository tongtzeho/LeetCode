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

    unordered_map<int, int> dict;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        if (!size) return NULL;
        int i;
        TreeNode *root = NULL;
        TreeNode **stack = new TreeNode*[size];
        int stacksize = 0;
        int *preindex = new int[size];
        for (i = 0; i < size; i++)
        {
            dict.insert(pair<int, int>(inorder[i], i));
            stack[i] = NULL;
        }
        for (i = 0; i < size; i++)
        {
            preindex[i] = dict[preorder[i]];
        }
        for (i = 0; i < size; i++)
        {
            while (stacksize > 0 && preindex[i] > stack[stacksize-1]->val)
            {
                stack[stacksize-1]->val = inorder[stack[stacksize-1]->val];
                stacksize--;
            }
            if (stacksize == 0)
            {
                if (root == NULL)
                {
                    root = new TreeNode(preindex[i]);
                    stack[stacksize++] = root;
                }
                else
                {
                    stack[stacksize]->right = new TreeNode(preindex[i]);
                    stack[stacksize] = stack[stacksize]->right;
                    stacksize++;
                }
            }
            else
            {
                if (stack[stacksize-1]->left == NULL)
                {
                    stack[stacksize-1]->left = new TreeNode(preindex[i]);
                    stack[stacksize] = stack[stacksize-1]->left;
                    stacksize++;
                }
                else
                {
                    stack[stacksize]->right = new TreeNode(preindex[i]);
                    stack[stacksize] = stack[stacksize]->right;
                    stacksize++;
                }
            }
        }
        while (stacksize > 0)
        {
            stack[stacksize-1]->val = inorder[stack[stacksize-1]->val];
            stacksize--;
        }
        return root;
    }
};