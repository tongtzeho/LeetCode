int **mem;

inline int min(const int x, const int y)
{
    if (x < y) return x;
    return y;
}

int f(const char *word1, const char *word2, const int l1, const int l2, const int x, const int y)
{
    if (l1 == x && l2 == y) return 0;
    if (mem[x][y] != -1) return mem[x][y];
    if (x < l1 && y < l2 && word1[x] == word2[y])
    {
        int i = 1;
        while (x+i < l1 && y+i < l2 && word1[x+i] == word2[y+i])
        {
            i++;
        }
        mem[x][y] = f(word1, word2, l1, l2, x+i, y+i);
    }
    else
    {
        if (x < l1 && y < l2) mem[x][y] = 1+min(f(word1, word2, l1, l2, x+1, y+1), min(f(word1, word2, l1, l2, x+1, y), f(word1, word2, l1, l2, x, y+1)));
        else if (x < l1) mem[x][y] = 1+f(word1, word2, l1, l2, x+1, y);
        else mem[x][y] = 1+f(word1, word2, l1, l2, x, y+1);
    }
    return mem[x][y];
}

int minDistance(char* word1, char* word2) {
    int l1 = strlen(word1), l2 = strlen(word2), i, j;
    mem = (int**)malloc(sizeof(int*)*(l1+1));
    for (i = 0; i <= l1; i++)
    {
        mem[i] = (int*)malloc(sizeof(int)*(l2+1));
        for (j = 0; j <= l2; j++)
            mem[i][j] = -1;
    }
    return f(word1, word2, l1, l2, 0, 0);
}