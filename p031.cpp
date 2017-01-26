class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return;
        int i, j;
        for (i = len-2; i >= 0; i--)
        {
            if (nums[i] < nums[i+1]) break;
        }
        if (i < 0)
        {
            for (i = 0; i < len>>1; i++)
            {
                nums[i] ^= nums[len-1-i];
                nums[len-1-i] ^= nums[i];
                nums[i] ^= nums[len-1-i];
            }
        }
        else
        {
            int m = len-1;
            for (j = i+1; j < (len+i+1)>>1; j++)
            {
                int k = len+i-j;
                nums[j] ^= nums[k];
                nums[k] ^= nums[j];
                nums[j] ^= nums[k];
                if (nums[j] > nums[i] && j < m) m = j;
                else if (nums[k] > nums[i] && k < m) m = k;
            }
            if (nums[j] > nums[i] && j < m) m = j;
            nums[i] ^= nums[m];
            nums[m] ^= nums[i];
            nums[i] ^= nums[m];
        }
    }
};