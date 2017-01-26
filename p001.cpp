class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int i;
        for (i = 0; i < nums.size(); i++)
        {
            if (m.find(target-nums[i]) != m.end())
            {
                vector<int> result(2);
                result[0] = m[target-nums[i]];
                result[1] = i;
                return result;
            }
            else
            {
                m.insert(pair<int, int>(nums[i], i));
            }
        }
    }
};