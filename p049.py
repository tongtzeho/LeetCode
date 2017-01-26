class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        result_dict = {}
        for word in strs:
            cnt = [0]*26
            for c in word:
                cnt[ord(c)-97] += 1
            cnttp = tuple(cnt)
            if cnttp in result_dict:
                result_dict[cnttp].append(word)
            else:
                result_dict[cnttp] = [word]
        return result_dict.values()