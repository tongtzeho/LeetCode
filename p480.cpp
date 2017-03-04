class Solution {
public:

    multiset<int, less<int> > big;
    multiset<int, greater<int> > small;
    
    double add(int val)
    {
        if (small.empty())
        {
            small.insert(val);
            return val;
        }
        else if (small.size() == big.size())
        {
            if (val > *(big.begin()))
            {
                small.insert(*(big.begin()));
                big.erase(big.begin());
                big.insert(val);
            }
            else
            {
                small.insert(val);
            }
            return *(small.begin());
        }
        else
        {
            if (val < *(small.begin()))
            {
                big.insert(*(small.begin()));
                small.erase(small.begin());
                small.insert(val);
            }
            else
            {
                big.insert(val);
            }
            return 0.5*(*(small.begin()))+0.5*(*(big.begin()));
        }
    }
    
    void rm(int val)
    {
        if (small.size() == big.size())
        {
            if (val >= *(big.begin()))
            {
                big.erase(big.find(val));
            }
            else
            {
                small.erase(small.find(val));
                small.insert(*(big.begin()));
                big.erase(big.begin());
            }
        }
        else
        {
            if (val <= *(small.begin()))
            {
                small.erase(small.find(val));
            }
            else
            {
                big.erase(big.find(val));
                big.insert(*(small.begin()));
                small.erase(small.begin());
            }
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<double> result(size-k+1, 0);
        big.clear();
        small.clear();
        int i;
        for (i = 0; i < k-1; i++)
        {
            add(nums[i]);
        }
        for (i = k-1; i < size-1; i++)
        {
            result[i-k+1] = add(nums[i]);
            rm(nums[i-k+1]);
        }
        result[i-k+1] = add(nums[i]);
        return result;
    }
};