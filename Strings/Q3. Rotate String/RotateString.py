class Solution(object):
    def rotateString(self, s, goal):
        """
        :type s: str
        :type goal: str
        :rtype: bool
        """
        for k in range(len(s)):
            if goal==s[k:] + s[:k]:
                return True

        return False

        
