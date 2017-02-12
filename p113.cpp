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

    vector<vector<int>> result;
    int *cur;
    int cursize;
    int cursum;

    void f(TreeNode *root, int sum) {
        cur[cursize++] = root->val;
        cursum += root->val;
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == cursum)
            {
                vector<int> addv(cursize);
                for (int i = 0; i < cursize; i++)
                    addv[i] = cur[i];
                result.push_back(addv);
            }
        }
        else
        {
            if (root->left != NULL)
            {
                f(root->left, sum);
                if (root->right != NULL) f(root->right, sum);
            }
            else f(root->right, sum);
        }
        cursize--;
        cursum -= root->val;
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return result;
        cursum = 0;
        cursize = 0;
        cur = new int[20000];
        f(root, sum);
        return result;
    }
};