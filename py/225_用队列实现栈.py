from queue import Queue
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = Queue()


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue.put(x)
        self.top_data = x


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        sz = self.queue.qsize() - 1
        while sz:
            ele = self.queue.get()
            self.queue.put(ele)
            sz -= 1
            if sz == 0:
                self.top_data = ele
        return self.queue.get()

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.top_data
        

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.queue.empty()
        

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()