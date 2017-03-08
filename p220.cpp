class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0 || t < 0) return false;
        map<long long, int> mem;
        map<long long, int>::iterator iter, prev, next;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (i > k)
            {
                iter = mem.find(nums[i-k-1]);
                if (iter->second == i-k-1) mem.erase(iter);
            }
            iter = mem.find(nums[i]);
            if (iter != mem.end()) return true;
            prev = next = iter = mem.insert(pair<long long, int>(nums[i], i)).first;
            if (prev != mem.begin())
            {
                prev--;
                if (nums[i]-prev->first <= t) return true;
            }
            next++;
            if (next != mem.end() && next->first-nums[i] <= t)
            {
                return true;
            }
        }
        return false;
    }
};
