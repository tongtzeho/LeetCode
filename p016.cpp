class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int *a = new int[len];
        int i, j, maxlessthantarget, minlargerthantarget;
        for (i = 0; i < len; i++)
        {
            a[i] = nums[i];
        }
        sort(a, a+len);
        maxlessthantarget = a[0]+a[1]+a[2];
        minlargerthantarget = a[len-3]+a[len-2]+a[len-1];
        for (i = 0; i < len-2; i++)
        {
            if (a[i]+a[i+1]+a[i+2] > minlargerthantarget) break;
            for (j = i+1; j < len-1; j++)
            {
                if (a[i]+a[j]+a[j+1] > minlargerthantarget) break;
                int l = j+1, r = len-1, findval = target-a[i]-a[j];
                while (r > l)
                {
                    int m = (l+r)>>1;
                    if (a[m] == findval) return target;
                    if (a[m+1] < findval) l = m+1;
                    else if (a[m] > findval) r = m;
                    else if (a[m+1]-findval < findval-a[m])
                    {
                        l = m+1;
                        break;
                    }
                    else
                    {
                        l = m;
                        break;
                    }
                }
                if (a[l] == findval) return target;
                else if (a[l] < findval)
                {
                    if (a[i]+a[j]+a[l] > maxlessthantarget) maxlessthantarget = a[i]+a[j]+a[l];
                }
                else
                {
                    if (a[i]+a[j]+a[l] < minlargerthantarget) minlargerthantarget = a[i]+a[j]+a[l];
                }
            }
        }
        if (minlargerthantarget-target < target-maxlessthantarget) return minlargerthantarget;
        return maxlessthantarget;
    }
};