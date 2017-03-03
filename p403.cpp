class Solution {
public:

    unordered_map<int, int> index;
    unordered_map<int, int>::iterator iter;
    bool **mem;
    int *arr;
    int size;

    bool f(int curindex, int previndex) {
        if (curindex == size-1)
        {
            return true;
        }
        if (!mem[curindex][previndex])
        {
            return false;
        }
        mem[curindex][previndex] = false;
        int step = arr[curindex]-arr[previndex];
        int i;
        for (i = 1; i >= -1; i--)
        {
            if (step+i == 0)
            {
                break;
            }
            iter = index.find(arr[curindex]+step+i);
            if (iter != index.end())
            {
                if (f(iter->second, curindex))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;
        index.clear();
        size = stones.size();
        arr = (int*)malloc(sizeof(int)*size);
        mem = (bool**)malloc(sizeof(bool*)*size);
        int i, j;
        for (i = 0; i < size; i++)
        {
            arr[i] = stones[i];
            index[arr[i]] = i;
            mem[i] = (bool*)malloc(sizeof(bool)*(i+1));
            for (j = 0; j <= i; j++)
                mem[i][j] = true;
        }
        return f(1, 0);
    }
};
