# class Solution:
#     def removeDuplicates(self, S: str) -> str:
#         stack = []
#         for s in S:
#             if len(stack) == 0:
#                 stack.append(s)
#             else:
#                 if stack[-1] == s:
#                     stack.pop()
#                 else:
#                     stack.append(s)
        
#         res = ''
#         for s in stack:
#             res += s
#         return res
from string import ascii_lowercase
class Solution:
    def removeDuplicates(self, S: str) -> str:
        arr = [2*ch for ch in ascii_lowercase]
        prev_len = -1
        while prev_len != len(S):
            prev_len = len(S)
            for s in arr:
                S = S.replace(s, '')
        return S