/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (!k)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = numsSize-k+1;
    int *mem = (int*)malloc(sizeof(int)*numsSize);
    int i;
    int membegin = 0, memend = 1;
    mem[0] = nums[0];
    for (i = 1; i < k; i++)
    {
        while (memend > membegin && nums[i] > mem[memend-1])
        {
            memend--;
        }
        mem[memend++] = nums[i];
    }
    for (i = k; i < numsSize; i++)
    {
        if (nums[i-k] == mem[membegin])
        {
            membegin++;
        }
        else
        {
            nums[i-k] = mem[membegin];
        }
        while (memend > membegin && nums[i] > mem[memend-1])
        {
            memend--;
        }
        mem[memend++] = nums[i];
    }
    nums[i-k] = mem[membegin];
    return nums;
}