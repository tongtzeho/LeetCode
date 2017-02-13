int trap(int* height, const int heightSize) {
    if (heightSize <= 2) return 0;
    int leftmax[heightSize];
    int i;
    leftmax[0] = 0;
    for (i = 1; i < heightSize-1; i++)
    {
        if (height[i-1] < leftmax[i-1])
        {
            leftmax[i] = leftmax[i-1];
        }
        else
        {
            leftmax[i] = height[i-1];
        }
    }
    int rightmax = 0;
    int result = 0;
    for (i = heightSize-2; i > 0; i--)
    {
        if (height[i+1] > rightmax)
        {
            rightmax = height[i+1];
        }
        int min = leftmax[i];
        if (rightmax < min)
        {
            min = rightmax;
        }
        min -= height[i];
        if (min > 0)
        {
            result += min;
        }
    }
    return result;
}
