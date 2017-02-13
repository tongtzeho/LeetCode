/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 * }
 */
int maxPoints(struct Point* points, int pointsSize) {
    if (pointsSize <= 1) return pointsSize;
    int i, j, k;
    int result = 0;
    int tmp = 0;
    long long x1, x2, y1, y2;
    bool *noteqlmem = (bool*)malloc(sizeof(bool)*pointsSize);
    bool *eqlmem = (bool*)malloc(sizeof(bool)*pointsSize);
    for (i = 0; i < pointsSize; i++)
    {
        eqlmem[i] = false;
    }
    for (i = 0; i < pointsSize; i++)
    {
        for (k = 0; k < pointsSize; k++)
        {
            noteqlmem[k] = false;
        }
        for (j = i+1; j < pointsSize; j++)
        {
            if (points[i].x != points[j].x || points[i].y != points[j].y)
            {
                if (noteqlmem[j]) continue;
                tmp = 0;
                x1 = points[i].x-points[j].x;
                y1 = points[i].y-points[j].y;
                for (k = 0; k < pointsSize; k++)
                {
                    x2 = points[k].x-points[i].x;
                    y2 = points[k].y-points[i].y;
                    if (x1*y2 == x2*y1)
                    {
                        noteqlmem[k] = true;
                        tmp++;
                    }
                }
                if (tmp > result)
                {
                    result = tmp;
                }
            }
            else
            {
                if (eqlmem[j]) continue;
                tmp = 0;
                for (k = 0; k < pointsSize; k++)
                {
                    if (points[i].x == points[k].x && points[i].y == points[k].y)
                    {
                        eqlmem[k] = true;
                        tmp++;
                    }
                }
                if (tmp > result)
                {
                    result = tmp;
                }
            }
        }
    }
    return result;
}
