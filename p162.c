int findPeakElement(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize;
    int mid;
    while (right > left+2)
    {
        mid = (left+right)>>1;
        if (nums[mid] > nums[mid+1])
        {
            right = mid+1;
        }
        else
        {
            left = mid;
        }
    }
    if (nums[left] > nums[right-1]) return left;
    return right-1;
}