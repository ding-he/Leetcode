# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        stack = []
        nodeset = set()

        if not root:
            return []

        stack.append(root)

        print_out = []

        while stack:
            node = stack[-1]

            if node.left and node not in nodeset:
                stack.append(node.left)
            else:
                stack.pop()
                print_out.append(node.val)

                if node.right:
                    stack.append(node.right)

            nodeset.add(node)
        
        return print_out
            