/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if (!numsSize) return NULL;
    char **result = (char**)malloc(sizeof(char*)*numsSize);
    *returnSize = 0;
    int i;
    int start = 0;
    int end = 0;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i-1]+1) {
            end++;
        } else {
            result[*returnSize] = (char*)malloc(sizeof(char)*30);
            if (start == end) sprintf (result[(*returnSize)++], "%d", nums[start]);
            else sprintf (result[(*returnSize)++], "%d->%d", nums[start], nums[end]);
            start = end = i;
        }
    }
    result[*returnSize] = (char*)malloc(sizeof(char)*30);
    if (start == end) sprintf (result[(*returnSize)++], "%d", nums[start]);
    else sprintf (result[(*returnSize)++], "%d->%d", nums[start], nums[end]);
    return result;
}
    
