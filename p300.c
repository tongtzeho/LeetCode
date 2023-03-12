int lengthOfLIS(int* nums, int numsSize){
    short arr[2503] = { 0, nums[0], 0 };
    short res = 1;
    int* numEnd = nums + numsSize;
    for (int* p = nums + 1; p != numEnd; ++p)
    {
        short val = (short)(*p);
        short count = res;
        short found = 1;
        while (count > 0)
        {
            short it = found; 
            short step = count / 2; 
            it += step;
            if (arr[it] < val)
            {
                found = ++it; 
                count -= step + 1; 
            }
            else
                count = step;
        }
        if (found > res)
        {
            arr[++res] = val;
        }
        else if (val < arr[found])
        {
            arr[found] = val;
        }
    }
    return res;
}