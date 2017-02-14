struct Position {
    int x, y;
};

struct Position *oldarr, *newarr, *tmp;
int oldsize, newsize;

inline int min(int x, int y)
{
    if (x < y) return x;
    return y;
}

void f(char **board, int x, int y, int boardRowSize, int boardColSize) {
    board[x][y] = 'J';
    oldsize = 1;
    newsize = 0;
    oldarr[0].x = x;
    oldarr[0].y = y;
    while (oldsize > 0)
    {
        int i;
        newsize = 0;
        for (i = 0; i < oldsize; i++)
        {
            x = oldarr[i].x;
            y = oldarr[i].y;
            if (x > 0 && board[x-1][y] == 'O')
            {
                board[x-1][y] = 'J';
                newarr[newsize].x = x-1;
                newarr[newsize++].y = y;
            }
            if (x < boardRowSize-1 && board[x+1][y] == 'O')
            {
                board[x+1][y] = 'J';
                newarr[newsize].x = x+1;
                newarr[newsize++].y = y;
            }
            if (y > 0 && board[x][y-1] == 'O')
            {
                board[x][y-1] = 'J';
                newarr[newsize].x = x;
                newarr[newsize++].y = y-1;
            }
            if (y < boardColSize-1 && board[x][y+1] == 'O')
            {
                board[x][y+1] = 'J';
                newarr[newsize].x = x;
                newarr[newsize++].y = y+1;
            }
        }
        oldsize ^= newsize;
        newsize ^= oldsize;
        oldsize ^= newsize;
        tmp = oldarr;
        oldarr = newarr;
        newarr = tmp;
    }
}

void solve(char** board, int boardRowSize, int boardColSize) {
    if ((!boardRowSize) || (!boardColSize)) return;
    int i, j;
    oldarr = (struct Position*)malloc(sizeof(struct Position)*min(boardRowSize, boardColSize));
    newarr = (struct Position*)malloc(sizeof(struct Position)*min(boardRowSize, boardColSize));
    for (i = 0; i < boardColSize; i++)
    {
        if (board[0][i] == 'O') f(board, 0, i, boardRowSize, boardColSize);
        if (board[boardRowSize-1][i] == 'O') f(board, boardRowSize-1, i, boardRowSize, boardColSize);
    }
    for (i = 1; i < boardRowSize-1; i++)
    {
        if (board[i][0] == 'O') f(board, i, 0, boardRowSize, boardColSize);
        if (board[i][boardColSize-1] == 'O') f(board, i, boardColSize-1, boardRowSize, boardColSize);
    }
    for (i = 0; i < boardRowSize; i++)
        for (j = 0; j < boardColSize; j++)
            if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
            else if (board[i][j] == 'J')
            {
                board[i][j] = 'O';
            }
}
