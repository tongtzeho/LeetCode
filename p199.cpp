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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return vector<int>();
        vector<TreeNode*> *oldv = new vector<TreeNode*>(1, root), *newv = new vector<TreeNode*>(), *tmpv;
        vector<int> result;
        int i;
        while (!oldv->empty())
        {
            result.push_back((*oldv)[0]->val);
            newv->clear();
            for (i = 0; i < oldv->size(); i++)
            {
                if ((*oldv)[i]->right != NULL) newv->push_back((*oldv)[i]->right);
                if ((*oldv)[i]->left != NULL) newv->push_back((*oldv)[i]->left);
            }
            tmpv = oldv;
            oldv = newv;
            newv = tmpv;
        }
        return result;
    }
};
