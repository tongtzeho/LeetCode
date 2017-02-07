int **mem;
int l1, l2;

int f(const char *s, const char *t, const int x, const int y)
{
    if (y == l2) return 1;
    if (x == l1) return 0;
    if (mem[x][y] != -1) return mem[x][y];
    int i = 0;
    while (x+i < l1 && s[x+i] != t[y])
    {
        i++;
    }
    if (x+i == l1) mem[x][y] = 0;
    else mem[x][y] = f(s, t, x+i+1, y)+f(s, t, x+i+1, y+1);
    return mem[x][y];
}

int numDistinct(char* s, char* t) {
    l1 = strlen(s);
    l2 = strlen(t);
    mem = (int**)malloc(sizeof(int*)*(l1+1));
    int i, j;
    for (i = 0; i <= l1; i++)
    {
        mem[i] = (int*)malloc(sizeof(int)*(l2+1));
        for (j = 0; j <= l2; j++)
        {
            mem[i][j] = -1;
        }
    }
    return f(s, t, 0, 0);
}