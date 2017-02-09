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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        if (!size) return NULL;
        int i;
        TreeNode *root = NULL;
        TreeNode **stack = new TreeNode*[size];
        int stacksize = 0;
        int *postindex = new int[size];
        for (i = 0; i < size; i++)
        {
            dict.insert(pair<int, int>(inorder[i], i));
            stack[i] = NULL;
        }
        for (i = 0; i < size; i++)
        {
            postindex[i] = dict[postorder[i]];
        }
        for (i = size-1; i >= 0; i--)
        {
            while (stacksize > 0 && postindex[i] < stack[stacksize-1]->val)
            {
                stack[stacksize-1]->val = inorder[stack[stacksize-1]->val];
                stacksize--;
            }
            if (stacksize == 0)
            {
                if (root == NULL)
                {
                    root = new TreeNode(postindex[i]);
                    stack[stacksize++] = root;
                }
                else
                {
                    stack[stacksize]->left = new TreeNode(postindex[i]);
                    stack[stacksize] = stack[stacksize]->left;
                    stacksize++;
                }
            }
            else
            {
                if (stack[stacksize-1]->right == NULL)
                {
                    stack[stacksize-1]->right = new TreeNode(postindex[i]);
                    stack[stacksize] = stack[stacksize-1]->right;
                    stacksize++;
                }
                else
                {
                    stack[stacksize]->left = new TreeNode(postindex[i]);
                    stack[stacksize] = stack[stacksize]->left;
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