int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize;
    int mid;
    while (right > left+1)
    {
        mid = (left+right) >> 1;
        if (nums[mid] < nums[left])
        {
            right = mid+1;
            if (nums[left+1] > nums[left]) left++;
            else return nums[left+1];
        }
        else
        {
            left = mid;
        }
    }
    if (left == numsSize || nums[0] < nums[left]) return nums[0];
    return nums[left];
}