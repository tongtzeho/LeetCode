inline int min(int x, int y)
{
    if (x < y) return x;
    return y;
}

inline int max(int x, int y)
{
    if (x > y) return x;
    return y;
}

int calculateMinimumHP(int** dungeon, int dungeonRowSize, int dungeonColSize) {
    int i, j;
    if (dungeon[dungeonRowSize-1][dungeonColSize-1] >= 0) dungeon[dungeonRowSize-1][dungeonColSize-1] = 1;
    else dungeon[dungeonRowSize-1][dungeonColSize-1] = 1-dungeon[dungeonRowSize-1][dungeonColSize-1];
    for (j = dungeonColSize-2; j >= 0; j--)
    {
        dungeon[dungeonRowSize-1][j] = max(1, dungeon[dungeonRowSize-1][j+1]-dungeon[dungeonRowSize-1][j]);
    }
    for (i = dungeonRowSize-2; i >= 0; i--)
    {
        dungeon[i][dungeonColSize-1] = max(1, dungeon[i+1][dungeonColSize-1]-dungeon[i][dungeonColSize-1]);
        for (j = dungeonColSize-2; j >= 0; j--)
        {
            dungeon[i][j] = max(1, min(dungeon[i+1][j], dungeon[i][j+1])-dungeon[i][j]);
        }
    }
    return dungeon[0][0];
}
