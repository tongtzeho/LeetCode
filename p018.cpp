class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int len = nums.size();
        if (len <= 3) return result;
        vector<int> addv(4);
        int *a = new int[len];
        int i, j, k;
        for (i = 0; i < len; i++)
        {
            a[i] = nums[i];
        }
        sort(a, a+len);
        unordered_map<int, int> hp;
        for (i = 0; i < len; i++)
        {
            if (i > 0 && a[i] == a[i-1]) hp[a[i]]++;
            else hp[a[i]] = 1;
        }
        int memleftj = len-3;
        for (i = 0; i < len-3; i++)
        {
            if (i > 0 && a[i] == a[i-1]) continue;
            int x1 = a[i];
            int rightj = memleftj;
            int leftj = i+1;
            int findvalj = target-x1-a[len-2]-a[len-1];
            while (rightj > leftj)
            {
                int mid = (leftj+rightj)>>1;
                if (a[mid] >= findvalj) rightj = mid;
                else leftj = mid+1;
            }
            memleftj = leftj;
            if (x1+a[leftj]+a[len-2]+a[len-1] < target) continue;
            int memleft = len-2;
            for (j = leftj; j < len-2; j++)
            {
                if (j > i+1 && a[j] == a[j-1]) continue;
                int x2 = a[j];
                int right = memleft;
                int left = j+1;
                int findval = target-x1-x2-a[len-1];
                while (right > left)
                {
                    int mid = (left+right)>>1;
                    if (a[mid] >= findval) right = mid;
                    else left = mid+1;
                }
                memleft = left;
                if (x1+x2+a[left]+a[len-1] < target) continue;
                for (k = left; k < len-1; k++)
                {
                    if (k > j+1 && a[k] == a[k-1]) continue;
                    int x3 = a[k];
                    int findval = target-x1-x2-x3;
                    if (findval < x3) break;
                    if (hp.find(findval) != hp.end())
                    {
                        if (x1 == x2)
                        {
                            if (x2 == x3)
                            {
                                if (x3 == findval && hp[x1] < 4) continue;
                                else if (hp[x1] < 3) continue;
                            }
                            else
                            {
                                if (hp[x1] < 2) continue;
                                if (x3 == findval && hp[x3] < 2) continue;
                            }
                        }
                        else if (x2 == x3)
                        {
                            if (x3 == findval && hp[x2] < 3) continue;
                            else if (hp[x2] < 2) continue;
                        }
                        else if (x3 == findval && hp[x3] < 2) continue;
                        addv[0] = x1;
                        addv[1] = x2;
                        addv[2] = x3;
                        addv[3] = findval;
                        result.push_back(addv);
                    }
                }
            }
        }
        return result;
    }
};