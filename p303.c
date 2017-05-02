typedef struct {
    int *sum;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *result = (NumArray*)malloc(sizeof(NumArray));
    result->sum = (int*)malloc(sizeof(int)*numsSize);
    int i;
    result->sum[0] = nums[0];
    for (i = 1; i < numsSize; i++)
    {
        result->sum[i] = result->sum[i-1]+nums[i];
    }
    return result;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    if (i == 0)
    {
        return obj->sum[j];
    }
    else
    {
        return obj->sum[j]-obj->sum[i-1];
    }
}

void numArrayFree(NumArray* obj) {
    free(obj->sum);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */
