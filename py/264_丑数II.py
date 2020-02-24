import heapq
# class Solution:
#     def nthUglyNumber(self, n: int) -> int:
#         if n == 1:
#             return 1
        
#         ugly_num = [2, 3, 5]
#         base_num = [2, 3, 5]
#         new_ugly_num = [2, 3, 5]

#         while len(ugly_num) < 3*n:
#             temp_num = new_ugly_num
#             new_ugly_num = []

#             for num in temp_num:
#                 for bn in base_num:
#                     val = num * bn
#                     if val not in ugly_num:
#                         index = len(ugly_num) - 1
#                         while val < ugly_num[index]:
#                             index -= 1
#                         ugly_num.insert(index + 1, val)
#                         new_ugly_num.append(val)
        
#         return ugly_num[n - 2]

# class Solution:
#     def nthUglyNumber(self, n: int) -> int:
#         ugly_num = []
#         heap = [1]
#         base_num = [2, 3, 5]

#         while len(ugly_num) < n:
#             base = heapq.heappop(heap)
#             ugly_num.append(base)

#             for bn in base_num:
#                 val = base*bn
#                 if val not in heap and val not in ugly_num:
#                     heapq.heappush(heap, val)

#         return ugly_num[n - 1]

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly_num = [0] * n
        ugly_num[0] = 1
        # 2^i * 3^j * 5^k
        i = j = k = 0

        for index in range(1, n):
            val = min(ugly_num[i]*2, ugly_num[j]*3, ugly_num[k]*5)
            ugly_num[index] = val

            if val == ugly_num[i]*2:
                i += 1
            if val == ugly_num[j]*3:
                j += 1
            if val == ugly_num[k]*5:
                k += 1
        
        return ugly_num[-1]
