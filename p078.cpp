class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int arr[32];
        int arrsize = nums.size();
        int resultsize = (1<<arrsize);
        int i, j, k;
        for (i = 0; i < arrsize; i++)
        {
            arr[i] = nums[i];
        }
        vector<vector<int>> result(resultsize);
        for (i = 0; i < resultsize; i++)
        {
            j = i;
            k = 0;
            while (j > 0)
            {
                if (j&1) result[i].push_back(arr[k]);
                j >>= 1;
                k++;
            }
        }
        return result;
    }
};