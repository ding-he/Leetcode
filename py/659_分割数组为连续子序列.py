class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        counter = {}
        tail = {}
        for x in nums:
            if x not in counter:
                counter[x] = 1
            else:
                counter[x] += 1
            if x not in tail:
                tail[x] = 0
        
        for x in nums:
            if counter[x] == 0:
                continue
            elif tail[x] > 0:
                tail[x] -= 1
                if x + 1 not in tail:
                    tail[x + 1] = 1
                else:
                    tail[x + 1] += 1
            elif x + 1 in counter and x + 2 in counter and counter[x + 1] > 0 and counter[x + 2] > 0:
                counter[x + 1] -= 1
                counter[x + 2] -= 1
                if x + 3 not in tail:
                    tail[x + 3] = 1
                else:
                    tail[x + 3] += 1
            else:
                return False
            counter[x] -= 1
        
        return True