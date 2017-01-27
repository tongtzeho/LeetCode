bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    if (boardRowSize != 9 || boardColSize != 9) return false;
    bool hori[9][9] = {false};
    bool ver[9][9] = {false};
    bool zone[9][9] = {false};
    int i, j, zbase = 0;
    for (i = 0; i < 9; i++)
    {
        if (i == 3 || i == 6) zbase += 3;
        int z = zbase;
        for (j = 0; j < 9; j++)
        {
            if (j == 3 || j == 6) z++;
            if (board[i][j] != '.')
            {
                int x = board[i][j]-'1';
                if (hori[i][x]) return false;
                hori[i][x] = true;
                if (ver[j][x]) return false;
                ver[j][x] = true;
                if (zone[z][x]) return false;
                zone[z][x] = true;
            }
        }
    }
    return true;
}