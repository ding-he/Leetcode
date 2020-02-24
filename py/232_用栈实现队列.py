class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []
        

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        if len(self.stack) == 0:
            self.front = x
        self.stack.append(x)
        

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if len(self.stack) == 1:
            pop_ele = self.stack.pop()
        else:
            stack_helper = []
            sz = len(self.stack) - 1
            for _ in range(sz):
                stack_helper.append(self.stack.pop())
            pop_ele = self.stack.pop()
            self.front = stack_helper[-1]
            
            for _ in range(sz):
                self.stack.append(stack_helper.pop())
        return pop_ele


    def peek(self) -> int:
        """
        Get the front element.
        """
        return self.front
        

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return len(self.stack) == 0
        

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()