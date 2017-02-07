bool solve(int val[][9], int x, int y, bool horilineput[][10], bool verlineput[][10], bool zoneput[][10])
{
    if (x >= 9) return true;
    if (val[x][y])
    {
        if (y == 8) return solve(val, x+1, 0, horilineput, verlineput, zoneput);
        else return solve(val, x, y+1, horilineput, verlineput, zoneput);
    }
    int i;
    int zone = (x>=3)+(x>=6);
    zone += (zone<<1)+(y>=3)+(y>=6);
    for (i = 1; i <= 9; i++)
    {
        if (!horilineput[x][i] && !verlineput[y][i] && !zoneput[zone][i])
        {
            val[x][y] = i;
            horilineput[x][i] = verlineput[y][i] = zoneput[zone][i] = true;
            if (y == 8)
            {
                if (solve(val, x+1, 0, horilineput, verlineput, zoneput)) return true;
            }
            else
            {
                if (solve(val, x, y+1, horilineput, verlineput, zoneput)) return true;
            }
            horilineput[x][i] = verlineput[y][i] = zoneput[zone][i] = false;
            val[x][y] = 0;
        }
    }
    return false;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    bool horilineput[9][10] = {false};
    bool verlineput[9][10] = {false};
    bool zoneput[9][10] = {false};
    int i, j;
    int val[9][9] = {0};
    for (i = 0; i < 9; i++)
    {
        int zoneid1 = (i>=3)+(i>=6);
        zoneid1 += (zoneid1<<1);
        for (j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                val[i][j] = board[i][j]-'0';
                horilineput[i][val[i][j]] = verlineput[j][val[i][j]] = zoneput[zoneid1+(j>=3)+(j>=6)][val[i][j]] = true;
            }
        }
    }
    solve(val, 0, 0, horilineput, verlineput, zoneput);
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            board[i][j] = val[i][j]+'0';
        }
    }
}