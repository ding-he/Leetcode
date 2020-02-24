# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        stack1 = []
        stack2 = []

        direction = True
        print_out = [[]]

        if not root:
            return []
        
        stack1.append(root)

        while stack1 or stack2:
            if direction:
                node = stack1.pop()
                print_out[-1].append(node.val)

                if node.left:
                    stack2.append(node.left)
                if node.right:
                    stack2.append(node.right)
            else:
                node = stack2.pop()
                print_out[-1].append(node.val)

                if node.right:
                    stack1.append(node.right)
                if node.left:
                    stack1.append(node.left)
            
            if direction and not stack1:
                direction = False
                print_out.append([])
            elif not direction and not stack2:
                direction = True
                print_out.append([])

        print_out.pop()    
        
        return print_out
