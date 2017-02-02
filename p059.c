/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    if (!n) return NULL;
    int **result = (int**)malloc(sizeof(int*)*n);
    int i;
    int right = n-1, left = 0, down = n-1, up = 1;
    int dir = 0;
    int x = 0, y = 0;
    for (i = 0; i < n; i++)
    {
        result[i] = (int*)malloc(sizeof(int)*n);
    }
    int size = n*n;
    for (i = 1; i <= size; i++)
    {
        result[x][y] = i;
        if (dir == 0)
        {
            if (y == right)
            {
                x++;
                dir = 1;
                right--;
            }
            else
            {
                y++;
            }
        }
        else if (dir == 1)
        {
            if (x == down)
            {
                y--;
                dir = 2;
                down--;
            }
            else
            {
                x++;
            }
        }
        else if (dir == 2)
        {
            if (y == left)
            {
                x--;
                dir = 3;
                left++;
            }
            else
            {
                y--;
            }
        }
        else
        {
            if (x == up)
            {
                y++;
                dir = 0;
                up++;
            }
            else
            {
                x--;
            }
        }
    }
    return result;
}