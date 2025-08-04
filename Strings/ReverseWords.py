class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        arr = s.strip().split()
        arr.reverse()
        return " ".join(arr)
