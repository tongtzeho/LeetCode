/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
struct TreeNode **result;
int *min, *max, *indexofdepth, *left, *right, *val;
int resultsize;

void f(const int depth, const int index, const int n)
{
    int i;
    if (index == n)
    {
        struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode)*n);
        for (i = 0; i < n; i++)
        {
            node[i].val = val[i];
            if (left[i] == -1) node[i].left = NULL;
            else node[i].left = node+left[i];
            if (right[i] == -1) node[i].right = NULL;
            else node[i].right = node+right[i];
        }
        result[resultsize++] = node;
        return;
    }
    int gotonextdepth = (index == indexofdepth[depth]);
    if (depth > 0 && index == indexofdepth[depth-1]+1)
    {
        indexofdepth[depth+1] = indexofdepth[depth];
    }
    if (max[index] == min[index])
    {
        val[index] = min[index];
        left[index] = right[index] = -1;
        f(depth+gotonextdepth, index+1, n);
    }
    else
    {
        indexofdepth[depth+1]++;
        min[indexofdepth[depth+1]] = min[index];
        max[indexofdepth[depth+1]] = max[index]-1;
        left[index] = indexofdepth[depth+1];
        right[index] = -1;
        val[index] = max[index];
        f(depth+gotonextdepth, index+1, n);
        min[indexofdepth[depth+1]] = min[index]+1;
        max[indexofdepth[depth+1]] = max[index];
        left[index] = -1;
        right[index] = indexofdepth[depth+1];
        val[index] = min[index];
        f(depth+gotonextdepth, index+1, n);
        if (max[index]-min[index] >= 2)
        {
            indexofdepth[depth+1]++;
            for (i = min[index]+1; i <= max[index]-1; i++)
            {
                min[indexofdepth[depth+1]-1] = min[index];
                max[indexofdepth[depth+1]-1] = i-1;
                min[indexofdepth[depth+1]] = i+1;
                max[indexofdepth[depth+1]] = max[index];
                left[index] = indexofdepth[depth+1]-1;
                right[index] = indexofdepth[depth+1];
                val[index] = i;
                f(depth+gotonextdepth, index+1, n);
            }
            indexofdepth[depth+1]--;
        }
        indexofdepth[depth+1]--;
    }
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0)
    {
        (*returnSize) = 0;
        return NULL;
    }
    resultsize = 0;
    min = (int*)malloc(sizeof(int)*n);
    max = (int*)malloc(sizeof(int)*n);
    indexofdepth = (int*)malloc(sizeof(int)*n);
    left = (int*)malloc(sizeof(int)*n);
    right = (int*)malloc(sizeof(int)*n);
    val = (int*)malloc(sizeof(int)*n);
    result = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*2000);
    int i;
    for (i = 0; i < n; i++)
    {
        indexofdepth[i] = 0;
        left[i] = right[i] = -1;
    }
    min[0] = 1;
    max[0] = n;
    f(0, 0, n);
    *returnSize = resultsize;
    return result;
}