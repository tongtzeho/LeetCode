int findDuplicate(int* nums, int numsSize) {
    int left = 1;
    int right = numsSize;
    while (right > left)
    {
        int mid = (left+right) >> 1;
        int cur_cnt = 0;
        int i;
        for (i = 0; i < numsSize; i++)
        {
            if (nums[i] >= left && nums[i] <= mid)
            {
                cur_cnt++;
            }
        }
        if (cur_cnt > mid-left+1)
        {
            right = mid;
        }
        else
        {
            left = mid+1;
        }
    }
    return left;
}
