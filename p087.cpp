class Solution {
public:

    unsigned char ***mem;
    unsigned int **cmplen;
    
    bool f(const int x, const int y, const int z)
    {
        if (cmplen[x][y] >= z) return 1;
        if (mem[x][y][z-1] != 2) return mem[x][y][z-1];
        int i;
        for (i = 1; i < z; i++)
        {
            if ((f(x, y, i) && f(x+i, y+i, z-i)) || (f(x, y+z-i, i) && f(x+i, y, z-i)))
            {
                mem[x][y][z-1] = 1;
                break;
            }
        }
        if (i == z) mem[x][y][z-1] = 0;
        return mem[x][y][z-1];
    }

    bool isScramble(string s1, string s2) {
        int len = s1.length();
        if (!len) return true;
        mem = (unsigned char***)malloc(sizeof(unsigned char**)*len);
        cmplen = (unsigned int**)malloc(sizeof(unsigned int*)*len);
        int i, j, k;
        for (i = 0; i < len; i++)
        {
            mem[i] = (unsigned char**)malloc(sizeof(unsigned char*)*len);
            cmplen[i] = (unsigned int*)malloc(sizeof(unsigned int)*len);
            for (j = 0; j < len; j++)
            {
                int tmplen = len-i;
                if (j > i)
                {
                    tmplen = len-j;
                }
                mem[i][j] = (unsigned char*)malloc(sizeof(unsigned char)*tmplen);
                for (k = 0; k < tmplen; k++)
                {
                    mem[i][j][k] = 2;
                }
                if (i > 0 && j > 0 && cmplen[i-1][j-1] > 0)
                {
                    cmplen[i][j] = cmplen[i-1][j-1]-1;
                }
                else
                {
                    for (cmplen[i][j] = 0; cmplen[i][j] < tmplen; cmplen[i][j]++)
                    {
                        if (s1[i+cmplen[i][j]] != s2[j+cmplen[i][j]])
                        {
                            break;
                        }
                    }   
                }
            }
        }
        return f(0, 0, len);
    }
};