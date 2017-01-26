class Solution {
public:

    int findindex(int *a, int x, int l, int r)
    {
        while (r-l > 1)
        {
            int m = (l+r-1)>>1;
            if (a[m] >= x) r = m+1;
            else l = m+1;
        }
        return l;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        int length = nums.size();
        int *a = new int[length];
        int i, j;
        for (i = 0; i < length; i++)
        {
            a[i] = nums[i];
        }
        sort(a, a+length);
        unordered_map<int, int> h;
        int cnt = 0;
        cnt = 1;
        int len = 0;
        for (i = 1; i < length; i++)
        {
            if (a[i] == a[i-1]) cnt++;
            else
            {
                h[a[i-1]] = cnt;
                cnt = 1;
                a[len++] = a[i-1];
            }
        }
        h[a[length-1]] = cnt;
        a[len++] = a[length-1];
        int r = len;
        int l = 0;
        while (r-l > 1)
        {
            int m = (r+l-1)>>1;
            if (a[m] >= 0) r = m+1;
            else l = m+1;
        }
        int zeropos = l;
        int zpos = zeropos;
        if (a[zeropos] < 0) return result;
        vector<int> v(3);
        for (i = zeropos-1; i >= 0; i--)
        {
            int x = a[i];
            r = len;
            l = zpos;
            int findval = (-x+1)>>1;
            while (r-l > 1)
            {
                int m = (r+l-1)>>1;
                if (a[m] >= findval) r = m+1;
                else l = m+1;
            }
            zpos = l;
            if (a[zpos] >= findval)
            {
                for (j = zpos; j < len && a[j] <= (-x)<<1; j++)
                {
                    int z = a[j];
                    int y = -x-z;
                    if (h.find(y) != h.end())
                    {
                        if ((x == y || y == z) && h[y] < 2) continue;
                        v[0] = x;
                        v[1] = y;
                        v[2] = z;
                        result.push_back(v);
                    }
                }
            }
            else
            {
                break;
            }
        }
        if (a[zeropos] == 0 && h[0] >= 3)
        {
            v[0] = v[1] = v[2] = 0;
            result.push_back(v);
        }
        return result;
    }
};