double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size == 0) return (nums2[nums2Size>>1]+nums2[(nums2Size-1)>>1])/2.0;
    if (nums2Size == 0) return (nums1[nums1Size>>1]+nums1[(nums1Size-1)>>1])/2.0;
    int l1 = 0, r1 = nums1Size-1;
    int l2 = 0, r2 = nums2Size-1;
    int k = (nums1Size+nums2Size-1)>>1;
    while (r1 >= l1 && r2 >= l2)
    {;
        int m11 = (l1+r1)>>1;
        int m12 = (l1+r1+1)>>1;
        int m21 = (l2+r2)>>1;
        int m22 = (l2+r2+1)>>1;
        if (k < ((r1+r2-l1-l2+3)>>1))
        {
            if (nums1[m12] <= nums2[m22]) r2 = m22-1;
            else r1 = m12-1;
        }
        else
        {
            if (nums1[m11] <= nums2[m21])
            {
                k -= (m11-l1+1);
                l1 = m11+1;
            }
            else
            {
                k -= (m21-l2+1);
                l2 = m21+1;
            }
        }
    }
    int mid1;
    if (r1 >= l1) mid1 = nums1[l1+k];
    else mid1 = nums2[l2+k];
    if (!((nums1Size+nums2Size)&1))
    {
        int mid2;
        if (r1 >= l1)
        {
            int x = ((nums1Size+nums2Size)>>1)-2-l1-k;
            if (x+1 < nums2Size)
            {
                mid2 = nums2[x+1];
                if (l1+k+1 < nums1Size && nums1[l1+k+1] < mid2) mid2 = nums1[l1+k+1];
            }
            else mid2 = nums1[l1+k+1];
        }
        else
        {
            int x = ((nums1Size+nums2Size)>>1)-2-l2-k;
            if (x+1 < nums1Size)
            {
                mid2 = nums1[x+1];
                if (l2+k+1 < nums2Size && nums2[l2+k+1] < mid2) mid2 = nums2[l2+k+1];
            }
            else mid2 = nums2[l2+k+1];
        }
        return (mid1+mid2)/2.0;
    }
    else return mid1;
}