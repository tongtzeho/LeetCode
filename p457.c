bool circularArrayLoop(int* nums, int numsSize) {
    if (numsSize == 0) return false;
    int i;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] >= numsSize) {
            nums[i] -= numsSize;
        } else if (nums[i] <= -numsSize) {
            nums[i] += numsSize;
        }
    }
    int fail = -numsSize;
    int j = 0;
    int nextj;
    bool positive;
    for (i = 0; i < numsSize; i++) {
        if (!nums[i]) {
            nums[i] = fail;
            fail--;
        } else if (nums[i] > -numsSize) {
            positive = nums[i] > 0;
            j = i;
            while (nums[j] > -numsSize && nums[j] != 0 && ((nums[j] < 0) ^ positive)) {
                nextj = j+nums[j];
                if (nextj >= numsSize) nextj -= numsSize;
                else if (nextj < 0) nextj += numsSize;
                nums[j] = fail;
                j = nextj;
            }
            if (!nums[j]) {
                nums[j] = fail;
                fail--;
            } else if (nums[j] == fail) {
                return true;
            } else {
                fail--;
            }
        }
    }
    return false;
}