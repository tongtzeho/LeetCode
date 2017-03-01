struct Pos {
    int x, y;
};

bool isSelfCrossing(int* x, int xSize) {
    if (xSize < 4) return false;
    struct Pos pos[4], cur, temp;
    int right, left, up, down;
    pos[0].x = pos[0].y = pos[1].x = 0;
    pos[1].y = pos[2].y = x[0];
    pos[2].x = pos[3].x = -x[1];
    pos[3].y = pos[1].y-x[2];
    cur = pos[3];
    int i = 3;
    bool inbound = false;
    if (cur.y >= pos[0].y)
    {
        down = cur.y;
        right = 0;
        left = cur.x;
        up = pos[1].y;
        inbound = true;
    }
    else if (cur.x+x[3] < 0)
    {
        down = cur.y;
        right = cur.x+x[3];
        left = cur.x;
        up = pos[1].y;
        inbound = true;
        cur.x += x[3];
        i = 4;
    }
    else if (cur.x+x[3] == 0)
    {
        down = cur.y;
        right = cur.x+x[3];
        left = cur.x;
        up = 0;
        inbound = true;
        cur.x += x[3];
        i = 4;
    }
    else
    {
        cur.x += x[3];
        i = 4;
    }
    if (!inbound)
    {
        while (i < xSize)
        {
            temp = cur;
            if ((i & 3) == 0) // up
            {
                cur.y += x[i++];
                if (cur.y < pos[0].y)
                {
                    inbound = true;
                    left = pos[3].x;
                    up = cur.y;
                    down = pos[3].y;
                    right = cur.x;
                    break;
                }
                else if (cur.y <= pos[1].y)
                {
                    inbound = true;
                    left = pos[1].x;
                    up = cur.y;
                    down = pos[3].y;
                    right = cur.x;
                    break;
                }
                else
                {
                    pos[0] = temp;
                }
            }
            else if ((i & 3) == 1) // left
            {
                cur.x -= x[i++];
                if (cur.x > pos[1].x)
                {
                    inbound = true;
                    left = cur.x;
                    up = cur.y;
                    down = pos[0].y;
                    right = pos[0].x;
                    break;
                }
                else if (cur.x >= pos[2].x)
                {
                    inbound = true;
                    left = cur.x;
                    up = cur.y;
                    down = pos[2].y;
                    right = pos[0].x;
                    break;
                }
                else
                {
                    pos[1] = temp;
                }
            }
            else if ((i & 3) == 2) // down
            {
                cur.y -= x[i++];
                if (cur.y > pos[2].y)
                {
                    inbound = true;
                    left = cur.x;
                    down = cur.y;
                    right = pos[1].x;
                    up = pos[1].y;
                    break;
                }
                else if (cur.y >= pos[3].y)
                {
                    inbound = true;
                    left = cur.x;
                    down = cur.y;
                    right = pos[3].x;
                    up = pos[1].y;
                    break;
                }
                else
                {
                    pos[2] = temp;
                }
            }
            else // right
            {
                cur.x += x[i++];
                if (cur.x < pos[3].x)
                {
                    inbound = true;
                    right = cur.x;
                    down = cur.y;
                    left = pos[2].x;
                    up = pos[2].y;
                    break;
                }
                else if (cur.x <= pos[0].x)
                {
                    inbound = true;
                    right = cur.x;
                    down = cur.y;
                    left = pos[2].x;
                    up = pos[0].y;
                    break;
                }
                else
                {
                    pos[3] = temp;
                }
            }
        }
    }
    if (inbound)
    {
        while (i < xSize)
        {
            if ((i & 3) == 0) // up
            {
                cur.y += x[i++];
                if (cur.y >= up) return true;
                else up = cur.y;
            }
            else if ((i & 3) == 1) // left
            {
                cur.x -= x[i++];
                if (cur.x <= left) return true;
                else left = cur.x;
            }
            else if ((i & 3) == 2) // down
            {
                cur.y -= x[i++];
                if (cur.y <= down) return true;
                else down = cur.y;
            }
            else
            {
                cur.x += x[i++];
                if (cur.x >= right) return true;
                else right = cur.x;
            }
        }
    }
    return false;
}
