import collections
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:

        n = len(words)

        check = collections.defaultdict(lambda: 0)

        for x in words:
            check[x] += 1

        h = []
        for key, value in check.items():
            h.append([-value, key])
        
        heapq.heapify(h)

        res = []
        for i in range(k):
            t = heapq.heappop(h)
            res.append(t[1])

        return res

        # word_count = {}
        # for word in words:
        #     word_count[word] = word_count.get(word, 0) + 1
        
        # heap = []
        # for key, value in word_count.items():
        #     heapq.heappush(heap, [-value, key])
        
        # sorted_word = []
        # while k and heap:
        #     k -= 1
        #     sorted_word.append(heapq.heappop(heap)[1])
        
        # return sorted_word