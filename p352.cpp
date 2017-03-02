/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    
    map<int, int> tree;
    map<int, int>::iterator iter, prev, next;
    vector<Interval> result;
    Interval itv;
    bool modify;
    
    SummaryRanges() {
        tree.clear();
        result.clear();
        modify = true;
    }
    
    void addNum(int val) {
        iter = tree.find(val);
        if (iter != tree.end())
        {
            return;
        }
        tree.insert(pair<int, int>(val, val));
        iter = tree.find(val);
        prev = iter;
        prev--;
        if (iter == tree.begin() || prev->second < val-1)
        {
            next = tree.find(val+1);
            if (next != tree.end())
            {
                iter->second = next->second;
                tree.erase(next);
            }
            modify = true;
        }
        else if (prev->second >= val)
        {
            tree.erase(iter);
            return;
        }
        else
        {
            next = tree.find(val+1);
            if (next != tree.end())
            {
                prev->second = next->second;
                tree.erase(next);
                tree.erase(iter);
            }
            else
            {
                prev->second = val;
                tree.erase(iter);
            }
            modify = true;
        }
    }
    
    vector<Interval> getIntervals() {
        if (!modify) return result;
        modify = false;
        result.clear();
        for (iter = tree.begin(); iter != tree.end(); iter++)
        {
            itv.start = iter->first;
            itv.end = iter->second;
            result.push_back(itv);
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
