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

    vector<int> v;
    vector<string> result;

    void f(TreeNode *node) {
        v.push_back(node->val);
        if (node->left == NULL && node->right == NULL)
        {
            stringstream ss;
            ss << v[0];
            int i;
            for (i = 1; i < v.size(); i++)
            {
                ss << "->" << v[i];
            }
            string str;
            result.push_back(str);
            ss >> result[result.size()-1];
            v.pop_back();
            return;
        }
        if (node->left != NULL)
        {
            f(node->left);
            if (node->right != NULL)
            {
                f(node->right);
            }
        }
        else
        {
            f(node->right);
        }
        v.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return vector<string>();
        v.clear();
        v.reserve(200);
        result.clear();
        result.reserve(1000);
        f(root);
        return result;
    }
};
