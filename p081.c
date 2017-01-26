bool search(int* nums, int numsSize, int target) {
    int i, j;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == target) return true;
        else if (nums[i] > target) break;
    }
    for (j = numsSize-1; j > i; j--)
    {
        if (nums[j] == target) return true;
        else if (nums[j] < target) break;
    }
    return false;
}