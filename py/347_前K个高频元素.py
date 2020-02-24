import collections
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        
        for n in nums:
            if n not in d:
                d[n] = 1
            else:
                d[n] += 1
        
        out = sorted(d.items(), key=lambda x:x[1])[::-1]
        
        return [out[i][0] for i in range(k)]
