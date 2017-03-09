inline int min(int x, int y) {
    if (x < y) return x;
    return y;
}

inline int max(int x, int y) {
    if (x > y) return x;
    return y;
}

int getoverlap(int x1, int x2, int x3, int x4) {
    if (x3 < x2 && x1 < x4)
    {
        return min(x2, x4)-max(x1, x3);
    }
    else
    {
        return 0;
    }
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int overlapx = getoverlap(A, C, E, G);
    int overlapy = getoverlap(B, D, F, H);
    return (C-A)*(D-B)+(G-E)*(H-F)-overlapx*overlapy;
}
