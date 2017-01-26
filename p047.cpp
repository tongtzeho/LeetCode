class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        if (!len) return result;
        vector<int> addv(len);
        int i, j;
        int *a = new int[len];
        for (i = 0; i < len; i++)
        {
            a[i] = nums[i];
        }
        sort(a, a+len);
        while (true)
        {
            for (i = 0; i < len; i++)
            {
                addv[i] = a[i];
            }
            result.push_back(addv);
            for (i = len-1; i > 0; i--)
            {
                if (a[i-1] < a[i])
                {
                    for (j = i+1; j < len; j++)
                    {
                        if (a[j] <= a[i-1])
                        {
                            break;
                        }
                    }
                    j--;
                    a[i-1] ^= a[j];
                    a[j] ^= a[i-1];
                    a[i-1] ^= a[j];
                    for (j = i; j < (i+len)>>1; j++)
                    {
                        a[j] ^= a[i+len-1-j];
                        a[i+len-1-j] ^= a[j];
                        a[j] ^= a[i+len-1-j];
                    }
                    break;
                }
            }
            if (!i) break;
        }
        return result;
    }
};