class Solution:
    def isUgly(self, num: int) -> bool:
        if num == 0:
            return False

        for n in [2, 3, 5]:
            while num % n == 0:
                num = num / n
        
        return num == 1