bool **mem;
int l1;
int l2;
int l3;

bool f(const char *s1, const char *s2, const char *s3, const int x, const int y)
{
    if (x == l1 && y == l2) return true;
    if (mem[x][y]) return false;
    mem[x][y] = true;
    if (x < l1 && s1[x] == s3[x+y] && f(s1, s2, s3, x+1, y)) return true;
    if (y < l2 && s2[y] == s3[x+y] && f(s1, s2, s3, x, y+1)) return true;
    return false;
}

bool isInterleave(char* s1, char* s2, char* s3) {
    l1 = strlen(s1);
    l2 = strlen(s2);
    l3 = strlen(s3);
    if (l1+l2 != l3) return false;
    mem = (bool**)malloc(sizeof(bool*)*(l1+1));
    int i, j;
    for (i = 0; i <= l1; i++)
    {
        mem[i] = (bool*)malloc(sizeof(bool)*(l2+1));
        for (j = 0; j <= l2; j++)
        {
            mem[i][j] = false;
        }
    }
    return f(s1, s2, s3, 0, 0);
}