class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int *indegree = (int*)malloc(sizeof(int)*numCourses);
        int *in0 = (int*)malloc(sizeof(int)*numCourses);
        int in0num = 0;
        vector<int> *out = new vector<int>[numCourses];
        vector<int> result(numCourses, 0);
        int i, order = 0;
        for (i = 0; i < numCourses; i++)
        {
            indegree[i] = 0;
        }
        int size = prerequisites.size();
        for (i = 0; i < size; i++)
        {
            out[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]++;
        }
        for (i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                in0[in0num++] = i;
            }
        }
        while (in0num > 0)
        {
            numCourses--;
            int c = in0[--in0num];
            result[order++] = c;
            size = out[c].size();
            for (i = 0; i < size; i++)
            {
                indegree[out[c][i]]--;
                if (indegree[out[c][i]] == 0)
                {
                    in0[in0num++] = out[c][i];
                }
            }
        }
        if (numCourses == 0) return result;
        result.clear();
        return result;
    }
};
