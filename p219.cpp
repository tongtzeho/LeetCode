class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        unordered_map<int, int>::iterator iter;
        int size = nums.size();
        int i;
        for (i = 0; i < size; i++)
        {
            iter = dict.find(nums[i]);
            if (iter == dict.end())
            {
                dict.insert(pair<int, int>(nums[i], i));
            }
            else
            {
                if (i-iter->second <= k) return true;
                iter->second = i;
            }
        }
        return false;
    }
};
