/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool cmp(const Interval &i1, const Interval &i2)
{
    if (i1.start != i2.start) return i1.start < i2.start;
    return i1.end < i2.end;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        unsigned len = intervals.size();
        if (!len) return result;
        Interval *a = new Interval[len];
        int k;
        for (k = 0; k < len; k++)
        {
            a[k] = intervals[k];
        }
        sort(a, a+len, cmp);
        int start, end, i = 0, j;
        while (i < len)
        {
            start = a[i].start;
            end = a[i].end;
            for (j = i+1; j < len; j++)
            {
                if (a[j].start <= end)
                {
                    if (a[j].end > end)
                    {
                        end = a[j].end;
                    }
                }
                else
                {
                    break;
                }
            }
            result.push_back(Interval(start, end));
            i = j;
        }
        return result;
    }
};