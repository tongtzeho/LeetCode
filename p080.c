int removeDuplicates(int* nums, int numsSize) {
    int result = 0;
    int prevnum = 0;
    int cnt = 0;
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != prevnum || cnt == 0)
        {
            prevnum = nums[i];
            cnt = 1;
            nums[result++] = nums[i];
        }
        else
        {
            cnt++;
            if (cnt <= 2) nums[result++] = nums[i];
        }
    }
    return result;
}