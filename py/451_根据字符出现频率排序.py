class Solution:
    def frequencySort(self, s: str) -> str:
        
        str_dict = {}
        for ch in s:
            if ch not in str_dict:
                str_dict[ch] = 1
            else:
                str_dict[ch] += 1
        
        heap = []
        for k, v in str_dict.items():
            heapq.heappush(heap, [-v, k])
        
        res = ''
        while heap:
            out = heapq.heappop(heap)
            res += out[1] * (-out[0])
        
        return res