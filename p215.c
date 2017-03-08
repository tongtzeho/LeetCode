int findKthLargest(int* nums, int numsSize, int k) {
    int *left = (int*)malloc(sizeof(int)*numsSize);
    int *right = (int*)malloc(sizeof(int)*numsSize);
    int *temp;
    while (numsSize > 1)
    {
        int leftsize = 0;
        int rightsize = 0;
        int pivot = rand()%numsSize;
        int i;
        for (i = 0; i < numsSize; i++)
        {
            if (nums[i] < nums[pivot] || (nums[i] == nums[pivot] && i < pivot))
            {
                right[rightsize++] = nums[i];
            }
            else if (nums[i] > nums[pivot] || (nums[i] == nums[pivot] && i > pivot))
            {
                left[leftsize++] = nums[i];
            }
        }
        if (k == leftsize+1) return nums[pivot];
        else if (k <= leftsize)
        {
            temp = nums;
            nums = left;
            left = temp;
            numsSize = leftsize;
        }
        else
        {
            temp = nums;
            nums = right;
            right = temp;
            k -= (leftsize+1);
            numsSize = rightsize;
        }
    }
    return nums[0];
}
