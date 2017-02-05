bool **mem;

bool f(const char **board, const int boardRowSize, const int boardColSize, const int i, const int j, const char *word)
{
    if (word[0] == '\0') return true;
    mem[i][j] = true;
    if (i > 0 && word[0] == board[i-1][j] && !mem[i-1][j])
    {
        if (f(board, boardRowSize, boardColSize, i-1, j, word+1)) return true;
    }
    if (j > 0 && word[0] == board[i][j-1] && !mem[i][j-1])
    {
        if (f(board, boardRowSize, boardColSize, i, j-1, word+1)) return true;
    }
    if (i < boardRowSize-1 && word[0] == board[i+1][j] && !mem[i+1][j])
    {
        if (f(board, boardRowSize, boardColSize, i+1, j, word+1)) return true;
    }
    if (j < boardColSize-1 && word[0] == board[i][j+1] && !mem[i][j+1])
    {
        if (f(board, boardRowSize, boardColSize, i, j+1, word+1)) return true;
    }
    mem[i][j] = false;
    return false;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    if ((!boardRowSize) || (!boardColSize)) return false;
    if ((!word) || word[0] == '\0') return true;
    mem = (bool**)malloc(sizeof(bool*)*boardRowSize);
    int i, j;
    for (i = 0; i < boardRowSize; i++)
    {
        mem[i] = (bool*)malloc(sizeof(bool)*boardColSize);
        for (j = 0; j < boardColSize; j++)
        {
            mem[i][j] = false;
        }
    }
    for (i = 0; i < boardRowSize; i++)
        for (j = 0; j < boardColSize; j++)
        {
            if (board[i][j] == word[0])
            {
                if (f(board, boardRowSize, boardColSize, i, j, word+1))
                {
                    return true;
                }
            }
        }
    return false;
}