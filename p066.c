/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i, j;
    for (i = digitsSize-1; i >= 0; i--)
    {
        if (digits[i] != 9)
        {
            digits[i]++;
            break;
        }
        digits[i] = 0;
    }
    if (i < 0)
    {
        *returnSize = digitsSize+1;
        int *result = (int*)malloc(sizeof(int)*(*returnSize));
        result[0] = 1;
        for (i = 1; i < *returnSize; i++)
        {
            result[i] = 0;
        }
        return result;
    }
    else
    {
        *returnSize = digitsSize;
        return digits;
    }
}