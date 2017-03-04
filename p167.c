/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *result = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
    int i, j = numbersSize-1;
    for (i = 0; i < numbersSize; i++)
    {
        while (numbers[i]+numbers[j] > target && i < j)
        {
            j--;
        }
        if (numbers[i]+numbers[j] == target && i < j)
        {
            result[0] = i+1;
            result[1] = j+1;
            return result;
        }
        else if (numbers[i]+numbers[j] < target && j < numbersSize-1)
        {
            j++;
        }
    }
    return result;
}