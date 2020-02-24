class Node:
    def __init__(self, s):
        self.val = s
        self.count = 0

class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        stack = []

        preorder_array = preorder.split(',')

        for i, p in enumerate(preorder_array):
            if stack:
                stack[-1].count += 1
            if p == '#':
                if not stack:
                    return len(preorder_array) == 1
                node = None
            else:
                node = Node(p)
            
            if stack and stack[-1].count >= 2:
                stack.pop()
            
            if node:
                stack.append(node)
            
            if not stack:
                break
        
        return len(stack) == 0 and i == len(preorder_array) - 1