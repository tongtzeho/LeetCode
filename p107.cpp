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
    vector<TreeNode*> v[2];

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) return result;
        v[0].push_back(root);
        int i, depth = 0;
        vector<int> addv;
        while (!v[depth&1].empty())
        {
            addv.clear();
            v[(depth+1)&1].clear();
            int size = v[depth&1].size();
            for (i = 0; i < size; i++)
            {
                if (v[depth&1][i]->left != NULL) v[(depth+1)&1].push_back(v[depth&1][i]->left);
                if (v[depth&1][i]->right != NULL) v[(depth+1)&1].push_back(v[depth&1][i]->right);
                addv.push_back(v[depth&1][i]->val);
            }
            depth++;
            result.push_back(addv);
        }
        for (i = 0; i < (depth>>1); i++)
        {
            addv = result[i];
            result[i] = result[depth-1-i];
            result[depth-1-i] = addv;
        }
        return result;
    }
};