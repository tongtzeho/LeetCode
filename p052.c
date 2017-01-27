int *place;
bool *y_0;
bool *yx;
bool *y_x;
int result;

void f(const int n, const int p)
{
    int i;
    if (n == p)
    {
        result++;
        if (place[0] < n>>1)
        {
            result++;
        }
        return;
    }
    for (i = 0; i < n; i++)
    {
        if ((!y_0[i]) && (!yx[i+p]) && (!y_x[i-p+(n-1)]))
        {
            place[p] = i;
            y_0[i] = true;
            yx[i+p] = true;
            y_x[i-p+(n-1)] = true;
            f(n, p+1);
            y_x[i-p+(n-1)] = false;
            yx[i+p] = false;
            y_0[i] = false;
        }
    }
}

int totalNQueens(int n) {
    if (n == 0) return 0;
    place = (int*)malloc(sizeof(int)*n);
    y_0 = (bool*)malloc(sizeof(bool)*n);
    yx = (bool*)malloc(sizeof(bool)*((n<<1)+1));
    y_x = (bool*)malloc(sizeof(bool)*((n<<1)+1));
    int i;
    result = 0;
    for (i = 0; i < n; i++)
    {
        y_0[i] = false;
    }
    for (i = 0; i < (n<<1)+1; i++)
    {
        yx[i] = y_x[i] = false;
    }
    for (i = 0; i < (n+1)>>1; i++)
    {
        place[0] = i;
        y_0[i] = true;
        yx[i] = true;
        y_x[i+n-1] = true;
        f(n, 1);
        y_x[i+n-1] = false;
        yx[i] = false;
        y_0[i] = false;
    }
    return result;
}