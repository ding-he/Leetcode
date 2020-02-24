# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from queue import Queue
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.queue = Queue()
        self._inorder(root)

    def _inorder(self, root):
        if not root:
            return
        self._inorder(root.left)
        self.queue.put(root.val)
        self._inorder(root.right)

    def next(self) -> int:
        """
        @return the next smallest number
        """
        return self.queue.get()
        

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return not self.queue.empty()


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()