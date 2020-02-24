# class Solution:
#     def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
#         result = []
#         for num in nums1:
#             i = nums2.index(num)
#             max_exist = False
#             for j in range(i, len(nums2)):
#                 if nums2[j] > nums2[i]:
#                     result.append(nums2[j])
#                     max_exist = True
#                     break
#             if not max_exist:
#                 result.append(-1)
#         return result

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = []
        num_map = {}
        for num in nums2:
            if len(stack) == 0:
                stack.append(num)
            else:
                while len(stack) != 0 and num > stack[-1]:
                    key = stack.pop()
                    num_map[key] = num
                else:
                    stack.append(num)
        for s in stack:
            num_map[s] = -1
        
        result = [num_map[key] for key in nums1]
        return result