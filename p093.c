/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int len;
char **result;

void f(const int x, const int y, const char *s, int *returnSize)
{
    if (x == 4)
    {
        (*returnSize)++;
        int i;
        for (i = 0; i < len+3; i++)
            result[*returnSize][i] = result[(*returnSize)-1][i];
        return;
    }
    int val = 0;
    int i;
    for (i = y; i <= y+2 && i < len; i++)
    {
        val = (val<<3)+(val<<1)+s[i]-'0';
        if (val > 255) break;
        result[*returnSize][x+i] = s[i];
        if (len-i <= 10-x-x-x && len-i >= 4-x)
        {
            if (x < 3) result[*returnSize][x+i+1] = '.';
            f(x+1, i+1, s, returnSize);
        }
        if (s[y] == '0') break;
    }
} 
 
char** restoreIpAddresses(char* s, int* returnSize) {
    len = strlen(s);
    result = (char**)malloc(sizeof(char*)*81);
    int i, j;
    for (i = 0; i < 81; i++)
    {
        result[i] = (char*)malloc(sizeof(char)*(len+4));
        result[i][len+3] = '\0';
    }
    (*returnSize) = 0;
    f(0, 0, s, returnSize);
    return result;
}