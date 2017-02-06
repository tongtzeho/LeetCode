class Solution {
public:
    unordered_map<int, int> dict;
    vector<vector<int>> result;
    
    void f(int *cur, int cursize, unordered_map<int, int>::iterator iter)
    {
        if (iter == dict.end())
        {
            vector<int> addv(cursize);
            for (int i = 0; i < cursize; i++)
            {
                addv[i] = cur[i];
            }
            result.push_back(addv);
            return;
        }
        int i;
        int val = iter->first;
        unordered_map<int, int>::iterator jter = iter;
        jter++;
        f(cur, cursize, jter);
        for (i = 0; i < iter->second; i++)
        {
            cur[cursize++] = iter->first;
            f(cur, cursize, jter);
        }
        cursize -= iter->second;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int i;
        int size = nums.size();
        int val;
        unordered_map<int, int>::iterator iter;
        for (i = 0; i < size; i++)
        {
            val = nums[i];
            iter = dict.find(val);
            if (iter == dict.end())
            {
                dict.insert(pair<int, int>(val, 1));
            }
            else
            {
                iter->second++;
            }
        }
        int *tmp = new int[size];
        iter = dict.begin();
        f(tmp, 0, iter);
        return result;
    }
};