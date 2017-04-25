void gameOfLife(int** board, int boardRowSize, int boardColSize) {
    const int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int i, j, k;
    for (i = 0; i < boardRowSize; i++)
        for (j = 0; j < boardColSize; j++)
        {
            int livenum = 0;
            for (k = 0; k < 8; k++)
            {
                if (i+dir[k][0] >= 0 && i+dir[k][0] < boardRowSize && j+dir[k][1] >= 0 && j+dir[k][1] < boardColSize && (board[i+dir[k][0]][j+dir[k][1]] & 1) == 1)
                {
                    livenum++;
                }
            }
            if ((board[i][j] & 1) == 1)
            {
                if (livenum == 2 || livenum == 3)
                {
                    board[i][j] += 2;
                }
            }
            else
            {
                if (livenum == 3)
                {
                    board[i][j] += 2;
                }
            }
        }
    for (i = 0; i < boardRowSize; i++)
        for (j = 0; j < boardColSize; j++)
            board[i][j] >>= 1;
}
