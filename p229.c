/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int *result = (int*)malloc(sizeof(int)*2);
    int a = 0;
    int b = 0;
    int acnt = 0;
    int bcnt = 0;
    *returnSize = 0;
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if (acnt > 0 && nums[i] == a)
        {
            acnt++;
        }
        else if (bcnt > 0 && nums[i] == b)
        {
            bcnt++;
        }
        else if (acnt == 0)
        {
            a = nums[i];
            acnt++;
        }
        else if (bcnt == 0)
        {
            b = nums[i];
            bcnt++;
        }
        else
        {
            acnt--;
            bcnt--;
        }
    }
    if (acnt > 0)
    {
        acnt = 0;
        for (i = 0; i < numsSize; i++)
        {
            acnt += nums[i]==a;
        }
        if (acnt * 3 > numsSize)
        {
            result[(*returnSize)++] = a;
        }
    }
    if (bcnt > 0)
    {
        bcnt = 0;
        for (i = 0; i < numsSize; i++)
        {
            bcnt += nums[i]==b;
        }
        if (bcnt * 3 > numsSize)
        {
            result[(*returnSize)++] = b;
        }
    }
    return result;
}
