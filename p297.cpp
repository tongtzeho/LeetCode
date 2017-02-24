/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string int2str(int x) {
        char result[13];
        sprintf (result, " %d", x);
        return result;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "null";
        string result = int2str(root->val);
        vector<TreeNode*> *oldarr = new vector<TreeNode*>, *newarr = new vector<TreeNode*>, *temp;
        oldarr->push_back(root);
        int i;
        while (!oldarr->empty())
        {
            newarr->clear();
            int size = oldarr->size();
            for (i = 0; i < size; i++)
            {
                if ((*oldarr)[i]->left != NULL)
                {
                    result += int2str((*oldarr)[i]->left->val);
                    newarr->push_back((*oldarr)[i]->left);
                }
                else
                {
                    result += " null";
                }
                if ((*oldarr)[i]->right != NULL)
                {
                    result += int2str((*oldarr)[i]->right->val);
                    newarr->push_back((*oldarr)[i]->right);
                }
                else
                {
                    result += " null";
                }
            }
            temp = oldarr;
            oldarr = newarr;
            newarr = temp;
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null") return NULL;
        stringstream ss;
        ss << data;
        TreeNode *root;
        vector<TreeNode*> *oldarr = new vector<TreeNode*>, *newarr = new vector<TreeNode*>, *temp;
        string cur;
        ss >> cur;
        root = new TreeNode(atoi(cur.c_str()));
        oldarr->push_back(root);
        int i;
        while (!oldarr->empty())
        {
            newarr->clear();
            int size = oldarr->size();
            for (i = 0; i < size; i++)
            {
                ss >> cur;
                if (cur != "null")
                {
                    (*oldarr)[i]->left = new TreeNode(atoi(cur.c_str()));
                    newarr->push_back((*oldarr)[i]->left);
                }
                ss >> cur;
                if (cur != "null")
                {
                    (*oldarr)[i]->right = new TreeNode(atoi(cur.c_str()));
                    newarr->push_back((*oldarr)[i]->right);
                }
            }
            temp = oldarr;
            oldarr = newarr;
            newarr = temp;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));