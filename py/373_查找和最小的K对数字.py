import heapq
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        # value_dict = {}
        # count = 0
        # for n1 in nums1:
        #     for n2 in nums2:
        #         s = n1 + n2
        #         value_dict[(n1, n2, count)] = s
        #         count += 1
        
        # sorted_pairs = sorted(value_dict.items(), key=lambda x: x[1])
        # pairs = []

        # for i in range(k):
        #     if i >= len(sorted_pairs):
        #         break
        #     pairs.append(sorted_pairs[i][0][0:2])

        # return pairs

        # heap = []
        # pair_out = []
        
        # k = k if k < len(nums1)*len(nums2) else len(nums1)*len(nums2)

        # for n1 in nums1:
        #     for n2 in nums2:
        #         if len(heap) < k:
        #             heapq.heappush(heap, [-(n1+n2), n1, n2])
        #         elif -heap[0][0] > n1 + n2:
        #             heapq.heappop(heap)
        #             heapq.heappush(heap, [-(n1+n2), n1, n2])
        
        # while heap:
        #     pair_out.append(heapq.heappop(heap)[1:])
        
        # return pair_out

        heap = []
        pair_out = []
        if nums1 and nums2:
            heap.append([nums1[0] + nums2[0], 0, 0])
        k = k if k < len(nums1)*len(nums2) else len(nums1)*len(nums2)

        while k > len(pair_out):
            _, m, n = heapq.heappop(heap)
            pair_out.append([nums1[m], nums2[n]])

            if n < len(nums2) - 1:
                heapq.heappush(heap, [nums1[m] + nums2[n + 1], m, n + 1])
            if n == 0 and m < len(nums1) - 1:
                heapq.heappush(heap, [nums1[m + 1] + nums2[0], m + 1, 0])
        
        return pair_out
        