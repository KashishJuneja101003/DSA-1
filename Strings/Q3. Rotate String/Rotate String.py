class Solution(object):
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if not A or not B or len(A) != len(B):
            return False
        
        for i in range(len(A)):
            if self._helper(A, B, i):
                return True
        
        return False
    
    def _helper(self, A, B, rotation):
        for i in range(len(A)):
            if A[i] != B[(i + rotation) % len(B)]:
                return False
        return True
