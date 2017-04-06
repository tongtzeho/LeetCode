int hIndex(int* citations, int citationsSize) {
    if (citationsSize == 0 || citations[citationsSize-1] == 0) return 0;
    if (citations[0] >= citationsSize) return citationsSize;
    int left = 0;
    int right = citationsSize-1;
    while (right > left)
    {
        int mid = (left + right) >> 1;
        if (citations[mid] >= citationsSize - mid)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return citationsSize - left;
}