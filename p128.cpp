class Solution {
public:

    unordered_set<int> existval;
    unordered_map<int, int> mintomax, maxtomin;
    unordered_map<int, int>::iterator iter, jter;

    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        int i;
        int size = nums.size();
        int val;
        int tmp;
        for (i = 0; i < size; i++)
        {
            val = nums[i];
            if (existval.find(val) == existval.end())
            {
                existval.insert(val);
                iter = mintomax.find(val+1);
                jter = maxtomin.find(val-1);
                if (iter == mintomax.end() && jter == maxtomin.end())
                {
                    tmp = 1;
                    mintomax.insert(pair<int, int>(val, val));
                    maxtomin.insert(pair<int, int>(val, val));
                }
                else if (iter != mintomax.end())
                {
                    if (jter == maxtomin.end())
                    {
                        tmp = iter->second-val+1;
                        mintomax.insert(pair<int, int>(val, iter->second));
                        maxtomin[iter->second] = val;
                        mintomax.erase(iter);
                    }
                    else
                    {
                        tmp = iter->second-jter->second+1;
                        mintomax[jter->second] = iter->second;
                        maxtomin[iter->second] = jter->second;
                        mintomax.erase(iter);
                        maxtomin.erase(jter);
                    }
                }
                else
                {
                    tmp = val-jter->second+1;
                    maxtomin.insert(pair<int, int>(val, jter->second));
                    mintomax[jter->second] = val;
                    maxtomin.erase(jter);
                }
                if (tmp > result)
                {
                    result = tmp;
                }
            }
        }
        return result;
    }
};