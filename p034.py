class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = 0
        r = len(nums)
        if r == 0: return [-1, -1]
        while r-l > 1:
            m = (r+l)//2
            if nums[m] < target: l = m
            else: r = m
        result = l
        if nums[result] < target:
            result += 1
            if result >= len(nums) or nums[result] != target: return [-1, -1]
        elif nums[result] > target: return [-1, -1]
        l = result
        r = len(nums)
        while r-l > 1:
            m = (r+l)//2
            if nums[m] > target: r = m
            else: l = m
        return [result, l]
            