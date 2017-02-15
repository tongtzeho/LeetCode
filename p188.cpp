class MyInterval {
public:
    int left, right;
    int prev, next;
}*myinterval;

int rmsetloss(int index)
{
    return myinterval[index].right-myinterval[index].left;
}

int mergesetloss(int index)
{
    return myinterval[index].right-myinterval[myinterval[index].next].left;
}

class OperationClass {
public:
    int index, loss;
    OperationClass(int x, int y)
    {
        index = x;
        loss = y;
    }
    bool operator < (const OperationClass& o) const     
    {  
        if (loss != o.loss) return loss < o.loss;
        return index < o.index;
    }
};

set<OperationClass> rmset, mergeset;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if (k == 0 || size <= 1) return 0;
        if (k > size>>1) k = size>>1;
        myinterval = new MyInterval[size>>1];
        rmset.clear();
        mergeset.clear();
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
                result += rmsetloss(i);
            }
            return result;
        }
        else
        {
            for (i = 0; i < myintervalsize-1; i++)
            {
                mergeset.insert(OperationClass(i, mergesetloss(i)));
                rmset.insert(OperationClass(i, rmsetloss(i)));
                result += rmsetloss(i);
            }
            rmset.insert(OperationClass(i, rmsetloss(myintervalsize-1)));
            result += rmsetloss(myintervalsize-1);
            while (myintervalsize > k)
            {
                if (rmset.begin()->loss <= mergeset.begin()->loss)
                {
                    result -= rmset.begin()->loss;
                    int index = rmset.begin()->index;
                    rmset.erase(rmset.begin());
                    if (myinterval[index].next != -1)
                    {
                        mergeset.erase(OperationClass(index, mergesetloss(index)));
                        myinterval[myinterval[index].next].prev = myinterval[index].prev;
                    }
                    if (myinterval[index].prev != -1)
                    {
                        mergeset.erase(OperationClass(myinterval[index].prev, mergesetloss(myinterval[index].prev)));
                        myinterval[myinterval[index].prev].next = myinterval[index].next;
                        if (myinterval[index].next != -1)
                        {
                            mergeset.insert(OperationClass(myinterval[index].prev, mergesetloss(myinterval[index].prev)));
                        }
                    }
                }
                else
                {
                    result -= mergeset.begin()->loss;
                    int index = mergeset.begin()->index;
                    mergeset.erase(mergeset.begin());
                    rmset.erase(OperationClass(index, rmsetloss(index)));
                    rmset.erase(OperationClass(myinterval[index].next, rmsetloss(myinterval[index].next)));
                    if (myinterval[myinterval[index].next].next != -1)
                    {
                        mergeset.erase(OperationClass(myinterval[index].next, mergesetloss(myinterval[index].next)));
                        myinterval[myinterval[myinterval[index].next].next].prev = index;
                        myinterval[index].right = myinterval[myinterval[index].next].right;
                        myinterval[index].next = myinterval[myinterval[index].next].next;
                        mergeset.insert(OperationClass(index, mergesetloss(index)));
                    }
                    else
                    {
                        myinterval[index].right = myinterval[myinterval[index].next].right;
                        myinterval[index].next = -1;
                    }
                    rmset.insert(OperationClass(index, rmsetloss(index)));
                }
                myintervalsize--;
            }
        }
        return result;
    }
};
