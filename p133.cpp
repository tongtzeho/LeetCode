/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:

    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> f;
    
    UndirectedGraphNode *dfs(UndirectedGraphNode *node) {
        UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
        f.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(node, ret));
        int size = node->neighbors.size();
        int i;
        for (i = 0; i < size; i++)
        {
            if (f.find(node->neighbors[i]) != f.end())
            {
                ret->neighbors.push_back(f[node->neighbors[i]]);
            }
            else
            {
                ret->neighbors.push_back(dfs(node->neighbors[i]));
            }
        }
        return ret;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        f.clear();
        return dfs(node);
    }
};
