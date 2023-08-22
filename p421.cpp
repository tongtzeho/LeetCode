class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;

        constexpr int groupCount = 11;

        int mask[groupCount] = { 0, 0, 0, 0, 0 };
        int m = 0;
        for (int i = 30; i >= 0; --i)
        {
            bool first = nums[0] & (1 << i);
            for (size_t j = 0; j < nums.size(); ++j)
            {
                if ((bool)(nums[j] & (1 << i)) != first)
                {
                    mask[m] = i;
                    ++m;
                    break;
                }
            }
            if (m >= groupCount)
            {
                break;
            }
        }

        vector<int> groups[1 << groupCount];
        for (size_t j = 0; j < nums.size(); ++j)
        {
            int group = 0;
            for (int i = 0; i < m; ++i)
            {
                if (nums[j] & (1 << mask[i]))
                {
                    group |= 1 << (groupCount - 1 - i);
                }
            }
            groups[group].emplace_back(nums[j]);
        }

        int maskGroupXOR = 0;
        for (int i = 0; i < (1 << groupCount) / 2; ++i)
            for (int j = (1 << groupCount) / 2; j < (1 << groupCount); ++j)
            {
                if (!groups[i].empty() && !groups[j].empty())
                {
                    int xorRes = i ^ j;
                    if (xorRes > maskGroupXOR)
                        maskGroupXOR = xorRes;
                }
            }
        
        int res = 0;
        for (int i = 0; i < (1 << groupCount) / 2; ++i)
        {
            int anotherGroup = i ^ maskGroupXOR;
            for (size_t j = 0; j < groups[i].size(); ++j)
                for (size_t k = 0; k < groups[anotherGroup].size(); ++k)
                {
                    int xorRes = groups[i][j] ^ groups[anotherGroup][k];
                    if (xorRes > res)
                        res = xorRes;
                }
        }
        return res;
    }
};