class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        result = ""
        vallist = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
        factor = (1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880)
        k -= 1
        for i in range(n):
            j = k%factor[n-i]//factor[n-i-1]
            result += vallist[j]
            del(vallist[j])
        return result