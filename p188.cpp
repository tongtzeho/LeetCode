class MyInterval {
public:
    int left, right;
    int prev, next;
}*myinterval;

int rmloss(int index)
{
    return myinterval[index].right-myinterval[index].left;
}

int mrgloss(int index)
{
    return myinterval[index].right-myinterval[myinterval[index].next].left;
}

class Operation {
public:
    int index, loss;
    Operation(int x, int y)
    {
        index = x;
        loss = y;
    }
    bool operator < (const Operation& o) const     
    {  
        if (loss != o.loss) return loss < o.loss;
        return index < o.index;
    }
};

set<Operation> rm, mrg;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if (k == 0 || size <= 1) return 0;
        if (k > size>>1) k = size>>1;
        myinterval = new MyInterval[size>>1];
        rm.clear();
        mrg.clear();
        int myintervalsize = 0;
        int left = prices[0], right = left;
        int i, result = 0;
        for (i = 1; i < size; i++)
        {
            if (prices[i] > right) right = prices[i];
            else if (prices[i] < right)
            {
                if (right > left)
                {
                    myinterval[myintervalsize].left = left;
                    myinterval[myintervalsize].right = right;
                    myinterval[myintervalsize].prev = myintervalsize-1;
                    if (myintervalsize > 0)
                    {
                        myinterval[myintervalsize-1].next = myintervalsize;
                    }
                    myinterval[myintervalsize++].next = -1;
                }
                left = right = prices[i];
            }
        }
        if (right > left)
        {
            myinterval[myintervalsize].left = left;
            myinterval[myintervalsize].right = right;
            myinterval[myintervalsize].prev = myintervalsize-1;
            if (myintervalsize > 0)
            {
                myinterval[myintervalsize-1].next = myintervalsize;
            }
            myinterval[myintervalsize++].next = -1;
        }
        if (myintervalsize <= k)
        {
            for (i = 0; i < myintervalsize; i++)
            {
                result += rmloss(i);
            }
            return result;
        }
        else
        {
            for (i = 0; i < myintervalsize-1; i++)
            {
                mrg.insert(Operation(i, mrgloss(i)));
                rm.insert(Operation(i, rmloss(i)));
                result += rmloss(i);
            }
            rm.insert(Operation(i, rmloss(myintervalsize-1)));
            result += rmloss(myintervalsize-1);
            while (myintervalsize > k)
            {
                if (rm.begin()->loss <= mrg.begin()->loss)
                {
                    result -= rm.begin()->loss;
                    int index = rm.begin()->index;
                    rm.erase(rm.begin());
                    if (myinterval[index].next != -1)
                    {
                        mrg.erase(Operation(index, mrgloss(index)));
                        myinterval[myinterval[index].next].prev = myinterval[index].prev;
                    }
                    if (myinterval[index].prev != -1)
                    {
                        mrg.erase(Operation(myinterval[index].prev, mrgloss(myinterval[index].prev)));
                        myinterval[myinterval[index].prev].next = myinterval[index].next;
                        if (myinterval[index].next != -1)
                        {
                            mrg.insert(Operation(myinterval[index].prev, mrgloss(myinterval[index].prev)));
                        }
                    }
                }
                else
                {
                    result -= mrg.begin()->loss;
                    int index = mrg.begin()->index;
                    mrg.erase(mrg.begin());
                    rm.erase(Operation(index, rmloss(index)));
                    rm.erase(Operation(myinterval[index].next, rmloss(myinterval[index].next)));
                    if (myinterval[myinterval[index].next].next != -1)
                    {
                        mrg.erase(Operation(myinterval[index].next, mrgloss(myinterval[index].next)));
                        myinterval[myinterval[myinterval[index].next].next].prev = index;
                        myinterval[index].right = myinterval[myinterval[index].next].right;
                        myinterval[index].next = myinterval[myinterval[index].next].next;
                        mrg.insert(Operation(index, mrgloss(index)));
                    }
                    else
                    {
                        myinterval[index].right = myinterval[myinterval[index].next].right;
                        myinterval[index].next = -1;
                    }
                    rm.insert(Operation(index, rmloss(index)));
                }
                myintervalsize--;
            }
        }
        return result;
    }
};