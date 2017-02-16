/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
struct Node {
    struct Node **child;
    int isend;
};

void initNode(struct Node *node)
{
    node->isend = -1;
    node->child = (struct Node**)malloc(sizeof(struct Node*)*26);
    int i;
    for (i = 0; i < 26; i++)
    {
        (node->child)[i] = NULL;
    }
}

bool **mem;
char **result;
char **wordsglobal;
bool *selected;

void f(const char **board, const int RowSize, const int ColSize, const int x, const int y, struct Node *node) {
    if (node->isend != -1)
    {
        selected[node->isend] = true;
    }
    mem[x][y] = true;
    if (x > 0 && (!mem[x-1][y]) && (node->child)[board[x-1][y]] != NULL) f(board, RowSize, ColSize, x-1, y, (node->child)[board[x-1][y]]);
    if (x < RowSize-1 && (!mem[x+1][y]) && (node->child)[board[x+1][y]] != NULL) f(board, RowSize, ColSize, x+1, y, (node->child)[board[x+1][y]]);
    if (y > 0 && (!mem[x][y-1]) && (node->child)[board[x][y-1]] != NULL) f(board, RowSize, ColSize, x, y-1, (node->child)[board[x][y-1]]);
    if (y < ColSize-1 && (!mem[x][y+1]) && (node->child)[board[x][y+1]] != NULL) f(board, RowSize, ColSize, x, y+1, (node->child)[board[x][y+1]]);
    mem[x][y] = false;
}

char** findWords(char** board, int boardRowSize, int boardColSize, char** words, int wordsSize, int* returnSize) {
    result = NULL;
    *returnSize = 0;
    if (wordsSize == 0 || boardRowSize == 0 || boardColSize == 0)
    {
        return result;
    }
    result = (char**)malloc(sizeof(char*)*wordsSize);
    selected = (bool*)malloc(sizeof(bool)*wordsSize);
    wordsglobal = words;
    mem = (bool**)malloc(sizeof(bool*)*boardRowSize);
    int i, j, k;
    for (i = 0; i < boardRowSize; i++)
    {
        mem[i] = (bool*)malloc(sizeof(bool)*boardColSize);
        for (j = 0; j < boardColSize; j++)
        {
            mem[i][j] = false;
            board[i][j] -= 'a';
        }
    }
    struct Node root;
    struct Node *node;
    initNode(&root);
    for (i = 0; i < wordsSize; i++)
    {
        node = &root;
        for (j = 0; words[i][j] != '\0'; j++)
        {
            k = words[i][j]-'a';
            if ((node->child)[k] == NULL)
            {
                (node->child)[k] = (struct Node*)malloc(sizeof(struct Node));
                initNode((node->child)[k]);
                node = (node->child)[k];
            }
            else
            {
                node = (node->child)[k];
            }
        }
        node->isend = i;
        selected[i] = false;
    }
    for (i = 0; i < boardRowSize; i++)
    {
        for (j = 0; j < boardColSize; j++)
        {
            if (root.child[board[i][j]] != NULL) f(board, boardRowSize, boardColSize, i, j, root.child[board[i][j]]);
        }
    }
    for (i = 0; i < wordsSize; i++)
    {
        if (selected[i])
        {
            result[(*returnSize)++] = words[i];
        }
    }
    return result;
}
