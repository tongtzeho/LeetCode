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

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return result;
        vector<TreeNode*> v[2];
        v[0].push_back(root);
        int flag = 0;
        int i;
        while (!v[flag].empty())
        {
            int size = v[flag].size();
            vector<int> addv(size);
            v[1-flag].clear();
            for (i = 0; i < size; i++)
            {
                if (v[flag][i]->left != NULL) v[1-flag].push_back(v[flag][i]->left);
                if (v[flag][i]->right != NULL) v[1-flag].push_back(v[flag][i]->right);
                addv[i] = v[flag][i]->val;
            }
            result.push_back(addv);
            flag = 1-flag;
        }
        return result;
    }
};