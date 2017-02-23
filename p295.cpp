class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int, vector<int>, greater<int> > big;
    priority_queue<int, vector<int>, less<int> > small;
    int size;
    
    MedianFinder() {
        while (!big.empty())
        {
            big.pop();
        }
        while (!small.empty())
        {
            small.pop();
        }
        size = 0;
    }
    
    void addNum(int num) {
        if (!size)
        {
            small.push(num);
            size = 1;
        }
        else if (size & 1)
        {
            int smalltop = small.top();
            if (smalltop <= num)
            {
                big.push(num);
            }
            else
            {
                small.pop();
                big.push(smalltop);
                small.push(num);
            }
            size++;
        }
        else
        {
            int bigtop = big.top();
            if (num <= bigtop)
            {
                small.push(num);
            }
            else
            {
                big.pop();
                small.push(bigtop);
                big.push(num);
            }
            size++;
        }
    }
    
    double findMedian() {
        if (size & 1)
        {
            return small.top();
        }
        else
        {
            return (small.top()+big.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */