/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    bool *mem = (bool*)malloc(sizeof(bool)*intervalsSize);
    *returnSize = 0;
    int i;
    for (i = 0; i < intervalsSize; i++)
    {
        if (intervals[i].start > newInterval.end || newInterval.start > intervals[i].end)
        {
            mem[i] = true;
            (*returnSize)++;
        }
        else
        {
            mem[i] = false;
            if (intervals[i].start < newInterval.start) newInterval.start = intervals[i].start;
            if (intervals[i].end > newInterval.end) newInterval.end = intervals[i].end;
        }
    }
    (*returnSize)++;
    struct Interval *result = (struct Interval*)malloc(sizeof(struct Interval)*(*returnSize));
    *returnSize = 0;
    bool ins = false;
    for (i = 0; i < intervalsSize; i++)
    {
        if (mem[i])
        {
            if ((!ins) && intervals[i].start > newInterval.start)
            {
                ins = true;
                result[(*returnSize)++] = newInterval;
            }
            result[(*returnSize)++] = intervals[i];
        }
    }
    if (!ins)
    {
        result[(*returnSize)++] = newInterval;
    }
    return result;
}