/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct EdgeInfo
{
    unsigned short target;
    unsigned short memIndex;
}edgeInfo[40006];

unsigned short edgeBegin[20003] = { 0 };
unsigned short minimum = 65535;

unsigned short f(unsigned short n, unsigned short from, unsigned short* mem)
{
    unsigned short res = 0;
    unsigned short begin = edgeBegin[n];
    unsigned short end = edgeBegin[n + 1];
    for (unsigned short i = begin; i < end; ++i)
    {
        unsigned short target = edgeInfo[i].target;
        if (target != from)
        {
            unsigned short index = edgeInfo[i].memIndex;
            if (mem[index] == 0)
            {
                mem[index] = 1 + f(target, n, mem);
            }
            if (mem[index] > res)
            {
                res = mem[index];
                if (res > minimum)
                {
                    return res;
                }
            }
        }
    }
    return res;
}

int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    unsigned short edgeCount[20003] = { 0 };
    unsigned short mem[40006] = { 0 };
    for (int i = 0; i < n - 1; ++i)
    {
        ++edgeCount[edges[i][0]];
        ++edgeCount[edges[i][1]];
    }
    for (int i = 1; i < n; ++i)
    {
        edgeBegin[i] = edgeBegin[i - 1] + edgeCount[i - 1];
        edgeCount[i - 1] = 0;
    }
    edgeBegin[n] = edgeBegin[n - 1] + edgeCount[n - 1];
    edgeCount[n - 1] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        unsigned short a = (unsigned short)edges[i][0];
        unsigned short b = (unsigned short)edges[i][1];
        unsigned short edgeA = edgeBegin[a] + (edgeCount[a]++);
        unsigned short edgeB = edgeBegin[b] + (edgeCount[b]++);
        edgeInfo[edgeA].target = b;
        edgeInfo[edgeA].memIndex = i * 2;
        edgeInfo[edgeB].target = a;
        edgeInfo[edgeB].memIndex = i * 2 + 1;
    }
    minimum = 65535;
    int* ret = (int*)malloc(20003 * sizeof(int));
    int size = 0;
    unsigned short nu16 = (unsigned short)n;
    for (unsigned short i = 0; i < nu16; ++i)
    {
        unsigned short ans = f(i, 65535, mem);
        if (ans < minimum)
        {
            minimum = ans;
            size = 0;
        }
        if (ans == minimum)
        {
            ret[size++] = i;
        }
    }
    *returnSize = size;
    return ret;
}