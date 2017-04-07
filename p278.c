// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    unsigned left = 1;
    unsigned right = n;
    while (right > left)
    {
        unsigned mid = (left + right) >> 1;
        if (isBadVersion(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}